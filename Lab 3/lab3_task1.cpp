#include <iostream>
#include<stdio.h>
#define SIZE 10

using namespace std;

void push(int);
void pop();
void display();

int stack[SIZE], top = -1;

void push(int value){
   if(top == SIZE-1)
      cout << "Stack is Full! Insertion is not possible!";
   else{
      top++;
      stack[top] = value;
      cout << "Insertion success!";
   }
}
void pop(){
   if(top == -1)
      cout << "Stack is Empty! Deletion is not possible!";
   else{
      cout << "Deleted : " <<  stack[top];
      top--;
   }
}
void display(){
   if(top == -1)
      cout << "Stack is Empty!";
   else{
      int i;
      cout << "Stack elements are:";
      for(i=top; i>=0; i--)
	      cout << stack[i];
   }
}


int main()
{
   int value, choice;
   while(1){
      cout <<"***** MENU *****" <<endl;
      cout <<"1. Push" << endl<< "2. Pop" << endl<< "3. Display"<< endl<<"4. Exit"<<endl;
      cout << "Enter your choice: ";
      cin >> choice;
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 cin >> value;
		 push(value);
		 break;
	 case 2: pop();
		 break;
	 case 3: display();
		 break;
	 case 4: 
	   cout << "Wrong selection! Please try again!";
      break ();
      }
   }

}
