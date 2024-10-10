//Nguyen Quoc Huy
//22520566
//Lab2 -P1
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};


struct Stack {
    Node *top;
    int maxSize;     // Giới hạn kích thước tối đa của stack
    int currentSize; // Kích thước hiện tại của stack
};

// Tạo một nút mới với giá trị
Node *create(int value) {
    Node *p = new Node;
    p->data = value;
    p->next = NULL;
    return p;
}

// Khởi tạo Stack
void initStack(Stack &s, int maxSize) {
    s.top = NULL;
    s.maxSize = maxSize;   // Đặt kích thước tối đa của stack
    s.currentSize = 0;     // Khởi tạo số lượng phần tử hiện tại là 0
}


bool emptyCheck(Stack s) {
    return s.top == NULL;
}


bool fullCheck(Stack s) {
    return s.currentSize >= s.maxSize;
}


void push(Stack &s, Node *p) {
    if (fullCheck(s)) {
        cout << "Stack is full, cannot push!" << endl;
        return;
    }
    if (emptyCheck(s)) {
        s.top = p;
    } else {
        p->next = s.top;
        s.top = p;
    }
    s.currentSize++;  // Tăng kích thước hiện tại của stack sau khi thêm phần tử
}


int pop(Stack &s) {
    if (emptyCheck(s)) {
        return -1;  // Trả về -1 nếu stack rỗng
    }
    Node *p = s.top;
    s.top = s.top->next;
    int value = p->data;
    delete p;
    s.currentSize--;  // Giảm kích thước hiện tại của stack sau khi pop
    return value;
}


void printTOP(Stack s) {
    if (emptyCheck(s)) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Top node's value: " << s.top->data << endl;
}

// Nhập dữ liệu cho phần tử mới
Node *input() {
    int x;
    cout << "Nhập giá trị cần thêm vào Stack: ";
    cin >> x;
    return create(x);
}


int main() {
    Stack s;
    int maxSize;

    cout << "Nhập kích thước tối đa của Stack: ";
    cin >> maxSize;
    initStack(s, maxSize);  // Khởi tạo stack với kích thước tối đa

    int choose;
    while (true) {
        
        cout << "1. Empty checking"<<endl;
        cout << "2. Full checking"<<endl;
        cout << "3. Push"<<endl;
        cout << "4. Pop"<<endl;
        cout << "5. Top"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Choose 1-6"<<endl;
        cin >> choose;

        switch (choose) {
            case 1: {
                if (emptyCheck(s)) {
                    cout << "True"<<endl;
                } else {
                    cout << "False"<<endl;
                }
                break;
            }
            case 2: {
                if (fullCheck(s)) {
                    cout << "True"<<endl;
                } else {
                    cout << "False"<<endl;
                }
                break;
            }
            case 3: {
                Node *p = input();
                push(s, p);
                break;
            }
            case 4: {
                int poppedValue = pop(s);
                if (poppedValue == -1) {
                    cout << "Stack rỗng"<<endl;
                } else {
                    cout << "Phần tử đã lấy ra: " << poppedValue << endl;
                }
                break;
            }
            case 5: {
                printTOP(s);
                break;
            }
            case 6: {
                cout << "Exit"<<endl;
                return 0;
            }
            default: {
                cout << "Lựa chọn không hợp lệ, vui lòng chọn lại."<<endl;
                break;
            }
        }
    }
}
