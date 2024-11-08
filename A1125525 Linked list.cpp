#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void display() {
    if (head == nullptr) {
        cout << "list內現在為空!!!" << endl;
        return;
    }
    Node* temp = head;
    cout << "list內有: ";
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void append(int num) {
    Node* new_one = new Node;   /* 動態配置一個新node */
    new_one->data = num;
    new_one->next = nullptr;    /* 最後一個的後面為NULL */

    if (head == nullptr) {
        head = new_one;
        return;
    }

    Node* last = head;          /* 記得要用另一個pointer代替head */
    while (last->next != nullptr) {
        last = last->next;
    }
    /* 最後一個節點後面必定為NULL */
    last->next = new_one;       /* 接到最後面 */
}

void insert(int num, int pos) {
    Node* new_one = new Node;   /* 動態配置一個新node */
    new_one->data = num;
    new_one->next = nullptr;

    if (pos == 0) {
        new_one->next = head;
        head = new_one;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "位置無效" << endl;
        delete new_one;
        return;
    }
    new_one->next = temp->next;
    temp->next = new_one;
}

void deleteLast() {
    if (head == nullptr) {
        cout << "list內現在為空!!!" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteAt(int pos) {
    if (head == nullptr) {
        cout << "list內現在為空!!!" << endl;
        return;
    }
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "位置無效" << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    int choice, data, position;

    while (true) {
        cout << "A1125525 Linked List使用介面" << endl;
        cout << "1. 列出全部資料" << endl;
        cout << "2. 新增一筆資料到最後面" << endl;
        cout << "3. 新增一筆資料到指定位置" << endl;
        cout << "4. 刪除最後面的資料" << endl;
        cout << "5. 刪除指定位置的資料" << endl;
        cout << "6. 反轉list" << endl;
        cout << "0. 離開" << endl;
        cout << "選擇操作 : ";
        cin >> choice;

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                cout << "請輸入要新增的資料: ";
                cin >> data;
                append(data);
                break;
            case 3:
                cout << "請輸入要插入的位置: ";
                cin >> position;
                cout << "請輸入要新增的資料: ";
                cin >> data;
                insert(data, position);
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                cout << "請輸入要刪除的位置: ";
                cin >> position;
                deleteAt(position);
                break;
            case 6:
                reverse();
                break;
            case 0:
                return 0;
            default:
                cout << "無效的選擇" << endl;
        }
    }

    return 0;
}