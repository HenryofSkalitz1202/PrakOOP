class Strength extends Hero{
    public Strength(){
        super();
    }

    public Strength(Integer level){
        super(level);
    }

    public Double value(){
        return this.getLevel() + 0.2;
    }

    public void printInfo(){
        System.out.println("Strength Hero (Lvl " + this.getLevel() + ")");
    }
}