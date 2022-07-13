#ifndef MY_PQ_H
#define MY_PQ_H

#include <vector>
#include<iostream>
#include<queue>
#include<cassert>
#include<algorithm>

using namespace std;

class My_PQ{
    int H[50];
    int size;
    //vector<int>heapvector;


public:
    My_PQ(){
        size=-1;
    }

    My_PQ(vector<int> arr){
        size=arr.size();
        sort(arr.rbegin(), arr.rend());

        for (int i=0;i<=size;i++){
            H[i]=arr[i];

        }

    }

    int parent(int i)
    {

        return (i - 1) / 2;
    }


    int rightChild(int i)
    {

        return ((2 * i) + 2);
    }


    int leftChild(int i)
    {

        return ((2 * i) + 1);
    }

    void shiftUp(int i)
    {
        while (i > 0 && H[parent(i)] < H[i]) {

            // Swap parent and current node
            swap(H[parent(i)], H[i]);

            // Update i to parent of i
            i = parent(i);
        }
    }

    void shiftDown(int i)
    {
        int maxIndex = i;

        // Left Child
        int l = leftChild(i);

        if (l <= size && H[l] > H[maxIndex]) {
            maxIndex = l;
        }

        // Right Child
        int r = rightChild(i);

        if (r <= size && H[r] > H[maxIndex]) {
            maxIndex = r;
        }

        // If i not same as maxIndex
        if (i != maxIndex) {
            swap(H[i], H[maxIndex]);
            shiftDown(maxIndex);
        }
    }

    int extract_max(){
        int result = H[0];

        // Replace the value at the root
        // with the last leaf
        H[0] = H[size];
        size = size - 1;

        // Shift down the replaced element
        // to maintain the heap property
        shiftDown(0);
        return result;

    }

    void change_priority(int index, int new_priority){
        int oldp = H[index];
        H[index] = new_priority;

        if (new_priority > oldp) {
            shiftUp(index);
        }
        else {
            shiftDown(index);
        }
    }

    int peek(){
        return H[0];
    }

    void insert(int value){
        size = size + 1;
        H[size] = value;

        // Shift Up to maintain heap property
        shiftUp(size);
    }


    void remove(int index){
        H[index] = peek()+ 1;

        // Shift the node to the root
        // of the heap
        shiftUp(index);
        extract_max();

    }
    int size_()
    {
        return size;
    }
};

#endif