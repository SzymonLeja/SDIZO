#pragma once
#include<iostream>

class Array
{
public:
    int size;
    int *array;

    Array(int amount);
    ~Array();
    void addToArray(int element);
    void printArray();
    void deleteFromArray(int index);
    bool findValue(int value);
};