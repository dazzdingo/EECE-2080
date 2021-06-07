#include <bits/stdc++.h>
#include "Task3_1.h"

using namespace std;
 
int main()
{
    int value, choice;
    while(1){
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit");
        printf("\nEnter your choice: ");
        cin >> choice;
        switch(choice){
	    case 1: printf("Enter the value to be insert: ");
		    cin >> value;
		    push(value);
		    break;
	    case 3: cout << "\nTop element is " << top() << endl;
            break;
        case 2: pop();
		    break;
	    case 4: display();
		    break;
	    case 5: exit(0);
	    default: printf("\nWrong selection! Please try again!");
        }
    }
}
