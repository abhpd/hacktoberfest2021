import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

/**
 * Thread pool vs. thread performance comparison
 */
public class ThreadPoolPerformance {
	// Maximum number of executions
    public static final int maxCount = 1000;

    public static void main(String[] args) throws InterruptedException {
        // Thread test code
        ThreadPerformanceTest();

        // Thread pool test code
        ThreadPoolPerformanceTest();
    }

    /**
     * Thread pool performance test
     */
    private static void ThreadPoolPerformanceTest() throws InterruptedException {
        // Starting time
        long stime = System.currentTimeMillis();
        // Business code
        ThreadPoolExecutor tp = new ThreadPoolExecutor(10, 10, 0,
                TimeUnit.SECONDS, new LinkedBlockingDeque<>());
        for (int i = 0; i < maxCount; i++) {
            tp.execute(new PerformanceRunnable());
        }
        tp.shutdown();
        tp.awaitTermination(1, TimeUnit.SECONDS);  // Wait for the thread pool execution to complete
        // End Time
        long etime = System.currentTimeMillis();
        // Calculation execution time
        System.out.printf("Thread pool execution time：%d millisecond.", (etime - stime));
        System.out.println();
    }

    /**
     * Thread performance test
     */
    private static void ThreadPerformanceTest() {
        // Starting time
        long stime = System.currentTimeMillis();
        // Execute business code
        for (int i = 0; i < maxCount; i++) {
            Thread td = new Thread(new PerformanceRunnable());
            td.start();
            try {
                td.join(); // Ensure thread execution is complete
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        // End Time
        long etime = System.currentTimeMillis();
        // Calculation execution time
        System.out.printf("Thread execution time：%d millisecond.", (etime - stime));
        System.out.println();
    }

	// Business execution
    static class PerformanceRunnable implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i < maxCount; i++) {
                long num = i * i + i;
            }
        }
    }
}