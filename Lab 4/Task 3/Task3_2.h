#include <bits/stdc++.h>

using namespace std;

// Structure of Node.
struct Node
{
int data;

Node *link;
};

Node *front = NULL;
Node *rear = NULL;

// Function to check if queue is empty or not
bool isempty()
{
        if(front == NULL && rear == NULL)
                return true;
        else
                return false;
}

// function to enter elements in queue
void enqueue ( int value )
{
        Node *ptr = new Node();
        ptr->data= value;
        ptr->link = NULL;

 // If inserting the first element/node
        if( front == NULL ){
                front = ptr;
                rear = ptr;
        }
        else{
                rear ->link = ptr;
                rear = ptr;
        }
}

// function to delete/remove element from queue
void dequeue ( )
{
        if( isempty() )
                cout<<"Queue is empty\n";
        else // only one element/node in queue.
                if( front == rear){
                        free(front);
                        front = rear = NULL;
        }
        else{
                Node *ptr = front;
                front = front->link;
                free(ptr);
        }
}

// function to show the element at front
void showfront( )
{
        if( isempty())
                cout<<"Queue is empty\n";
        else
                cout<<"element at front is:"<<front->data;
}

// function to display queue
void displayQueue()
{
        if (isempty())
                cout<<"Queue is empty\n";
        else{
                Node *ptr = front;
                while( ptr !=NULL){
                        cout<<ptr->data<<" ";
                        ptr= ptr->link;
                }
        }
}

