#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
    
    int sz;
    printf("Enter the size of array: ");
    scanf("%d",&sz);

    int arr[sz], i;
    for(i = 0; i < sz; i++)
    arr[i] = rand()%(sz*2);
    
    int n = sizeof(arr)/sizeof(arr[0]);

    auto t1 = high_resolution_clock::now();
    bubbleSort(arr, n);
    auto t2 = high_resolution_clock::now();

    cout<<"Sorted array: \n";
    printArray(arr, n);
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << " ms";

    return 0;
}
