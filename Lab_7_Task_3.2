#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <chrono>
using namespace std;

class Heap
{
    private:
        vector <int> heap;
        int left(int parent);
        int right(int parent);
        int parent(int child);
        void heapifyup(int index);
        void heapifydown(int index);
    public:
        Heap()
        {}
        void Insert(int element);
        void DeleteMin();
        int ExtractMin();
        void PrintHeap();
        int Size();
};
//Return Heap Size
int Heap::Size()
{
    return heap.size();
}
 
//Insert
void Heap::Insert(int element)
{
    using namespace std::chrono_literals;
    heap.push_back(element);
    heapifyup(heap.size() -1);
}
//Delete Minimum Element
void Heap::DeleteMin()
{
    using namespace std::chrono_literals;
    if (heap.size() == 0)
    {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
}

//Print Heap
void Heap::PrintHeap()
{
    vector <int>::iterator pos = heap.begin();
    while (pos != heap.end())
    {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl;
}

int Heap::left(int parent)
{
    int l = 2 * parent + 1;
    if(l < heap.size())
        return l;
    else
        return -1;
}

int Heap::right(int parent)
{
    int r = 2 * parent + 2;
    if(r < heap.size())
        return r;
    else
        return -1;
}

int Heap::parent(int child)
{
    int p = (child - 1)/2;
    if(child == 0)
        return -1;
    else
        return p;
}
 
//Maintain Heap Structure bottom up
void Heap::heapifyup(int in)
{
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in])
    {
        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        heapifyup(parent(in));
    }
}
 
//Maintain Heap Structure top down
void Heap::heapifydown(int in)
{
 
    int child = left(in);
    int child1 = right(in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1])
    {
       child = child1;
    }
    if (child > 0)
    {
        int temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;
        heapifydown(child);
    }
}

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    Heap h;


    int i, n, item, item_priority;
          
          i = 1;

          printf("\nEnter the number of item(s) to be added to the heap: ");
          
          scanf("%d",&n);

          auto t1 = high_resolution_clock::now();
          while (i < n + 1){
            item = rand();
            h.Insert(item);
            i++;         
          }
          auto t2 = high_resolution_clock::now();
          
          cout<<"Heap is: ";
          h.PrintHeap();
          cout<<"\n";

          cout<<"The insertion time of " << n << " item(s) is: ";
          duration<double, std::milli> ms_double = t2 - t1;
          std::cout << ms_double.count() << "ms";
          cout<<"\n";

          i = 1;

          auto t3 = high_resolution_clock::now();
          while (i < n + 1){
            h.DeleteMin();
            i++;         
          }
          auto t4 = high_resolution_clock::now();
          
          cout<<"\n";
          cout<<"All items have been removed. ";
          h.PrintHeap();
          cout<<"\n";          
          
          cout<<"The deletion time of " << n << " item(s) is: ";
          duration<double, std::milli> ms_double2 = t4 - t3;
          std::cout << ms_double2.count() << "ms";
    return 0;
}
