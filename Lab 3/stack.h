#pragma once
#include <iostream>
using namespace std;
class stack {
private:

    int maxsize = 10;

    int next = 0;

    int data[10];

public:

    /*stack();

    stack(int size) {

    maxsize = size;



    }*/

    //data = new int[10];

    void push(int var) {
        //data = new int[10];
        if (next >= maxsize) {
            cout << "STACK IS FULL!" << endl;
        }

        else {
            data[next] = var;
            next++;

        }
    }
    int pop() {
        //data = new int[10];
        if ((next - 1) < 0) {


            cout << "STACK IS EMPTY" << endl;

        }
        else {
            next = next - 1;
            int val = data[next];
            return val;
        }
    }
    int topStack() {
        if ((next - 1) < 0) {
            cout << "STACK IS EMPTY" << endl;
        }
        else {
            int val = data[next - 1];
            cout << "The Value on top of the stack is " << val << endl;
            return val;
        }
    }
    int length() {
        int tempval = next;
        cout << "The Number of items in the stack is " << tempval << endl;
        return tempval;
    }
    void display() {
        if ((next - 1) < 0) {
            cout << "STACK IS EMPTY" << endl << endl;;
        }
        else {
            cout << "The Values of the stack are: " << endl;
            for (int t = 0; t < next; t++) {
                cout << data[t]<<endl;
            }
        }
    }
};
class queue {

private:

    int maxsize = 10;
    int start=0;
    int end=0;
    int count=0;
    char data2[10];

public:
    void enqueue(char val) {
       // data2 = new char[10];
        data2[end] = val;
        count++;
        end++;
    }
    int dequeue() {
        char returned_val = data2[start];
        start++;
        count--;
        return returned_val;
    }
    bool isFull() {
        return count == maxsize;
    }
    bool isEmpty() {
        return count == 0;
    }
    int length() {
        int tempval = count;
        cout << "The Number of items in the queue is " << tempval;
        return tempval;
    }
    void qDisplay() {
        if (isEmpty()) {
            cout << "STACK IS EMPTY" << endl << endl;;
        }
        else {
            cout << "The Values of the queue are: " << endl;
            for (int t = 0; t < end; t++) {
                cout << data2[t]<<endl;
            }
        }
    }
};