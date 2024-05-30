import java.util.*;

public class Pasukan {
    private List<Integer> list;
    private int n;

    public Pasukan(List<Integer> l, int amount) {
        list = l;
        n = amount;
    }

    public void reset() {
        list.clear();

        for (int i = 0; i < n; i++){
            list.add(0);
        }
    }

    public long get(int idx){
        reset();
        long start = Util.getTime();
        list.get(idx);
        long end = Util.getTime();
        return (end - start);
    }

    public long del(int idx, int t){
        reset();
        long start = Util.getTime();

        for (int i = 0; i < t; i++){
            list.remove(idx);
        }

        long end = Util.getTime();
        return (end - start);
    }
}