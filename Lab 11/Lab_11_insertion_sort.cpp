#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
 
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
/* Driver code */
int main()
{
    
    int sz;
    printf("Enter the size of array: ");
    scanf("%d",&sz);

    int arr[sz], i;
    for(i = 0; i < sz; i++)
    arr[i] = rand()%(sz*2);
    
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    auto t1 = high_resolution_clock::now(); 
    insertionSort(arr, n);
    auto t2 = high_resolution_clock::now();

    printArray(arr, n);
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << " ms";
 
    return 0;
}
