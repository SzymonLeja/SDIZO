#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include "twoWayList.cpp"
#include "heap.h"
#include "bst.h"
#include "dynArray.h"

#include <ratio>
#include <chrono>

using namespace std;

void generateFile(int size) {
    srand(time(NULL));
    ofstream myFile_Handler;
    // File Open
    myFile_Handler.open("data.txt");

    for (int i = 0; i < size + 1; i++) {
        if (i == 0) {
            myFile_Handler << size << endl;
        } else {
            myFile_Handler << rand() % size << endl;
        }
    }
    //myFile_Handler << "This is a sample test File. " << endl;
    // myFile_Handler << "This is the second line of the file. " << endl;

    // File Close
    myFile_Handler.close();
}

int *readFile() {
    std::ifstream infile("data.txt");
    std::string line;
    bool trus = true;
    int *tab;
    int i = 0;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        int a;
        if (!(iss >> a)) { break; } // error

        if (!trus) {
            tab[i] = a;
            i++;
        } else {
            trus = false;
            tab = new int[a];
        }

    }
    return tab;
}
int main() {
    int size;
    cout<<"Wpisz wielkosc danych wejsciowych" << endl;
    cin>>size;
//    double avgTime[17] = {0};
    int dataSizes[1] = {size};
//    int testcase= 5;
    for (int i = 0; i < sizeof(dataSizes)/sizeof(dataSizes[0]); i++) {
        int k=0;
        cout << "\n---- Size[" << dataSizes[i] << "] ----" << endl;
        chrono::high_resolution_clock::time_point t1,t2;
        chrono::duration<double> elapsed;
        generateFile(dataSizes[i]);
        int *dataArray = readFile();
        // dynamic array
        cout << "\nDynamic Array: \n" << endl;
        Array array = Array();
        //Adding to start
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            array.addToStart(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Adding to start : " << 1000 * elapsed.count() << " ms" << endl;
        //Remove from start
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            array.removeFromStart();
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Removing from start : " << 1000 * elapsed.count() << " ms" << endl;
        //Add to end
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            array.addToEnd(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Adding to end : " << 1000 * elapsed.count() << " ms" << endl;
        //Search value
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            array.findValue(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        //Remove from end
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            array.removeFromEnd();
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Removing from end : " << 1000 * elapsed.count() << " ms" << endl;
        //Add to index
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            array.addToIndex(dataArray[j], j / 2);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Add to the middle : " << 1000 * elapsed.count() << " ms" << endl;
        //Remove from index
        t1 = chrono::high_resolution_clock::now();
        for (int j = dataSizes[i] - 1; j > 0; j--) {
            array.removeFromIndex(j / 2);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Removing from the middle : " << 1000 * elapsed.count() << " ms" << endl;
        cout << "\nTwo Way List: \n" << endl;


        ////TwoWayList
        TwoWayList<int> list = TwoWayList<int>();

        //add to start
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            list.addToBeggining(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Adding to start : " << 1000 * elapsed.count() << " ms" << endl;
        //search
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            list.searchValue(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Searching for value : " << 1000 * elapsed.count() << " ms" << endl;
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            list.deleteFromBeggining();
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Removing from start : " << 1000 * elapsed.count() << " ms" << endl;
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            list.addToEnd(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Adding to end : " << 1000 * elapsed.count() << " ms" << endl;
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            list.deleteFromEnd();
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Removing from end : " << 1000 * elapsed.count() << " ms" << endl;
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            list.addToCertainIndex(j / 2, dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Adding to middle : " << 1000 * elapsed.count() << " ms" << endl;
        t1 = chrono::high_resolution_clock::now();
        for (int j = dataSizes[i] - 1; j > 0; j--) {
            list.deleteAtCertainIndex(j / 2);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Removing from middle : " << 1000 * elapsed.count() << " ms" << endl;
        cout << "\nHeap: \n" << endl;
        ////Heap

        Heap heap = Heap(dataSizes[i]);
//        t1 = chrono::high_resolution_clock::now();
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            heap.insertNode(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Adding to the heap : " << elapsed.count() * 1000 << " ms" << endl;

        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            heap.searchNode(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Searching from the heap : " << 1000 * elapsed.count() << " ms" << endl;
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            heap.deleteNode();
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Removing from the heap : " << 1000 * elapsed.count() << " ms" << endl;
        ////Bst
        cout<<"\nBST:\n"<<endl;
        bst binarySearchTree = bst();
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            binarySearchTree.insertToTree(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Adding to the BST : " << 1000 * elapsed.count() << " ms" << endl;
        node *p;
        p=binarySearchTree.root->left;
        while(p->left != nullptr){
            if(p->key > binarySearchTree.root->key){
                cout<<"BST IS BROKEN!"<<endl;
            }
            p=p->left;
        }
        p=binarySearchTree.root->right;
        while(p->right != nullptr){
            if(p->key < binarySearchTree.root->key){
                cout<<"BST IS BROKEN!"<<endl;
            }
            p=p->right;
        }
        t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSizes[i]; j++) {
            binarySearchTree.searchTree(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Search for the BST : " << 1000 * elapsed.count() << " ms" << endl;
        t1 = chrono::high_resolution_clock::now();
        for (int j = dataSizes[i] - 2; j > 0; j--) {
            binarySearchTree.deleteKey(dataArray[j]);
        }
        t2 = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(t2-t1);
//        avgTime[k] = (avgTime[k] + 1000 * elapsed.count());
//        k++;
        cout << "Removing from the BST : " << 1000 * elapsed.count() << " ms" << endl;

    }
//    for(int i=0;i<17;i++){
//        cout<<"avg: " << avgTime[i]/(testcase-1) << endl;
//    }
    int exit;
    cout<<"\n\nWpisz 0 i nacisnij enter aby wyjsc" << endl;
    cin>>exit;
    return 0;
}