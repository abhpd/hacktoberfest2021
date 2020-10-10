// Implementation of circular queue 


#include <iostream>
using namespace std;

class circularq{
  int rear;
  int front;
  int size;
  int cq[10];
  public:
  circularq()
    {
    cout<<"\n enter size";
    cin>>size;
    rear=front=-1;
    }
    void enQueue(int element); 
    int deQueue(); 
    void displayQueue();
    bool qfull();
    bool qempty(){
      if(front == -1 && rear== -1){
        return true;
      }
      else{
        return false;
      }
    }
};

void circularq::enQueue(int element){
  if (qfull())
  {
      cout<<"\n circular queue is full ";
      return;
  }
  else{
    if(rear==-1 && front==-1){
        rear=front=0;
        cq[rear]=element;
        cout<<cq[rear];
    }
    else{
      rear=(rear+1)%size;
      cq[rear]=element;
      cout<<cq[rear];
    }
  }
}

int circularq::deQueue(){
  if(qempty()){
    cout<<"\n circular queue is empty ";
    return 0;
  }
  else{
    int element=cq[front];
    cout<<front;
    if(front==rear){
      front=rear=-1;
    }
    else{
      front=(front+1)%size;
    }
    return element;
  }
}

bool circularq::qfull(){
  if(((rear+1)%size)==front){
    return true;
  }
  else{
    return false;
  }
}

void circularq::displayQueue()
{
  if(qempty()){
    cout<<"\n Queue is empty ";
  }
  else{
    cout << "\n Queue is: " << endl;
    for(int i = 0; i < size; ++i){
            cout << cq[i] << "  ";
    }
    cout<< "\n ";
  }
}

int main() {
  int i,choice,element,num;
  circularq c;
  int n=0;
	do{
		cout<<"\n  1. enqueue";
		cout<<"\n  2. Dequeue";
    cout<<"\n  3. display list";
    cout<<"\n  0.Exit";
		cout<<"\n  Enter choice";
		cin>>choice;
		switch(choice)
		{
			case 1:
            cout<<"\n Enter Element to be entered : ";
            cin>>element;
            c.enQueue(element);
            break;
			case 2:
            num=c.deQueue();
            cout<<"\n Element decremented is  : "<<num;
            break;
      case 3:
            c.displayQueue();
            break;
			case 0:
            cout<<"\nexiting";
		}
	}while(choice!=0);


}