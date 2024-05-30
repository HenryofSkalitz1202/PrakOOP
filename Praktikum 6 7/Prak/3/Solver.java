import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solver {
    private final List<String> prompts;
    private final List<Character> answers;
    private int completedThreads;

    public Solver() {
        this.prompts = new ArrayList<>();
        this.answers = Collections.synchronizedList(new ArrayList<>());
        this.completedThreads = 0;
    }

    public void addPiece(String prompt) {
        this.prompts.add(prompt);
    }

    public synchronized void notifyThreadCompleted() {
        completedThreads++;
        if (completedThreads == prompts.size()) {
            notify();
        }
    }

    public String scrapeAnswer() throws InterruptedException {
        for (String prompt : prompts) {
            new Scraper(prompt, this).start();
        }

        synchronized (this) {
            while (completedThreads < prompts.size()) {
                wait();
            }
        }

        Collections.sort(answers);
        StringBuilder answer = new StringBuilder();
        for (char ch : answers) {
            answer.append(ch);
        }
        return answer.toString();
    }

    public void addAnswer(char answer) {
        answers.add(answer);
    }
}
