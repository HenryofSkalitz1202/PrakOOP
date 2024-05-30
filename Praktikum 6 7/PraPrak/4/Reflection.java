import java.util.ArrayList;
import java.lang.reflect.Method;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.util.List;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods(){
        ArrayList<String> result = new ArrayList<String>();

        try{
            Class<?> ghost = Class.forName("Ghost");
            Method[] methods = ghost.getDeclaredMethods();

            for(Method method : methods){
                method.setAccessible(true);
                result.add(method.getName());
            }
        }catch(Exception e){
        }

        return result;
    }   

    public Integer sumGhost() throws Exception{
        ArrayList<String> methods = this.ghostMethods();
        int sum = 0;

        Class<?> ghost = Class.forName("Ghost");
        Constructor<?>[] constructors = ghost.getDeclaredConstructors();
        Object ghostObj = constructors[0].newInstance();

        for(String methodName : methods){
            Method method = ghost.getDeclaredMethod(methodName);
            method.setAccessible(true);
            if (method.getReturnType() == Integer.class) {
                sum += (Integer) method.invoke(ghostObj);
            }
        }
        return sum;
    }

    public String letterGhost() throws Exception{
        ArrayList<String> methods = this.ghostMethods();
        String resultString = "";

        Class<?> ghost = Class.forName("Ghost");
        Constructor<?>[] constructors = ghost.getDeclaredConstructors();
        Object ghostObj = constructors[0].newInstance();

        for(String methodName : methods){
            Method method = ghost.getDeclaredMethod(methodName);
            method.setAccessible(true);
            if(method.getReturnType() == String.class){
                resultString += (String) method.invoke(ghostObj);
            }
        }

        return resultString;
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception{
        boolean found = false;
        String secretID = "NaN";
        for(int i = 0; i < sl.size() && !found; i++){
            Secret s = sl.get(i);
            if(s.isThis(email)){
                found = true;
                Field field = s.getClass().getDeclaredField("uniqueId");
                field.setAccessible(true);
                secretID = (String) field.get(s);
            }
        }
        return secretID;
    }
}