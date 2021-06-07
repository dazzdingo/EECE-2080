#include <bits/stdc++.h>
#include "Task1.h"

using namespace std;


int main()
{
  Node* head = NULL;

   int value, choice, temp;

   	while(1){
    	printf("\n\n***** MENU *****\n");
      	printf("1.  AddItemFront\n2.  AddItemEnd\n3.  GetItem\n4.  GetItemFront\n5.  IsInlist\n6.  IsEmpty\n7.  Size\n8.  SeeNext\n9.  SeeAt\n10. Reset\n11. Print\n12. Exit");

      	printf("\nEnter your choice: ");
      	cin >> choice;
      	switch(choice){
	 	case 1: printf("Enter the value to be insert: ");
		 	cin >> value;
			temp = value;
		 	AddItemFront(&head, value);
		 	break;

	 	case 2: printf("Enter the value to be insert: ");
		 	cin >> value;
		 	AddItemEnd(&head, value);
		 	break;

	 	case 3: printf("Enter the item you are looking for: ");
		 	cin >> value;
		 	GetItem(&head, value);
     		cout<<"You searched for:"<< value;
     		break;

	 	case 4:	 	
			GetItemFront(&head);
		 	break;

	 	case 5: printf("Enter the item you are looking for: ");
     		cin >> value;
		 	IsInlist(head, value)? cout<<value<<" is in the list." : cout<<value<<" is not in the list.";
		 	break;

   		case 6:
		 	IsEmpty(head)? cout<<"\nThe list is empty." : cout<<"\nThe list is not empty.";
			break;

	 	case 7: 
		 	cout<<"\nThe list has "<<Size(head)<<" item(s).";
		 	break;

	 	case 8: printf("Enter the item you are looking for: ");
		 	cin >> value;
		 	GetItem(&head, value);
     		cout<<"You searched for:"<< value; 
     	break;

	 	case 9: printf("Enter the value to be insert: ");
		 	cin >> value;
		 	cout << "\nThe item at location "<<value<<" is: " << SeeAt(head, value);
		 	break;

	 	case 10: printf("Enter the item you are looking for: ");
		 	cin >> value;
		 	GetItem(&head, value);
     		cout<<"You searched for:"<< value;
     		break;

	 	case 11: cout<<"\nCreated Linked list is: ";
    		Print(head);
		 	break;

	 	case 12: exit(0);
	 	default: printf("\nWrong selection! Please try again!");
    	}
   	}
}
