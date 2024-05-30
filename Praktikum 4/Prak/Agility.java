class Agility extends Hero{
    public Agility(){
        super();
    }

    public Agility(Integer level){
        super(level);
    }

    public Double value(){
        return this.getLevel() + 0.3;
    }
    
    public void printInfo(){
        System.out.println("Agility Hero (Lvl " + this.getLevel() + ")");
    }
}