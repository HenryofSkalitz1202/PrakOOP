class Kompleks{
    public Kompleks(){
        this.real = 0;
        this.imaginer = 0;
        n_kompleks++;
    }

    public Kompleks(int real, int imaginer){
        this.real = real;
        this.imaginer = imaginer;
        n_kompleks++;
    }

    public int getReal() {
        return this.real;
    }
    public int getImaginer(){
        return this.imaginer;
    }
    
    public void setReal(int real){
        this.real = real;
    }
    
    public void setImaginer(int imaginer){
        this.imaginer = imaginer;
    }
    
    public Kompleks plus(Kompleks b){
        int new_real = this.real + b.getReal();
        int new_imaginer = this.imaginer + b.getImaginer();
        return new Kompleks(new_real, new_imaginer);
    }
    
    public Kompleks minus(Kompleks b){
        int new_real = this.real - b.getReal();
        int new_imaginer = this.imaginer - b.getImaginer();
        return new Kompleks(new_real, new_imaginer);
    }
    
    public Kompleks multiply(Kompleks b){
        int new_real = this.real * b.getReal() - this.imaginer * b.getImaginer();
        int new_imaginer = this.imaginer * b.getReal() + this.real * b.getImaginer();
        return new Kompleks(new_real, new_imaginer);
    }
    
    public Kompleks multiply(int c){
        int new_real = this.real * c;
        int new_imaginer = this.imaginer * c;
        return new Kompleks(new_real, new_imaginer);
    }
    
    public static int countKompleksInstance(){
        return n_kompleks;
    }

    public void print(){
        if(this.real == 0){
            if(this.imaginer == 0){
                System.out.println(0);
            }else{
                System.out.print(this.imaginer);
                System.out.print("i");
                System.out.println();
            }
        }else{
            System.out.print(this.real);
            if(this.imaginer != 0){
                if(this.imaginer > 0){
                    System.out.print("+");
                }
                System.out.print(this.imaginer);
                System.out.print("i");
            }
            System.out.println();
        }
    }
    private static int n_kompleks;
    private int real;
    private int imaginer;
}