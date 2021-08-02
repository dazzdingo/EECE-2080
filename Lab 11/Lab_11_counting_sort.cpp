#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
 
// Counting sort in C++ programming

#include <iostream>
using namespace std;

void countSort(int array[], int size) {
  // The size of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int output[300000];
  int count[300000];
  int max = array[0];

  // Find the largest element of the array
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
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
    countSort(arr, n);
    auto t2 = high_resolution_clock::now();

    cout<<"Sorted array: \n";
    printArray(arr, n);
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << " ms";

    return 0;
}
