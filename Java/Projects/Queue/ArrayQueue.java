public class ArrayQueue implements Queue
{
	//Kapasitas default dari Queue
	public static final int CAPACITY = 1000;
	
	private int capacity; //kapasitas Queue
	private Object S[]; //Array yang digunakan dalam implementasi Queue
	private int peek = -1; //Index dari elemen Queue yang pertama;
	
	//Constructor Default
	public ArrayQueue()
	{
		this(CAPACITY);
	}
	
	//Constructor alternatif
	public ArrayQueue(int cap)
	{
		capacity = cap;
		S = new Object[capacity];
	}
	
	public int size()
	{
		return (peek + 1);
	}
	
	public boolean isEmpty()
	{
		return (peek < 0);
	}
	
	public Object peek() throws QueueEmptyException
	{
		if (isEmpty())
			throw new QueueEmptyException("Queue is empty");
		return S[0];
	}
	
	public void enqueue(Object obj) throws QueueFullException
	{
		if (size() == capacity)
			throw new QueueFullException("Queue is full");
		peek = peek + 1;
		S[peek] = obj;
	}
	
	public Object dequeue() throws QueueEmptyException
	{
		Object elem;
		if (isEmpty())
			throw new QueueEmptyException("NO MORE dequeue! Queue is empty");
		
		elem = S[0];
		for (int i = 0; i < peek; i++)
		{
			S[i] = S[i+1];
		}
		peek = peek - 1;
		return elem;
	}
}