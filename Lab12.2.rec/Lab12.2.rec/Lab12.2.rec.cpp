#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void createRecursive(Elem*& first, Elem*& last, int n)
{
    if (n == 0) return;

    Elem* tmp = new Elem;
    cout << "info = "; cin >> tmp->info;
    tmp->link = NULL;

    if (first == NULL)
        first = tmp;
    else
        last->link = tmp;
    last = tmp;

    createRecursive(first, last, n - 1);
}

void printRecursive(Elem* L)
{
    if (L == NULL)
    {
        cout << endl;
        return;
    }
    cout << setw(4) << L->info;
    printRecursive(L->link);
}

void removeAfterRecursive(Elem* L, Info value)
{
    if (L == NULL) return;

    if (L->info == value && L->link != NULL)
    {
        Elem* tmp = L->link;
        L->link = tmp->link;
        delete tmp;
        removeAfterRecursive(L->link, value);
    }
    else
    {
        removeAfterRecursive(L->link, value);
    }
}

void clearRecursive(Elem*& first)
{
    if (first == NULL) return;
    Elem* next = first->link;
    delete first;
    first = next;
    clearRecursive(first);
}

int main()
{
    Elem* first = NULL;
    Elem* last = NULL;
    int n;

    cout << "n = "; cin >> n;
    createRecursive(first, last, n);
    printRecursive(first);

    Info val;
    cout << "value = "; cin >> val;
    removeAfterRecursive(first, val);
    printRecursive(first);

    clearRecursive(first);
    return 0;
}