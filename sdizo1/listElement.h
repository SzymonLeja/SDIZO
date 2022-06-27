template<class T>
class ListElement
{
public:
    T value;
    //wskaznik wskazujacy na poprzedni element listy
    ListElement<T> *previous;
    //wskaznik wskazujacy na kolejny element listy
    ListElement<T> *next;
    //konstruktor elementu listy, na sam poczatek wskaznikom przypisywany jest nullptr
    ListElement(T t)
    {
        value= t;
        previous=NULL;
        next=NULL;
    }

};