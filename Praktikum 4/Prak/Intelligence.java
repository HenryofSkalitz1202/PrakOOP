class Intelligence extends Hero{
    public Intelligence(){
        super();
    }

    public Intelligence(Integer level){
        super(level);
    }

    public Double value(){
        return this.getLevel() + 0.1;
    }

    public void printInfo(){
        System.out.println("Intelligence Hero (Lvl " + this.getLevel() + ")");
    }
}