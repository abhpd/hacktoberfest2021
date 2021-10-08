public class QueueTest
{
	public static void main(String[] args)
	{
		int N = 5;
		ArrayQueue as = new ArrayQueue(N);
		
		System.out.println("enqueue Operations");
		for (int i=0; i<N; i++)
		{
			as.enqueue(i+11);
			System.out.print("Item in peek: " + as.peek());
			System.out.println(" Number of items in the Queue: " + as.size());			
		}
		
		System.out.println("dequeue Operations");
		for (int i=0; i<3; i++)
		{
			System.out.print("dequeue Element: " + as.dequeue());
			System.out.print(" Number of items in the Queue: " + as.size());
			System.out.println(" NOW, item in peek: " + as.peek());
		}
		
		for (int i=0; i<3; i++)
		{
			as.enqueue(i+11);
			System.out.print("Item in peek: " + as.peek());
			System.out.println(" Number of items in the Queue: " + as.size());			
		}
		
		System.out.println("dequeue Operations");
		for (int i=0; i<N; i++)
		{
			System.out.print("dequeue Element: " + as.dequeue());
			System.out.print(" Number of items in the Queue: " + as.size());
			System.out.println(" NOW, item in peek: " + as.peek());
		}
		
	}
}