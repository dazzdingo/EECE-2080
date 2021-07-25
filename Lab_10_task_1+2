#include <fstream>

#include <string>

#include <iostream>

#include <bits/stdc++.h>

using namespace std;

// Function to add an edge

void addEdge(vector < vector < int >> & adj, int point1, int point2) {
  adj[point1].push_back(point2);
  adj[point2].push_back(point1);
}

// Function to delete an edge
void delEdge(vector < vector < int >> & adj, int point1, int point2) {
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
    else {
      cout << "Can't delete" << endl;}
  }

  // Also traverse and delete point1 from point2's adjacency list
  for (int i = 0; i < adj[point2].size(); i++) {
    currentValue = adj[point2][i];
    if (currentValue == point1) {
      adj[point2].erase(adj[point2].begin() + i);
      break;
    }
    else {
      cout << "Can't delete" << endl;}
  }
}



// Function to search an edge
void hasEdge(vector<vector<int>>& adj, int point1, int point2) {
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
    cout << "The edge you are looking for is in the graph." << endl;
  } else {
    cout << "The edge you are looking for is not in the graph." << endl;
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

void printGraph(vector<vector<int>>& adj) {
  for (int i = 0; i < adj.size(); i++) {
    vector<int> individualAdjList = adj.at(i);
    cout << i << " -> ";
    printSingleVector(individualAdjList);
  }
}

// Driver code
int main() {
  int choice;
  int numVertices = 0;
  vector<vector<int>> adj;

  // Ask for size of vector
  printf("Enter the number of vertices: ");
  cin >> numVertices;
  // Resize
  adj.resize(numVertices);

  while (true) {

    printf("\n\n***** MENU *****\n");
    printf("Press 1 to add an edge (i, j) to the graph.\nPress 2 to remove an edge (i, j) from the graph.\nPress 3 to verify if an edge (i, j) is in the graph.\nPress 4 to print the graph \nPress 5 to exit.");
    printf("\nEnter your choice: ");
    cin >> choice;
    switch (choice) {
    case 1: {
      int i, j;
      printf("Enter i: ");
      cin >> i;
      printf("Enter j: ");
      cin >> j;
      addEdge(adj, i, j);
      break;
    }

    case 2: {
      int i, j;
      printf("Enter i: ");
      cin >> i;
      printf("Enter j: ");
      cin >> j;
      delEdge(adj, i, j);
      break;
    }

    case 3: {
      int i, j;
      printf("Enter i: ");
      cin >> i;
      printf("Enter j: ");
      cin >> j;
      hasEdge(adj, i, j);
      break;
    }

    case 4: {
      printGraph(adj);
      break;
    }

    case 5:
      exit(0);
    default:
      printf("\nWrong selection! Please try again!");
    }
  }
  return 0;
}
