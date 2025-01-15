#include <iostream>
#include <string>
using namespace std;

const int HeapSize = 100;

typedef struct {
    string name;  
    int priority; 
} heapElement;

heapElement heap[HeapSize]; 
int heapCount = 0;          

void printHeap() {
    if (heapCount == 0) {
        cout << "堆積目前為空。" << endl;
        return;
    }
    cout << "堆積內容如下：" << endl;
    for (int i = 1; i <= heapCount; i++) {
        cout << i << ". " << heap[i].name << " (優先權: " << heap[i].priority << ")" << endl;
    }
}


void insert(string name, int priority) {
    if (heapCount == HeapSize - 1) {
        cout << "堆積已滿，無法新增元素。" << endl;
        return;
    }

    heapElement newElement = {name, priority};
    int i = ++heapCount;

    while (i > 1 && newElement.priority > heap[i / 2].priority) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = newElement;

    cout << "新增成功：" << name << "，優先權為 " << priority << endl;
}


void deleteMax() {
    if (heapCount == 0) {
        cout << "堆積目前為空，無法刪除。" << endl;
        return;
    }

    cout << "刪除成功：" << heap[1].name << "，優先權為 " << heap[1].priority << endl;

    heap[1] = heap[heapCount--];
    int parent = 1, child = 2;

    while (child <= heapCount) {
        if (child < heapCount && heap[child].priority < heap[child + 1].priority) {
            child++;
        }
        if (heap[parent].priority >= heap[child].priority) {
            break;
        }
        swap(heap[parent], heap[child]);
        parent = child;
        child *= 2;
    }
}


void menu() {
    int choice;
    do {
        cout << "\n可執行的堆積 (Heap) 運算如下：" << endl;
        cout << "1. 新增工作名稱與其優先權至堆積" << endl;
        cout << "2. 自堆積刪除優先權最高的工作" << endl;
        cout << "3. 列印整個堆積的工作名稱與優先權" << endl;
        cout << "4. 結束程式" << endl;
        cout << "請輸入要執行的選項：";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int priority;
            cout << "請輸入工作名稱：";
            cin >> name;
            cout << "請輸入工作優先權：";
            cin >> priority;
            insert(name, priority);
            break;
        }
        case 2:
            deleteMax();
            break;
        case 3:
            printHeap();
            break;
        case 4:
            cout << "程式結束，感謝使用！" << endl;
            break;
        default:
            cout << "無效的選項，請重新輸入。" << endl;
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}