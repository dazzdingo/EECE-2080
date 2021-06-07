#include <bits/stdc++.h>

using namespace std;

// A linked list node
class Node
{
    public:
    int data;
    struct Node *next;
};


// adds an item to the front of the list
void AddItemFront(Node** head_ref, int new_data)
{
    // allocate node
    Node* new_node = new Node();
 
    // put in the data
    new_node->data = new_data;
 
    // make next of new node as head
    new_node->next = (*head_ref);
 
    // move the head to point to the new node
    (*head_ref) = new_node;
}

// adds an item to the end of the list
void AddItemEnd(Node** head_ref, int new_data)
{
    // allocate node
    Node* new_node = new Node();
 
    Node *last = *head_ref; /* used in step 5*/
 
    // put in the data
    new_node->data = new_data;
 
    // This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;
 
    // If the Linked List is empty, then make the new node as head 
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
 
    // Else traverse till the last node
    while (last->next != NULL)
        last = last->next;
 
    // change the next of last node
    last->next = new_node;
    return;
}

// removes and returns the item in the list
void GetItem(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;         // free old head
        return;
    }
 
    // Else Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL){
      cout<<"\n"<<key<<" is not in the list."; 
      return;
    }
        
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    // Free memory
    delete temp;
    }
}

// Function to remove the first node of the linked list
Node* GetItemFront(Node** head)
{
     
    //Node* temp = head;
    //head = head->next;
    //delete temp;
    //return head;
    if (head == NULL)
        return NULL;
 
    // Move the head pointer to the next node
    Node* temp = *head;
    cout << "The value has been deleted is " << temp ->data;
    *head = temp->next; 
    delete temp;

}
    
// returns a bool indicating if the given item is in the list.
bool IsInlist(Node* head, int x)
{
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

// returns a bool indicating if the list is empty.
bool IsEmpty(Node* head)
{
    Node* current = head; // Initialize current
    while (current == NULL)
    {
      return true;
    }
    return false;
}

// returns an int indicating the number of items in the list.
int Size(Node* head)
{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// finds an item at a location in the list (int passed in from user), and returns the item without removing it.
int SeeAt(Node* head, int index)
{
 
    Node* current = head;
 
    // the index of the node we're currently looking at
    int count = 0;
    while (current != NULL) {
        if (count == index-1)
            return (current->data);
        count++;
        current = current->next;
    } 
    // if we get to this line, the caller was asking for a non-existent element so we assert fail
    assert(0);
}


// prints contents of linked list starting from head
void Print(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}