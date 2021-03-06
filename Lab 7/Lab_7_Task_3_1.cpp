#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;

struct node
{
        int priority;
        int info;
        struct node *link;
}*front=NULL;

void insert(int item, int item_priority);
int del();
void display();
int isEmpty();

void insert(int item,int item_priority)
{
        using namespace std::chrono_literals;

        struct node *tmp,*p;

        tmp=(struct node *)malloc(sizeof(struct node));
        if(tmp==NULL)
        {
                printf("\nMemory not available\n");
                return;
        }
        tmp->info=item;
        tmp->priority=item_priority;
        /*Queue is empty or item to be added has priority more than first element*/
        if( isEmpty() || item_priority < front->priority )
        {
                tmp->link=front;
                front=tmp;
        }
        else
        {
                p = front;
                while( p->link!=NULL && p->link->priority<=item_priority )
                        p=p->link;
                tmp->link=p->link;
                p->link=tmp;
        }
}

int del()
{
        using namespace std::chrono_literals;

        struct node *tmp;
        int item;
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        else
        {
                tmp=front;
                item=tmp->info;
                front=front->link;
                free(tmp);
        }
        return item;
}

int isEmpty()
{
        if( front == NULL )
                return 1;
        else
                return 0;

}


void display()
{
        struct node *ptr;
        ptr=front;
        if( isEmpty() )
                printf("\nQueue is empty\n");
        else
        {       printf("\nQueue is :\n");
                printf("\nPriority       Item\n");
                while(ptr!=NULL)
                {
                        printf("%5d        %5d\n",ptr->priority,ptr->info);
                        ptr=ptr->link;
                }
        }
}

int main()
{
        using std::chrono::high_resolution_clock;
        using std::chrono::duration_cast;
        using std::chrono::duration;
        using std::chrono::milliseconds;
        
        int i, n, item, item_priority;
          
          i = 1;

          printf("\nEnter the number of item(s) to be added to the queue: ");
          
          scanf("%d",&n);

          auto t1 = high_resolution_clock::now();
          while (i < n + 1){
            item = rand();
            insert(item, i);
            i++;         
          }
          auto t2 = high_resolution_clock::now();

          display();
          cout<<"\n";

          cout<<"The insertion time of " << n << " item(s) is: ";
          duration<double, std::milli> ms_double = t2 - t1;
          std::cout << ms_double.count() << "ms";
          cout<<"\n";

          i = 1;

          auto t3 = high_resolution_clock::now();
          while (i < n + 1){
            del();
            i++;         
          }
          auto t4 = high_resolution_clock::now();
          
          cout<<"\n";
          cout<<"All items have been removed. ";
          display();
          cout<<"\n";          
          
          cout<<"The deletion time of " << n << " item(s) is: ";
          duration<double, std::milli> ms_double2 = t4 - t3;
          std::cout << ms_double2.count() << "ms";

          
          

        return 0;
}
