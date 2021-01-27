#include <iostream>
using namespace std;
class Queue{
  public:
   int q[10];
   int front;
   int rear;

   Queue(){
     front = -1;
     rear = -1;
   }

   bool isEmpty(){
     if(front == -1)
       return true;
     else
       return false;
   }

   bool isFull(){
     if(rear == 9)
       return true;
     else
       return false;
   }

   void EnQueue(int val){
     if(isFull())
       return;
     else if(front == -1){
       front = 0;
       rear = 0;
     }
     else{
       rear++;
     }
     q[rear] = val;
   }

   int Dequeue(){
     int val;
     if(isEmpty())
       return 0;
     else if(front == rear){
       val = q[front];
       q[front]=0;
       front = -1;
       rear = -1;
       return val;
     }
     else{
       val = q[front];
       q[front]=0;
       front++;
       return val;
     }
   }

   void Display(){
     for(int i = front;i <= rear;i++)
       cout << q[i] << endl;
     }

   int Length(){
     return (rear-front+1);
   }
};
int main(){
  Queue q1;
  int choice,value;
      do {
          cout << "\n0 -> Exit\n1 -> EnQueue\n2 -> Dequeue\n3 -> Length\n4 -> Display" << endl;
          cout << "Enter your choice : " << endl;
          cin >> choice;
          cout << endl;
          switch(choice) {
            case 1:
             cout << "Enter the value you want to insert : " << endl;
              cin >> value;
              q1.EnQueue(value);
              break;
            case 2:
              if(q1.isEmpty())
                cout << "Stack Underflow!" << endl;
              else 
                cout << "Dequeued Value: " << q1.Dequeue() << endl;
              break;
            case 3:
              cout <<"Length: " << q1.Length() << endl;
              break;
            case 4:
              cout << "Values in the Queue: " << endl;
              q1.Display();
              break;
          }
      }while(choice != 0);
}