#include<iostream>
#include<math.h>
using namespace std;

class Heap{
public:
    int *heap;
    int maxSize;
    int currentSize;
    Heap(int sizing)
    {
        currentSize=0;
        maxSize=sizing;
        heap=new int[sizing];
    }
    void insertNode(int value)
    {
        if( currentSize == maxSize){
            cout<< "Overflow: Can't addToIndex node"<<endl;
            return;
        }
        currentSize++;
        int i= currentSize -1;
        heap[i]=value;
        while(i > 0 && heap[i] > heap[(i)/2])
        {
            swap(heap[i],heap[(i)/2] );
            i = (i)/2;
        }
    }
    void heapFix(int i){
        int largest;
        int l = 2 * i +1;
        int r = 2 * i +2;
        if(l <= currentSize && heap[l] > heap[i]){
            largest = l;
        }else {
            largest=i;
        }
        if(r <= currentSize && heap[r] > heap[i]){
            largest = r;
        }
        if( largest != i ){
            swap(heap[i], heap[largest]);
            heapFix(largest);
        }
    }
    void searchNode(int value){
        bool found = false;
        int i =0;
        while(!found){
            if(currentSize ==0){
                found = true;
                return;
            } else{
                if(heap[i] == value){
                    found = true;
                    return;
                }
                i++;
            }
        }
    }
    void deleteNode(){
        int lastElement = heap[currentSize-1];
        heap[0] = lastElement;
        heap[currentSize-1];
        currentSize--;
        heapFix(1);
    }

    void printHeap()
    {
        for(int i=0; i < currentSize; i++)
        {
            cout<< heap[i] << " " << endl;
        }
    }
};
