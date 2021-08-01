#include <bits/stdc++.h>
using namespace std;

//
//SORT NAMES
//
//function to print the array
void print(vector<string> names) {
	for(int i = 0; i < names.size(); i++)
		cout << names[i] << endl;
	printf("\n");
}

bool mycomp(string a, string b) {
	//returns 1 if string a is alphabetically less than string b
	return a < b;
}

vector<string> alphabeticallySort(vector<string> a) {
	int n = a.size();
	//mycomp function is the defined function which sorts the strings in alphabetical order
	sort(a.begin(), a.end(), mycomp);
	return a;
}

bool mycomp2(string a, string b) {
	//returns 1 if string a is alphabetically more than string b
	return a > b;
}
vector<string> reverseSort(vector<string> a) {
	int n = a.size();
	//mycomp2 function is the defined function which sorts the strings in reverse-alphabetical order
	sort(a.begin(), a.end(), mycomp2);
	return a;
}

//
//SORT MNumbers
//
// A utility function to get maximum value in arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using Radix Sort
void radixsort(int arr[], int n) {
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// Print sorted MNumbers (ascending)
void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n"; 
}

// Print sorted MNumbers (descending)
void rvereseArray(int arr[], int start, int end) {
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}    


int main() {   
	int sz, choice;
    printf("Enter the number of student(s): ");
    scanf("%d",&sz);

    while (true) {

    printf("\n***** MENU *****\n");
    printf("Press 1 to store first name.\nPress 2 to store last name.\nPress 3 to store MNumber.\nPress 4 to exit.\n");
    printf("\nEnter your choice: ");
    cin >> choice;
    switch (choice) {
      case 1: {
      //creating a vector of strings vector to store strings
	    vector<string> fnames;
	    string fname;
	    printf("\nEnter first name: \n");
	    //taking input
	    for(int i = 0; i < sz; i++){
		    cin >> fname;
		    //insert names into the vector
		    fnames.push_back(fname); 
	      }
	    //sort names alphabetically or reverse-alphabetically?
      printf("\nPress 1 to sort alphabetically. Press 2 to sort reverse-alphabetically. \n");
      int a;
      cin >> a;
      if (a == 1) {
        //function to sort names alphabetically
	      fnames = alphabeticallySort(fnames);
        cout << "\nSorted first names: \n";
	      print(fnames);
        }
      if (a == 2) {
        //function to sort names alphabetically
	      fnames = reverseSort(fnames);
        cout << "\nSorted first names: \n";
	      print(fnames);
        }
      break;	 
      }

      case 2: {
      //creating a vector of strings vector to store strings
	    vector<string> lnames;
	    string lname;
	    printf("\nEnter last name: \n");
	    //taking input
	    for(int i = 0; i < sz; i++){
		    cin >> lname;
		    //insert names into the vector
		    lnames.push_back(lname); 
	      }
	    //sort names alphabetically or reverse-alphabetically?
      printf("\nPress 1 to sort alphabetically. Press 2 to sort reverse-alphabetically. \n");
      int a;
      cin >> a;
      if (a == 1) {
        //function to sort names alphabetically
	      lnames = alphabeticallySort(lnames);
        cout << "\nSorted last names: \n";
	      print(lnames);
        }
      if (a == 2) {
        //function to sort names alphabetically
	      lnames = reverseSort(lnames);
        cout << "\nSorted last names: \n";
	      print(lnames);
        }
      break;  	 
      }

      case 3: {
      int arr[sz], i, MNumber;
      printf("\nEnter MNumber: \n");
    
      for(i = 0; i < sz; i++) {
      cin >> MNumber;
      arr[i] = MNumber;
      }

      int n = sizeof(arr)/sizeof(arr[0]);
      radixsort(arr, n);

      printf("\nPress 1 to sort in ascending order. Press 2 to in descending order. \n");
      int a;
      cin >> a;
      if (a == 1) {
        cout<<"\nSorted MNumbers: \n";
        print(arr, n);
        }
      if (a == 2) {
        rvereseArray(arr, 0, n-1);     
        cout<<"\nSorted MNumbers: \n";
        print(arr, n);
        }
      break;        
      }

      case 4:
      exit(0);

      default:
      printf("\nWrong selection! Please try again!\n");
      }
	return 0;
}
}
