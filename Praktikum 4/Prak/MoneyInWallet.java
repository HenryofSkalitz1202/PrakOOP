public class MoneyInWallet implements MoneyTransaction{
    private int amount;

    /*
     * Inisialisasi amount = 0
     */
    public MoneyInWallet(){
        this.amount = 0;
    }

    /*
     * Inisialisasi amount sesuai masukan
     */
    public MoneyInWallet(int amount){
        this.amount = amount;
    }

    /*
     * Mengembalikan nilai amount
     */
    public int getAmount(){
        return this.amount;
    }

    /*
     * Menambahkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInWallet
     */
    public MoneyTransaction add(MoneyTransaction money){
        int moneyToAdd = money.getAmount();
        this.amount += moneyToAdd;

        return new MoneyInWallet(this.amount);
    }

    /*
     * Mengurangkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInWallet
     * Jika amount dari masukan lebih besar dari amount, maka objek yang dikembalikan memiliki amount = 0
     */
    public MoneyTransaction subtract(MoneyTransaction money){
        int moneyToSubtract = money.getAmount();

        if (moneyToSubtract > this.amount) {
            this.amount = 0;
        } else {
            this.amount -= moneyToSubtract;
        }

        return new MoneyInWallet(this.amount);
    }

    /*
     * Menyimpan uang di dompet dapat membuang uang menjadi lapuk
     * Amount akan menjadi 90% dari sebelumnya
     * Jika hasil bukan integer, bulatkan hasil ke bawah
     */
    public void decay(){
        this.amount = (int)Math.floor(this.amount * 0.9);
    }
}