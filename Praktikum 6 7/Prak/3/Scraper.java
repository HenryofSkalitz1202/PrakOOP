public class Scraper extends Thread {
    private final String prompt;
    private final Solver solver;

    public Scraper(String prompt, Solver solver) {
        this.prompt = prompt;
        this.solver = solver;
    }

    @Override
    public void run() {
        Gpt gpt = new Gpt(prompt);
        char answer = gpt.getPieceAnswer();
        solver.addAnswer(answer);
        solver.notifyThreadCompleted();
    }
}
