//Nguyen Quoc Huy - 22520566
//Lab2 part 2
#include <iostream>
using namespace std;

// Question 1: Khoi tao Queue
struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
    int maxSize;     // Maximum size of the queue
    int currentSize; // Current size of the queue
};

Node *create(int value)
{
    Node *p = new Node;
    p->data = value;
    p->next = NULL;
    return p;
}

void initQueue(Queue &q, int maxSize)
{
    q.front = NULL;
    q.rear = NULL;
    q.maxSize = maxSize;   // Set maximum size
    q.currentSize = 0;     // Initialize current size to 0
}

// Question 2: kiem tra queue rong
bool emptyCheck(Queue q)
{
    return q.front == NULL;
}

// Question 3: kiem tra queue full
bool fullCheck(Queue q)
{
    return q.currentSize >= q.maxSize;
}

// Question 4: day 1 phan tu vao queue
void enqueue(Queue &q, Node *p)
{
    if (fullCheck(q))
    {
        cout << "Queue is full, cannot enqueue!" << endl;
        return;
    }

    if (emptyCheck(q))
    {
        q.front = q.rear = p;
    }
    else
    {
        q.rear->next = p;
        q.rear = p;
    }
    q.currentSize++; // Increment the size of the queue
}

// Question 5: xoa 1 phan tu tu queue
int dequeue(Queue &q)
{
    if (emptyCheck(q))
    {
        return -1;
    }

    Node *p = q.front;
    int value = p->data;
    q.front = q.front->next;
    delete p;

    if (q.front == NULL)
    {
        q.rear = NULL; // If the queue becomes empty
    }

    q.currentSize--; // Decrement the size of the queue
    return value;
}

// Question 6: xuat phan tu FRONT va REAR
void printFrontRear(Queue q)
{
    if (emptyCheck(q))
    {
        cout << "Nothing to print";
        return;
    }
    //neu khong rong thi xuat front va rear
    cout << "Front: " << q.front << " - " << q.front->data << endl;
    cout << "Rear: " << q.rear << " - " << q.rear->data << endl;
}

Node *input(Queue &q)
{
    int x;
    cout << "Gia tri can nhap: ";
    cin >> x;
    Node *p = create(x);
    return p;
}

void printQueue(Queue q)
{
    if (emptyCheck(q))
    {
        return;
    }
    Node *p = q.front;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    Queue q;
    int maxSize;

    cout << "Nhap kich thuoc toi da cua Queue: ";
    cin >> maxSize;

    initQueue(q, maxSize);
    int choose;
    while (true)
    {
        // Tạo menu
        cout << "1. Empty checking" << endl;
        cout << "2. Full checking" << endl;
        cout << "3. Enqueue" << endl;
        cout << "4. Dequeue" << endl;
        cout << "5. Front and Rear" << endl;
        cout << "6. Exit" << endl;
        cout << "Please input your choice: "<<endl;
        cin >> choose;

        switch (choose)
        {
            case 1:
                if (emptyCheck(q))
                {
                    cout << "True"<<endl;
                }
                else
                {
                    cout << "False"<<endl;
                }
                break;
            case 2:
                if (fullCheck(q))
                {
                    cout << "True"<<endl;
                }
                else
                {
                    cout << "False"<<endl;
                }
                break;
            case 3:
            {
                Node *p = input(q);
                enqueue(q, p);
                break;
            }
            case 4:
            {
                int x = dequeue(q);
                if (x < 0)
                {
                    cout << "Queue rong" << endl;
                }
                else
                {
                    cout << "Gia tri duoc xoa: " << x << endl;
                }
                break;
            }
            case 5:
                printFrontRear(q);
                break;
            case 6:
                cout << "Exit" << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le, vui long chon lai!" << endl;
                break;
        }
    }
}
