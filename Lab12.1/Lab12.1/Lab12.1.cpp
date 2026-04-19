#include <iostream>

using namespace std;

struct Elem
{
    Elem* link1, * link2;
    int info;
};

int main()
{
    Elem* v1 = new Elem;
    Elem* v2 = new Elem;
    Elem* v3 = new Elem;
    Elem* v4 = new Elem;

    v1->info = 1;
    v2->info = 2;
    v3->info = 3;
    v4->info = 4;

    v1->link1 = v2;
    v1->link2 = v4;

    v2->link1 = v1;
    v2->link2 = v3;

    v3->link1 = v2;
    v3->link2 = v4;

    v4->link1 = v2;
    v4->link2 = NULL; 

    Elem* p = v1;

    cout << "Structure built successfully." << endl;
    cout << "p->info: " << p->info << endl;
    cout << "p->link1->info (v2): " << p->link1->info << endl;
    cout << "p->link2->info (v4): " << p->link2->info << endl;

    delete v1;
    delete v2;
    delete v3;
    delete v4;

    cout << "Structure destroyed. Memory cleared." << endl;

    return 0;
}