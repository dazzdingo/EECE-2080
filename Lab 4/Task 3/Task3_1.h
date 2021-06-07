#include <bits/stdc++.h>
using namespace std;
 
// Declare linked list node
 
struct Node
{
    int data;
    struct Node* link;
};
 
struct Node* t;
 
// Function to add an element data in the stack insert at the beginning
void push(int data)
{
     
    // Create new node temp and allocate memory
    struct Node* temp;
    temp = new Node();
 
    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }
 
    // Initialize data into temp data field
    temp->data = data;
 
    // Put top pointer reference into temp link
    temp->link = t;
 
    // Make temp as top of Stack
    t = temp;
}
 
// Function to check if the stack is empty or not
int isEmpty()
{
    return t == NULL;
}
 
// Function to return top element in a stack
int top()
{
     
    // Check for empty stack
    if (!isEmpty())
        return t->data;
    else
        exit(1);
}
 
// Function to pop top element from the stack
void pop()
{
    struct Node* temp;
 
    // Check for stack underflow
    if (t == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
         
        // Top assign into temp
        temp = t;
 
        // Assign second node to top
        t = t->link;
 
        // Destroy connection between
        // first and second
        temp->link = NULL;
 
        // Release memory of top node
        free(temp);
    }
}
 
// Function to print all the elements of the stack
void display()
{
    struct Node* temp;
 
    // Check for stack underflow
    if (t == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = t;
        while (temp != NULL)
        {
 
            // Print node data
            cout << temp->data << "-> ";
 
            // Assign temp link to temp
            temp = temp->link;
        }
    }
}