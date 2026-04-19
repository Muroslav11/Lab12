#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void create(Elem*& first, Elem*& last)
{
    int n;
    cout << "Enter number of elements: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        Elem* tmp = new Elem;
        cout << "info = "; cin >> tmp->info;
        tmp->link = NULL;
        if (first == NULL)
            first = tmp;
        else
            last->link = tmp;
        last = tmp;
    }
}

void print(Elem* L)
{
    while (L != NULL)
    {
        cout << setw(4) << L->info;
        L = L->link; 
    }
    cout << endl;
}

void removeAfterValue(Elem* first, Info value)
{
    Elem* L = first;
    while (L != NULL)
    {
        if (L->info == value && L->link != NULL)
        {
            Elem* tmp = L->link;  
            L->link = tmp->link;    
            delete tmp;
        }
        L = L->link;
    }
}

void clear(Elem*& first)
{
    while (first != NULL)
    {
        Elem* tmp = first->link;
        delete first;
        first = tmp;
    }
}

int main()
{
    Elem* first = NULL;
    Elem* last = NULL;

    create(first, last);
    cout << "Original list: " << endl;
    print(first);

    Info val;
    cout << "Enter value to find: "; cin >> val;

    removeAfterValue(first, val);

    cout << "Modified list: " << endl;
    print(first);

    clear(first);
    return 0;
}