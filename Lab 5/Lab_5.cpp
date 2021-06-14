#include<iostream>

#include<stdlib.h>

using namespace std;

class BST{

private:

struct node

{

string key;

struct node *left, *right;

};

struct node*root;

struct node* insert(struct node* Node , struct node*newNode)

{

if (Node == NULL) return newNode;

if (newNode->key < Node->key)

Node->left = insert(Node->left, newNode);

else if (newNode->key > Node->key)

Node->right = insert(Node->right, newNode);

return Node;

}

struct node*findmin(struct node*tree){

while(tree->left){

tree=tree->left;

}

return tree;

}

node*deletenode(struct node*tree, string key){

node*temp;

if(!tree)return NULL;

else if(tree->key<key)tree->right=deletenode(tree->right,key);

else if(tree->key>key)tree->left=deletenode(tree->left,key);

else if(tree->key==key){

if(!tree->left){

temp=tree->right;

delete(tree);

return temp;

}

if(!tree->right){

temp=tree->left;

delete(tree);

return temp;

}

temp=findmin(tree->right);

tree->key=temp->key;

deletenode(tree->right,temp->key);

}

else

cout<<"key not found\n";

return tree;

}

bool search(node* Node, string x)

{

if (Node == NULL){
  return false;
}

if (Node->key == x){
  return true;
}

bool res1 = search(Node->left, x);
if (res1) {
  return true;
}
bool res2 = search(Node->right, x);
return res2;

}

int size(struct node*Node){

if(!Node)return 0;

return 1+size(Node->left)+size(Node->right);

}

void inorder(struct node*Node , string &arr){

if(!Node)return;

inorder(Node->left , arr );

arr+=Node->key+"\n";

inorder(Node->right , arr );

}

public:

BST(){

root=NULL;

}

void Insert(string item){

struct node *temp = new struct node;

temp->key = item;

temp->left =NULL;

temp->right = NULL;

root= insert(root,temp);

}

void Remove(string item){

root= deletenode(root,item);

}

bool Search(string item){

return search(root,item);

}

int Size(){

return size(root);

}

string PrintTree(){

string arr="";

inorder(root,arr);

return arr;

}

};

int main()

{

BST bst1;

//Insert elements into Tree 1
string arr1[] = {"ABC", "CBS", "ESPN", "Fox", "NBC"};

for(int i=0;i<5;i++){

bst1.Insert(arr1[i]);

}

//Print Tree 1
cout<<"The first list has "<<bst1.Size()<<" element(s): \n";

cout<<bst1.PrintTree();

//Search "ESPN" in Tree 1
if (bst1.Search("ESPN"))
        cout << "ESPN is in the first list." << endl;
    else
        cout << "ESPN is not in the first list." << endl;

//Empty Tree 1
cout<<"Deleting...\n";
for(int i=0;i<5;i++){

bst1.Remove(arr1[i]);

}

//Print Tree 1 again
cout<<"The first list has "<<bst1.Size()<<" element. It has been removed.\n";

cout<<bst1.PrintTree()<<"\n";

BST bst2;

//Insert elements into Tree 2
string arr2[] = {"Space Force", "Lilyhammer", "Master of none", "Tiger King", "Nailed it!"};

for(int i=0;i<5;i++){

bst2.Insert(arr2[i]);

}

//Print Tree 2
cout<<"The second list has "<<bst2.Size()<<" element(s): \n";

cout<<bst2.PrintTree();

//Search "DMM" in Tree 2
if (bst2.Search("DMM"))
        cout << "DMM is in the second list.\n" << endl;
    else
        cout << "DMM is not in the second list.\n" << endl;

BST bst3;

//Insert elements into Tree 3
string arr3[] = {"Avengers: Endgame", "Lion King", "Frozen II", "Spider-man: Far From Home"};

for(int i=0;i<4;i++){

bst3.Insert(arr3[i]);

}

//Print Tree 3
cout<<"The third list has "<<bst3.Size()<<" element(s): \n";

cout<<bst3.PrintTree();

//Remove "Frozen II" from Tree 3
bst3.Remove("Frozen II");
cout<<"'Frozen II' has been removed.\n";

//Print Tree 3 again
cout<<"After removed 'Frozen II', the third list has "<<bst3.Size()<<" element(s): \n";

cout<<bst3.PrintTree();

return 0;

}