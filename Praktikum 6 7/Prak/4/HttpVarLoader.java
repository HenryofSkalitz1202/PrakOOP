import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;

public class HttpVarLoader {

  private final HashMap<String, String> headers;
  private final HashMap<String, String> body;
  private final HashMap<String, String> query;
  private final HashMap<String, String> cookie;

  /**
   * Variabel HTTP direpresentasikan dengan HashMap key-value.
   * Asumsikan:
   * - Tidak mungkin ada key berupa null
   * - Value mungkin null
   * 
   * @param headers
   * @param body
   * @param query
   * @param cookie
   */
  public HttpVarLoader(HashMap<String, String> headers, HashMap<String, String> body, HashMap<String, String> query, HashMap<String, String> cookie) {
    this.headers = new HashMap<>(headers);
    this.body = new HashMap<>(body);
    this.query = new HashMap<>(query);
    this.cookie = new HashMap<>(cookie);
  }

  /**
   * Melakukan load variabel HTTP terhadap objek pada atribut dan method yang
   * menggunakan annotation HttpVar
   * 
   * @param obj Objek
   * @throws NullPointerException      Jika parameter obj bernilai null, atau jika
   *                                   nama variabel yang diminta tidak ada pada
   *                                   daftar variabel HTTP. Throw exception ini
   *                                   tanpa string message apapun.
   * @throws InvocationTargetException Jika method yang dipanggil meng-throw
   *                                   exception. Perhatikan bahwa Method.invoke()
   *                                   meng-throw exception ini.
   */
  public void load(Object obj) throws NullPointerException, InvocationTargetException {
    if (obj == null) {
      throw new NullPointerException();
    }

    Class<?> clazz = obj.getClass();

    // Handle fields
    for (Field field : clazz.getDeclaredFields()) {
      if (field.isAnnotationPresent(HttpVar.class)) {
        HttpVar httpVar = field.getAnnotation(HttpVar.class);
        String value = getHttpVarValue(httpVar);

        if (value == null) {
          throw new NullPointerException();
        }

        try {
          field.setAccessible(true);
          field.set(obj, value);
        } catch (IllegalAccessException e) {
          throw new InvocationTargetException(e);
        }
      }
    }

    // Handle methods
    for (Method method : clazz.getDeclaredMethods()) {
      if (method.isAnnotationPresent(HttpVar.class)) {
        HttpVar httpVar = method.getAnnotation(HttpVar.class);
        String value = getHttpVarValue(httpVar);

        if (value == null) {
          throw new NullPointerException();
        }

        try {
          method.setAccessible(true);
          method.invoke(obj, value);
        } catch (IllegalAccessException e) {
          throw new InvocationTargetException(e);
        }
      }
    }
  }

  private String getHttpVarValue(HttpVar httpVar) {
    HashMap<String, String> sourceMap;
    switch (httpVar.type()) {
      case Header:
        sourceMap = headers;
        break;
      case Cookie:
        sourceMap = cookie;
        break;
      case Body:
        sourceMap = body;
        break;
      case Query:
        sourceMap = query;
        break;
      default:
        return null;
    }

    return sourceMap.get(httpVar.name());
  }
}

