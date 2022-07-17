public interface Queue
{
	//Jumlah Elemen pada Queue
	public int size();
	
	//True jika Queue kosong
	public boolean isEmpty();
	
	//Elemen pertama pada Queue
	public Object peek() throws QueueEmptyException;
	
	//Memasukkan elemen kedalam Queue
	public void enqueue(Object element) throws QueueFullException;
	
	//Mengeluarkan elemen dari Queue
	public Object dequeue() throws QueueEmptyException;
}