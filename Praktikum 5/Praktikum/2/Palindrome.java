public class Palindrome<T> {
    //Method untuk mengecek apakah Deque dq merupakan palindrome
    //Deque dq merupakan palindrome jika elemen-elemen pada Deque dq dapat dibaca sama dari depan dan belakang
    public boolean isPalindrome(Deque<T> dq){
        Deque<T> copyDeque = new Deque<>(dq);

        try{
            while(!dq.isEmpty()){
                T front = copyDeque.popFront();

                //handle middle elem in odd list
                if(copyDeque.isEmpty()){
                    return true;
                }

                T back = copyDeque.popBack();

                if(front != back){
                    return false;
                }
            }
        }catch(Exception e){
            e.printStackTrace();
        }

        return true;
    }
}
