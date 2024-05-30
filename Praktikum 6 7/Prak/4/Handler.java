import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;

public class Handler {
    @HttpVar(type = HttpVar.Type.Query, name = "q")
    private String q;
  
    private String token;
  
    // other attributes...
  
    @HttpVar(type = HttpVar.Type.Header, name = "Authorization")
    public void initToken(String auth) {
      this.token = auth;
    }
  
    public static void main(String[] args) {
      HashMap<String, String> headers = new HashMap<>();
      headers.put("Authorization", "Bearer some_token");
  
      HashMap<String, String> query = new HashMap<>();
      query.put("q", "search_query");
  
      HashMap<String, String> body = new HashMap<>();
      HashMap<String, String> cookie = new HashMap<>();
  
      HttpVarLoader loader = new HttpVarLoader(headers, body, query, cookie);
  
      Handler handler = new Handler();
  
      try {
        loader.load(handler);
  
        // handler.q should be set to "search_query"
        // handler.initToken should be called with "Bearer some_token"
        System.out.println("Query: " + handler.q); // Should print "search_query"
        System.out.println("Token: " + handler.token); // Should print "Bearer some_token"
      } catch (NullPointerException | InvocationTargetException e) {
        e.printStackTrace();
      }
  
      // Test missing variable
      query.remove("q");
      try {
        loader.load(handler);
      } catch (NullPointerException e) {
        System.out.println("Caught expected NullPointerException for missing query variable");
      } catch (InvocationTargetException e) {
        e.printStackTrace();
      }
  
      // Test null object
      try {
        loader.load(null);
      } catch (NullPointerException e) {
        System.out.println("Caught expected NullPointerException for null object");
      } catch (InvocationTargetException e) {
        e.printStackTrace();
      }
    }
}
  