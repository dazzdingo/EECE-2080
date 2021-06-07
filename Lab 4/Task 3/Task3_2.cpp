#include <bits/stdc++.h>
#include "Task3_2.h"

using namespace std;

int main()
{
 int choice, flag=1, value;
 while( flag == 1){
        cout<<"\n1.enqueue \n2.dequeue \n3.showfront \n4.displayQueue \n5.exit\n";
        cin>>choice;
        switch (choice)
        {
        case 1: 
                cout<<"Enter Value:\n";
                cin>>value;
                enqueue(value);
                break;
        case 2: 
                dequeue();
                break;
        case 3: 
                showfront();
                break;
        case 4: 
                displayQueue();
                break;
        case 5: 
                flag = 0;
                break;
        }
        }

        return 0;
}
