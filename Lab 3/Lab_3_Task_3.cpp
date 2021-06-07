#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:      
   char stack[25];                           // Declaring stack array in class Stack
   int top = -1;
  
   void push(char element)                   // Push function
   {
       top++;
       stack[top] = element;
   }
  
   char pop()                               // Pop function
   {
       char element = stack[top];
       top--;
       return element;
   }
  
   void print()                           // Function for printing topmost element of stack
   {
       cout << stack[top];
   }
};

class Queue
{
public:      
   char queue[25];                           // Declaring queue array in class Queue
   int front = 0, rear = 0;
  
   void enqueue(char element)               // Enqueue function
   {
   queue[rear] = element;
rear++;
   }
  
   char dequeue()                            // Dequeue function
   {
       char element=queue[front];
   queue[front] = 0;
front++;
return element;
   }
  
   void print()                           // Function for printing first element in queue
   {
       cout << queue[front];
   }
};

int main()
{
   for(int i = 1; i > 0; i++)
   {
       string x;
       printf("\n\n***** MENU *****\n");
       printf("1. Send message\n2. Exit");
       printf("\nEnter your choice: ");
       getline(cin, x);
      
       if(x[0] == '1')
       {
           string s;
           Stack S;
           Queue Q;
           cout << "Enter your message: ";
           getline(cin, s);
           int L = s.length();
          
           for(int i = 0; i < L; i++)                       // Message stored in queue(buffer according to question)
               Q.enqueue(s[i]);
              
           cout<<"Content of Queue: ";
           for(int i = 0; i < L; i++)
           {
               Q.print();                               // Printing the contents of Queue
               char element = Q.dequeue();               // Transforming the message using Queue and Stack
               S.push(element);
           }
           cout << endl;
          
           cout << "Content of Stack: ";
           string transformed_message[L];
           for(int i = 0; i < L; i++)
           {
               S.print();                               // Printing the contents of Queue
               transformed_message[i] = S.pop();
           }
           cout << endl;
       }
       else
           break;
   }
}
