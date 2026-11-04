
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Queue {
private:
    Node *head;
    Node *tail;
    int n;

public:
    Queue() {
        head = NULL;
        tail = NULL;
        n = 0;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(int x) {
        Node *tmp = new Node;
        tmp->data = x;
        tmp->next = NULL;

        if (isEmpty()) {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tmp;
        }

        n++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return -1;
        }

        Node *tmp = head;
        int x = tmp->data;

        head = head->next;

        if (head == NULL)
            tail = NULL;

        delete tmp;
        n--;

        return x;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return -1;
        }

        return head->data;
    }

    int size() {
        return n;
    }

    void display() {
        cout << "Queue (dau den cuoi): ";

        Node *p = head;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }

    ~Queue() {
        while (head != NULL) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }

        tail = NULL;
    }
};

int main() {
    Queue q;

    while (1) {
        cout << "\n====== QUEUE - LINKED LIST ======\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Size\n";
        cout << "5. Kiem tra rong\n";
        cout << "6. In Queue\n";
        cout << "0. Thoat\n";

        int lc;
        cout << "Nhap lua chon: ";
        cin >> lc;

        if (lc == 1) {
            int x;
            cout << "Nhap gia tri: ";
            cin >> x;
            q.enqueue(x);
        }
        else if (lc == 2) {
            if (!q.isEmpty())
                cout << "Gia tri lay ra: " << q.dequeue() << endl;
            else
                q.dequeue();
        }
        else if (lc == 3) {
            if (!q.isEmpty())
                cout << "Phan tu dau Queue: " << q.front() << endl;
            else
                q.front();
        }
        else if (lc == 4) {
            cout << "So phan tu: " << q.size() << endl;
        }
        else if (lc == 5) {
            if (q.isEmpty())
                cout << "Queue rong\n";
            else
                cout << "Queue khong rong\n";
        }
        else if (lc == 6) {
            q.display();
        }
        else if (lc == 0) {
            break;
        }
        else {
            cout << "Lua chon khong hop le!\n";
        }
    }

    return 0;
}

