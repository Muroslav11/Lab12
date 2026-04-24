#include <iostream>
#include <Windows.h>

using namespace std;

// Структура вузла двонаправленого списку
struct Node {
    int info;
    Node* prev;
    Node* next;
};

// --- 1. СТВОРЕННЯ ВУЗЛА ---
Node* createNode(int value) {
    Node* newNode = new Node; // 1: Виділення динамічної пам'яті під новий вузол
    newNode->info = value;    // 2: Запис інформаційного значення
    newNode->prev = nullptr;  // 3: Ініціалізація вказівника "назад"
    newNode->next = nullptr;  // 4: Ініціалізація вказівника "вперед"
    return newNode;
}

// --- 2. ДОДАВАННЯ В КІНЕЦЬ ---
void pushBack(Node*& head, Node*& tail, int value) {
    Node* newNode = createNode(value); // 5: Створення нового елемента 
    if (head == nullptr) {             // 6: Перевірка, чи список порожній
        head = tail = newNode;         // 7: Перший вузол стає одночасно головою і хвостом
        return;
    }
    tail->next = newNode;              // 8: Встановлення прямого зв'язку від поточного хвоста
    newNode->prev = tail;              // 9: Встановлення зворотного зв'язку від нового вузла
    tail = newNode;                    // 10: Перенесення покажчика хвоста на новий останній вузол
}

// --- 3. ПОШУК ЕЛЕМЕНТА В СПИСКУ ---
bool isElementInList(Node* head, int value) {
    Node* curr = head;                 // 11: Встановлення "бігунка" на початок списку
    while (curr != nullptr) {          // 12: Цикл до кінця списку
        if (curr->info == value)       // 13: Перевірка на збіг значень
            return true;               // 14: Елемент знайдено
        curr = curr->next;             // 15: Перехід до наступного елемента
    }
    return false;                      // 16: Елемент не знайдено після перегляду всього списку
}

// --- 4. ПЕРЕВІРКА ВХОДЖЕННЯ L1 В L2 ---
bool areAllElementsContained(Node* L1, Node* L2) {
    if (L1 == nullptr) return true;    // 17: Порожній L1 формально входить у будь-який L2

    Node* curr1 = L1;                  // 18: Починаємо з першого елемента L1
    while (curr1 != nullptr) {         // 19: Для кожного вузла в L1...
        // 20: Виклик підпрограми пошуку для поточного значення L1 у списку L2
        if (!isElementInList(L2, curr1->info)) {
            return false;              // 21: Якщо хоча б одного елемента немає в L2 — повертаємо false
        }
        curr1 = curr1->next;           // 22: Перехід до наступного елемента в L1
    }
    return true;                       // 23: Усі елементи пройшли перевірку
}

// --- 5. ВИВІД СПИСКУ ---
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->info << " ";
        curr = curr->next;
    }
    cout << endl;
}

// --- 6. ОЧИЩЕННЯ ПАМ'ЯТІ ---
void freeList(Node*& head, Node*& tail) {
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = tail = nullptr;
}

#ifndef UNIT_TESTING
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Node* L1_head = nullptr; Node* L1_tail = nullptr; // 24: Ініціалізація порожнього списку L1
    Node* L2_head = nullptr; Node* L2_tail = nullptr; // 25: Ініціалізація порожнього списку L2

    // 26: Формування списку L2 (основний список)
    int val2[] = { 10, 20, 30, 40, 50 };
    for (int v : val2) pushBack(L2_head, L2_tail, v);

    // 27: Формування списку L1 (елементи для перевірки)
    int val1[] = { 40, 10, 30 };
    for (int v : val1) pushBack(L1_head, L1_tail, v);

    cout << "Список L1: "; printList(L1_head);
    cout << "Список L2: "; printList(L2_head);

    // 28: Виклик логічної функції та вивід результату
    if (areAllElementsContained(L1_head, L2_head))
        cout << "Результат: Всі елементи L1 входять у список L2" << endl;
    else
        cout << "Результат: НЕ всі елементи L1 входять у список L2" << endl;

    // 29: Звільнення ресурсів
    freeList(L1_head, L1_tail);
    freeList(L2_head, L2_tail);

    return 0;
}
#endif