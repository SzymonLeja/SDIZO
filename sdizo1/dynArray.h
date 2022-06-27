#include <iostream>

using namespace std;

class Array{

private:
    int *array;
    int arraySize;
public:

    Array(){
        array = new int[0];
        arraySize = 0;
    }
    ~Array(){
        free(array);
        array = nullptr;
        arraySize =0;
    }

    void addToStart(int value){
        if(arraySize != 0){
            arraySize++;
            array = (int*)realloc(array, sizeof(int) * arraySize);
            for(int i = arraySize - 2; i >= 0; i--){
                array[i + 1] = array[i];
            }
            array[0] = value;
        } else {
            arraySize++;
            array = (int*)malloc(sizeof(int));
            array[0] = value;
        }
    }

    void addToEnd(int value){
        if(arraySize != 0){
            arraySize++;
            array = (int*)realloc(array, sizeof(int) * arraySize);
            array[arraySize - 1] = value;
        } else{
            arraySize++;
            array = (int*)malloc(sizeof(int));
            array[0] = value;
        }
    }

    void addToIndex(int value, int index){
        if(arraySize != 0){
            arraySize++;
            int tmp[arraySize];
            for(int i = 0; i < arraySize; i++){
                tmp[i] = array[i];
            }
            array = (int*)realloc(array, sizeof(int) * arraySize);
            for(int i = index; i < arraySize; i++){
                array[i + 1] = tmp[i];
            }
            array[index] = value;
        } else {
            arraySize = 1;
            array = (int*)malloc(sizeof(int));
            array[0] = value;
        }
    }


    void removeFromStart(){
        if(arraySize != 0){
            int tmp[arraySize];
            for(int i = 0; i < arraySize; i++){
                tmp[i] = array[i];
            }
            arraySize--;
            array = (int*)realloc(array, sizeof(int) * arraySize);
            for(int i = 0; i < arraySize; i++){
                array[i] = tmp[i + 1];
            }
        } else {
            cout << "Array is empty" << endl;
            return;
        }
    }

    void removeFromEnd(){
        if(arraySize != 0){
            int tmp[arraySize];
            for(int i = 0; i < arraySize; i++){
                tmp[i] = array[i];
            }
            arraySize--;
            array = (int*)realloc(array, sizeof(int) * arraySize);
            for(int i = 0; i < arraySize-1; i++){
                array[i] = tmp[i];
            }
        } else {
            cout << "Array is empty" << endl;
            return;
        }
    }

    void removeFromIndex(int index){
        if(arraySize != 0){
            int tmp[arraySize];
            for(int i = 0; i < arraySize; i++){
                tmp[i] = array[i];
            }
            arraySize--;
            array = (int*)realloc(array, sizeof(int) * arraySize);
            for(int i = index; i < arraySize; i++){
                array[i] = tmp[i + 1];
            }
        } else {
            cout << "Array is empty" << endl;
            return;
        }
    }
    void findValue(int value){
        for(int i = 0; i < arraySize; i++){
            if(array[i] == value){
                return;
            }
        }
        return;
    }

    void showArray(){
        if(arraySize > 0){
            for(int i = 0; i < arraySize; i++){
            cout << array[i] << " ";
            }
            cout << endl;
        }else{
            cout << "Tablica jest pusta" << endl;
        }
    }
};

