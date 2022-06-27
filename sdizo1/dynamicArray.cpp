//#include "dynamicArray.h"
//
//Array::Array(int amount)
//{
//    size=amount;
//    array=new int[size];
//}
//Array::~Array()
//{
//    delete array;
//    array= nullptr;
//    size=0;
//}
//void Array::addToArray(int element)
//{
//    int* temp=new int[++size];
//    if(array!=NULL)
//    {
//        for(int i=0; i<size; i++)
//        {
//            temp[i]=array[i];
//        }
//        temp[size-1]=element;
//    }
//    else{
//        temp[0]=element;
//    }
//    array=temp;
//    size++;
//}
//
//void Array::printArray()
//{
//    std::cout<<"{";
//    for(int i=0; i<size; i++)
//        std::cout<< array[i] << " ";
//
//    std::cout<<"}";
//}
//
//void Array::deleteFromArray(int index)
//{
//    int*temp=new int[size-1];
//    int iterator=0;
//    for(int i=0; i<size; i++)
//    {
//        if(index!=i)
//        {
//            temp[iterator]=array[i];
//            iterator++;
//        }
//    }
//    array=temp;
//    size--;
//}
//
//bool Array::findValue(int value)
//{
//    for(int i=0; i<size; i++)
//    {
//        if(array[i]==value)
//        {
//            return true;
//        }
//    }
//    return false;
//}
