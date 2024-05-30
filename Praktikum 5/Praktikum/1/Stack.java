import java.util.ArrayList;
import java.util.List;

//Class Stack berikut merupakan suatu kelas GENERIC
//Stack disimpan dengan memanfaatkan ArrayList
//Element terakhir stack disimpan pada index paling kanan pada ArrayList
public class Stack<T> {

  private List<T> data;

  private int lastElmIdx, size;

  private final static int DEFAULT_STACK_SIZE = 500;


  //Constructor dengan size default
  public Stack(){
    this.lastElmIdx = -1;
    this.size = DEFAULT_STACK_SIZE;
    this.data = new ArrayList<T> ();
  }
  
  //Constructore dengan size = n
  public Stack(int n){
    this.lastElmIdx = -1;
    this.size = n;
    this.data = new ArrayList<T> ();
  }

  //Copy constructor dari stack lain
  public Stack(final Stack<T> q){
    this.lastElmIdx = q.lastElmIdx;
    this.size = q.size;
    this.data = new ArrayList<T> ();
    for (int i = 0; i <= q.lastElmIdx; i++){
        this.data.add(q.data.get(i));
    }
  }

  //Tambahkan elemen t ke dalam stack
  //Jika stack penuh, lempar exception "Stack is full"
  public void push(T t) throws Exception{
    if(this.isFull()){
        throw new Exception("Stack is full");
    }

    this.data.add(t);
    this.lastElmIdx++;
  }

  //Hapus elemen terakhir dari stack
  //Jika stack kosong, lempar exception "Stack is empty"
  public T pop() throws Exception{
    if(this.isEmpty()){
        throw new Exception("Stack is empty");
    }

    T res = this.data.get(this.lastElmIdx);
    this.data.remove(this.lastElmIdx);
    this.lastElmIdx--;
    return res;
  }

  //Cek apakah stack kosong
  public boolean isEmpty(){
    return this.lastElmIdx == -1;
  }

  //Cek apakah stack penuh
  public boolean isFull(){
    return this.lastElmIdx == this.size - 1;
  }
}