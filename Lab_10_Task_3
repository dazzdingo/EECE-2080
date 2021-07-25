#include <fstream>

#include <string>

#include <iostream>

#include <bits/stdc++.h>

using namespace std;

// Function to add an edge

void addEdge(vector<int> adj[], int point1, int point2) {
  adj[point1].push_back(point2);
  adj[point2].push_back(point1);
}

// Function to delete an edge
void delEdge(vector<int> adj[], int point1, int point2) {
  // Remove point1 from point2's adjacency list
  int currentValue;
  for (int i = 0; i < adj[point1].size(); i++) {
    currentValue = adj[point1][i];
    if (currentValue == point2) {
      // Remove element at index i
      // cplusplus.com/reference/vector/vector/erase/
      adj[point1].erase(adj[point1].begin() + i);
      break;
    }
  }

  // Also traverse and delete point1 from point2's adjacency list
  for (int i = 0; i < adj[point2].size(); i++) {
    currentValue = adj[point2][i];
    if (currentValue == point1) {
      adj[point2].erase(adj[point2].begin() + i);
      break;
    }
  }
}



// Function to search an edge
void hasEdge(vector<int> adj[], int point1, int point2) {
  bool found_1_in_2 = false;
  bool found_2_in_1 = false;

  // Try to find point1 in point2's adj list
  for (int i = 0; i < adj[point2].size(); i++) {
    if (adj[point2].at(i) == point1) {
      found_1_in_2 =  true;
      break;
    }
  }

  // Try to find point2 in point1's adj list
  for (int i = 0; i < adj[point1].size(); i++) {
    if (adj[point1].at(i) == point2) {
      found_2_in_1 = true;
      break;
    }
  }
  if (found_1_in_2 == 1 && found_2_in_1 == 1) {
    cout << "Found" << endl;
  } else {
    cout << "Not found" << endl;
  }
}

// Function to print the adjacency list representation of graph
void printSingleVector(vector<int>& a) {
  for (int i = 0; i < a.size(); i++) {
    int element = a.at(i);
    cout << element;
    // If this is not the last element, print an additional arrow
    if (i != a.size() - 1) {
      cout << " -> ";
    }
  }
  cout << endl;
}

void printGraph(vector<int> adj[], int sizeArray) {
  for (int i = 0; i < sizeArray; i++) {
    vector<int> individualAdjList = adj[i];
    cout << i << " -> ";
    printSingleVector(individualAdjList);
  }
}

// Driver code
int main() {
  int choice;
  int numVertices = 51;


  // Create array
  vector<int> adj[numVertices];
      addEdge(adj, 1, 2);
      addEdge(adj, 1, 7);
      addEdge(adj, 2, 3);
      addEdge(adj, 2, 5);
      addEdge(adj, 2, 7);
      addEdge(adj, 3, 4);
      addEdge(adj, 4, 5);
      addEdge(adj, 4, 6);
      addEdge(adj, 4, 10);
      addEdge(adj, 4, 11);
      addEdge(adj, 5, 6);
      addEdge(adj, 5, 7);
      addEdge(adj, 6, 7);
      addEdge(adj, 6, 9);
      addEdge(adj, 6, 10);
      addEdge(adj, 6, 11);
      addEdge(adj, 7, 8);
      addEdge(adj, 7, 9);
      addEdge(adj, 8, 9);
      addEdge(adj, 8, 16);
      addEdge(adj, 8, 17);
      addEdge(adj, 9, 10);
      addEdge(adj, 9, 15);
      addEdge(adj, 9, 16);
      addEdge(adj, 10, 11);
      addEdge(adj, 10, 13);
      addEdge(adj, 10, 14);
      addEdge(adj, 10, 15);
      addEdge(adj, 11, 12);
      addEdge(adj, 12, 13);
      addEdge(adj, 12, 21);
      addEdge(adj, 12, 22);
      addEdge(adj, 13, 14);
      addEdge(adj, 13, 20);
      addEdge(adj, 13, 21);
      addEdge(adj, 14, 15);
      addEdge(adj, 14, 20);
      addEdge(adj, 15, 16);
      addEdge(adj, 15, 19);
      addEdge(adj, 15, 20);
      addEdge(adj, 16, 17);
      addEdge(adj, 16, 18);
      addEdge(adj, 16, 19);
      addEdge(adj, 17, 18);
      addEdge(adj, 18, 19);
      addEdge(adj, 18, 23);
      addEdge(adj, 19, 20);
      addEdge(adj, 19, 23);
      addEdge(adj, 19, 25);
      addEdge(adj, 20, 21);
      addEdge(adj, 20, 25);
      addEdge(adj, 20, 29);
      addEdge(adj, 21, 22);
      addEdge(adj, 21, 29);
      addEdge(adj, 21, 30);
      addEdge(adj, 22, 30);
      addEdge(adj, 23, 25);
      addEdge(adj, 24, 26);
      addEdge(adj, 24, 27);
      addEdge(adj, 25, 26);
      addEdge(adj, 25, 28);
      addEdge(adj, 26, 27);
      addEdge(adj, 26, 28);
      addEdge(adj, 27, 28);
      addEdge(adj, 27, 37);
      addEdge(adj, 27, 38);
      addEdge(adj, 28, 29);
      addEdge(adj, 28, 36);
      addEdge(adj, 28, 37);
      addEdge(adj, 29, 30);
      addEdge(adj, 29, 31);
      addEdge(adj, 29, 32);
      addEdge(adj, 29, 34);
      addEdge(adj, 29, 35);
      addEdge(adj, 29, 36);
      addEdge(adj, 30, 31);
      addEdge(adj, 30, 33);
      addEdge(adj, 31, 32);
      addEdge(adj, 31, 33);
      addEdge(adj, 32, 34);
      addEdge(adj, 32, 33);
      addEdge(adj, 34, 35);
      addEdge(adj, 35, 36);
      addEdge(adj, 36, 37);
      addEdge(adj, 36, 38);
      addEdge(adj, 37, 38);
      addEdge(adj, 38, 39);
      addEdge(adj, 38, 46);
      addEdge(adj, 38, 47);
      addEdge(adj, 38, 48);
      addEdge(adj, 39, 40);
      addEdge(adj, 39, 43);
      addEdge(adj, 39, 45);
      addEdge(adj, 39, 46);
      addEdge(adj, 40, 41);
      addEdge(adj, 40, 43);
      addEdge(adj, 41, 42);
      addEdge(adj, 41, 43);
      addEdge(adj, 44, 45);
      addEdge(adj, 45, 46);
      addEdge(adj, 46, 47);
      addEdge(adj, 47, 48);
       printGraph(adj, numVertices);
  return 0;
}
