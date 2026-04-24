#include <iostream>
#include <Windows.h>

using namespace std;

struct Node {
    int info;
    Node* prev;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node; // 1
    newNode->info = value;    // 2
    newNode->prev = nullptr;  // 3
    newNode->next = nullptr;  // 4
    return newNode;
}

void pushBack(Node*& curr, Node* prevNode, int value, Node*& tail) {
    if (curr == nullptr) {           // 5: Базовий випадок (кінець списку)
        curr = createNode(value);    // 6: Створення вузла
        curr->prev = prevNode;       // 7: Встановлення зворотного зв'язку
        tail = curr;                 // 8: Оновлення вказівника хвоста
        return;
    }
    // 9: Рекурсивний крок вперед, передаємо поточний вузол як "prev" для наступного
    pushBack(curr->next, curr, value, tail);
}

bool isElementInList(Node* curr, int value) {
    if (curr == nullptr)             // 10: Базовий випадок: не знайдено
        return false;
    if (curr->info == value)         // 11: Знайдено
        return true;
    return isElementInList(curr->next, value); // 12: Рекурсія вперед
}

bool areAllElementsContained(Node* L1, Node* L2) {
    if (L1 == nullptr)               // 13: Базовий випадок: L1 порожній/закінчився
        return true;

    // 14: Шукаємо поточне значення L1 у всьому списку L2
    if (!isElementInList(L2, L1->info)) {
        return false;                // 15: Не знайшли — повертаємо false
    }
    // 16: Рекурсія для наступного елемента L1
    return areAllElementsContained(L1->next, L2);
}

void printList(Node* curr) {
    if (curr == nullptr) {           // 17
        cout << endl;
        return;
    }
    cout << curr->info << " ";       // 18
    printList(curr->next);           // 19
}

void freeList(Node*& head, Node*& tail) {
    if (head == nullptr) {           // 20
        tail = nullptr;
        return;
    }
    Node* nextNode = head->next;     // 21
    delete head;                     // 22
    head = nextNode;                 // 23
    freeList(head, tail);            // 24
}

#ifndef UNIT_TESTING
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Node* L1_head = nullptr; Node* L1_tail = nullptr; // 25
    Node* L2_head = nullptr; Node* L2_tail = nullptr; // 26

    // 27: Формування списку L2
    int val2[] = { 10, 20, 30, 40, 50 };
    for (int v : val2) pushBack(L2_head, nullptr, v, L2_tail);

    // 28: Формування списку L1
    int val1[] = { 40, 10, 30 };
    for (int v : val1) pushBack(L1_head, nullptr, v, L1_tail);

    cout << "Список L1: "; printList(L1_head); // 29
    cout << "Список L2: "; printList(L2_head); // 30

    // 31: Логічна перевірка
    if (areAllElementsContained(L1_head, L2_head))
        cout << "Результат: Всі елементи L1 входять у список L2" << endl;
    else
        cout << "Результат: НЕ всі елементи L1 входять у список L2" << endl;

    // 32: Очищення
    freeList(L1_head, L1_tail);
    freeList(L2_head, L2_tail);

    return 0;
}
#endif