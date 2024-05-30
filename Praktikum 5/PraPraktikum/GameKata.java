import java.util.*;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
      Map<String, Integer> map = new HashMap<>();
      for (String word : tito) {
        if (!map.containsKey(word)){
          map.put(word, 0);
        }
      }
      for (String word : wiwid) {
        if (map.containsKey(word)){
          map.put(word, 1);
        }
      }
      for (Map.Entry<String, Integer> entry : map.entrySet()) {
        if (entry.getValue() == 1){
          System.out.println(entry.getKey());
        }
      }
    }
  }