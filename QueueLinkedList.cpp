#include <iostream>
using namespace std;
class Node{
  public:
    int data;
    Node* next;
};
class Queue{
  public:
   Node* front;
   Node* rear;

   Queue(){
     front = NULL;
     rear = NULL;
   }

   bool isEmpty(){
     if(front == NULL)
       return true;
     else
       return false;
   }

   void EnQueue(int val){
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
     if(front == NULL && rear == NULL){
       front = temp;
       rear = temp;
     }
     else{
       rear->next=temp;
       rear = temp;
     }
   }

   int Dequeue(){
     int val;
     if(front == NULL)
       return 0;
     else if(front == rear){
       val = front->data;
       delete front;
       front = NULL;
       rear = NULL;
     }
     else{
       val = front->data;
       Node* temp = front;
       front = front->next;
       delete temp;
     }
     return val;
   }

   void Display(){
      Node* current = front;
      while(current != NULL){
         cout << current->data << endl;
         current=current->next;
      }
     }

   int Length(){
      Node* current = front;
      int cnt = 0;
      while(current != NULL){
         cnt++;
         current=current->next;
      }
      return cnt;
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
                cout << "Dequeue Value: " << q1.Dequeue() << endl;
              break;
            case 3:
              cout <<"Length: " << q1.Length() << endl;
              break;
            case 4:
              cout << "Values in the List: " << endl;
              q1.Display();
              break;
          }
      }while(choice != 0);
}