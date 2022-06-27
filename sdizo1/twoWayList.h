#pragma once
#include<iostream>
#include "listElement.h"
//klasa bedaca wlasna implementacja listy
template<class T>
class TwoWayList{
    // wskaznik na poczatek i koniec listy
private:
    ListElement<T> *head, *end;
    int size;
public:
    TwoWayList();
    //destruktor
    ~TwoWayList();
    /*
        drukowanie zawartosci listy od poczatku do konca
    */
    void printFromFront();

    /*
         drukowanie zawartosci listy od konca do poczatku
    */
    void printFromBack();

    //dodaj za konkretnym indexem
    void addToCertainIndex(int id, T t);
    void addToEnd(T t);
    void addToBeggining(T t);
    void deleteFromBeggining();
    void deleteFromEnd();
    void deleteAtCertainIndex(int index);

    //wyszukiwanie wartosci po indexie
    T returnValueAtIndex(int index);
    void searchValue(int value);
};