public class Main {
    public static void main(String[] args) throws InterruptedException {
        Solver solver = new Solver();
        solver.addPiece("Prompt 1");
        solver.addPiece("Prompt 2");
        solver.addPiece("Prompt 3");

        String answer = solver.scrapeAnswer();
        System.out.println("Jawaban teka teki: " + answer);
    }
}
