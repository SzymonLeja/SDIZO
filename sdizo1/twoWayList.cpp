//#include "TwoWayList.hpp"
#include<iostream>

using namespace std;

//klasa zawierajaca element listy
template<class T>
class ListElement {
public:
    T value;
    //wskaznik wskazujacy na poprzedni element listy
    ListElement<T> *previous;
    //wskaznik wskazujacy na kolejny element listy
    ListElement<T> *next;

    //konstruktor elementu listy, na sam poczatek wskaznikom przypisywany jest nullptr
    ListElement(T t) {
        value = t;
        previous = NULL;
        next = NULL;
    }

};

//klasa bedaca wlasna implementacja listy
template<class T>
class TwoWayList {
    // wskaznik na poczatek i koniec listy
private:
    ListElement<T> *head, *end;
    int size;
    /*
        konstruktor listy, przyjmuje na wejsciu wartosc do pierwszego elementu listy
    */
public:
    TwoWayList() {
        head = nullptr;
        end = head;
        size = 0;
    }

    ~TwoWayList() {
        while (head != end) {
            head = head->next;
            delete head->previous;
        }
        delete end;
    }

    /*
        drukowanie zawartosci listy od poczatku do konca
    */
    void printFromFront() {
        ListElement<T> *temporary = head;
        cout << "{" << endl;
        while (temporary) {
            cout << temporary->value << " ";
            temporary = temporary->next;
        }
        cout << endl << "}" << endl;
    }

    /*
         drukowanie zawartosci listy od konca do poczatku
    */
    void printFromBack() {
        ListElement<T> *temporary = end;
        cout << "{" << endl;
        while (temporary) {
            cout << temporary->value << " ";
            temporary = temporary->previous;
        }
        cout << endl << "}" << endl;
    }

    /*
     metoda dodajaca element na poczatek listy
    */
    void addToBeggining(T t) {
        //jezeli lista jest pusta, przypisz nowy element jako poczatek i koniec listy
        if (size == 0) {
            head = new ListElement<T>(t);
            end = head;
        }
            // jezeli lista nie jest pusta, utworz nowy element i przesun poczatkowy element aby moc nowy element
            // tam wrzucic
        else {
            ListElement<T> *temp = new ListElement<T>(t);
            head->previous = temp;
            temp->next = head;
            head = temp;
        }
        size++;
    }

    /*
      metoda dodajaca element na koniec listy
    */
    void addToEnd(T t) {
        // analogiczny przypadek jak przy dodawaniu na poczatku listy
        if (size == 0) {
            head = new ListElement<T>(t);
            end = head;
        } else {
            ListElement<T> *temp = new ListElement<T>(t);
            end->next = temp;
            temp->previous = end;
            end = temp;
        }
        size++;
    }
    //dodaj za konkretnym indexem

    void addToCertainIndex(int id, T t) {
        if (id > size || id < 0) {
            return;
        }
        if (id == 0) {
            addToBeggining(t);
            return;
        }
        if (id == size - 1) {
            addToEnd(t);
            return;
        }
        ListElement<T> *temp = head->next;
        ListElement<T> *temp2;
        int iterator = 1;
        while (iterator != id) {
            temp = temp->next;
            iterator++;
        }
        temp2 = new ListElement<T>(t);
        temp2->previous = temp->previous;
        temp->previous->next = temp2;
        temp2->next = temp;
        temp->previous = temp2;
        size++;
        return;

    }

    //Usun z poczatku listy
    void deleteFromBeggining() {
        //jezeli lista jest pusta wyrzuc komunikat
        if (size == 0) {
            cout << "Nie mozna usunac z pustej listy";
            return;
        }
            //jezeli lista ma 1 element to usun glowe
        else if (size == 1) {
            delete head;
            //delete end;
        }
            //w innym wypadku zastepujemy glowe jej nastepnikiem
            //a stara glowe usuwamy
        else {
            ListElement<T> *temp = head->next;
            temp->previous = NULL;
            delete head;
            head = temp;
        }
        //zmniejszamy wielkosc o jeden
        size--;
    }

    void deleteFromEnd() {
        //jezeli lista jest pusta wyrzuc komunikat
        if (size == 0) {
            cout << "Nie mozna usunac z pustej listy";
            return;
        }
            // usun koncowke
        else if (size == 1) {
            delete end;
        }
            //w innym wypadku zastepujemy koniec jej poprzednikiem
            //a stary koniec usuwamy
        else {
            ListElement<T> *temp = end->previous;
            temp->next = NULL;
            delete end;
            end = temp;
        }
        size--;
    }

    void deleteAtCertainIndex(int index) {
        //jezeli index jest za duzy lub za maly
        if (index > size - 1 || index < 0) {
            cout << "Index out of bounds";
            return;
        }
        if (index == 0) {
            deleteFromBeggining();
            return;
        }
        if (index == size - 1) {
            deleteFromEnd();
            return;
        }
        ListElement<T> *current;
        current = head;

        int iterator = 0;
        while (index != iterator) {
            current = current->next;
            iterator++;
        }
        current->previous->next = current->next;
        current->next->previous = current->previous;
        delete current;
        size--;


    }

    //wyszukiwanie wartosci po indexie
    T returnValueAtIndex(int index) {
        if (index > size - 1 || index < 0) {
            return NULL;
        }
        ListElement<T> *temp = head;
        int iterator = 0;
        while (index != iterator) {
            temp = temp->next;
            iterator++;
        }
        return temp->value;


    }
    void searchValue(int value){
        bool found = false;
        ListElement<T> *temp = head;
        while(!found){
            if(temp != nullptr){
                if(temp->value == value){
                    found = true;
                    return;
                } else {
                    temp = temp->next;
                }
            } else {
                found = true;
                return;
            }
        }

    }

};


//int main() {
//    TwoWayList<int> lista = TwoWayList<int>();
//    lista.addToBeggining(1);
//    lista.addToEnd(2);
//    lista.addToEnd(3);
//    lista.addToEnd(4);
//    lista.addToEnd(5);
//    lista.printFromFront();
//    //cout << lista.maxSize;
//    lista.deleteAtCertainIndex(1);
//    lista.addToCertainIndex(2, 1023);
//
//    //lista.deleteFromBeggining();
//    //lista.deleteFromEnd();
//    lista.printFromFront();
//    lista.printFromBack();
//    //cout<< lista.returnValueAtIndex(2);
//    return 0;
//}

