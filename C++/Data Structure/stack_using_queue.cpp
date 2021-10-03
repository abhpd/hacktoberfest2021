//C++ Program to Implement Stack Using Two Queues

#include<iostream>
using namespace std;
struct qu1// queue1 declaration {
   qu1 *n1;
   int d1;
}*f1 = NULL, *r1 = NULL, *q1 = NULL, *p1 = NULL, *np1 = NULL;

struct qu2// queue2 declaration {
   qu2 *n2;
   int d2;
}*f2 = NULL, *r2 = NULL, *q2 = NULL, *p2 = NULL, *np2 = NULL;

void enqueue1(int a) {
   np1 = new qu1;
   np1->d1 = a;
   np1->n1 = NULL;
   if (f1 == NULL) {
      r1 = np1;
      r1->n1 = NULL;
      f1 = r1;
   } 
  else {
      r1->n1 = np1;
      r1 = np1;
      r1->n1 = NULL;
   }
}

int dequeue1() {
   int a;
   if (f1 == NULL) {
      cout<<"no elements present in queue\n";
   } 
  else {
      q1 = f1;
      f1 = f1->n1;
      a = q1->d1;
      delete(q1);
      return a;
   }
}

void enqueue2(int a) {
   np2 = new qu2;
   np2->d2 = a;
   np2->n2 = NULL;
   if (f2 == NULL) {
      r2 = np2;
      r2->n2 = NULL;
      f2 = r2;
   } 
  else {
      r2->n2 = np2;
      r2 = np2;
      r2->n2 = NULL;
   }
}

int dequeue2() {
   int a;
   if (f2 == NULL) {
      cout<<"no elements present in queue\n";
   } 
  else {
      q2 = f2;
      f2 = f2->n2;
      a = q2->d2;
      delete(q2);
      return a;
   }
}

int main() {
   int n, a, i = 0;
   cout<<"Enter the number of elements to be entered into stack\n";
   cin>>n;
   while (i < n) {
      cout<<"enter the element to be entered\n";
      cin>>a;
      enqueue1(a);
      i++;
   }
   cout<<"\n\nElements popped\n\n";
   while (f1 != NULL || f2 != NULL)// if both queues are not null {
      if (f2 == NULL)// if queue 2 is null {
         while (f1->n1 != NULL) {
            enqueue2(dequeue1());
         }
         cout<<dequeue1()<<endl;
      } else if (f1 == NULL)//if queue 1 is null {
         while (f2->n2 != NULL) {
            enqueue1(dequeue2());
         }
         cout<<dequeue2()<<endl;
      }
   }
}
