
#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    list<int> l;

public:
    bool isEmpty() {
        return l.empty();
    }

    void enqueue(int x) {
        l.push_back(x);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return -1;
        }

        int x = l.front();
        l.pop_front();
        return x;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return -1;
        }

        return l.front();
    }

    int size() {
        return (int)l.size();
    }

    void display() {
        cout << "Queue (dau den cuoi): ";

        for (int x : l)
            cout << x << " ";

        cout << endl;
    }
};

int main() {
    Queue q;

    while (1) {
        cout << "\n========== QUEUE - LIST ==========\n";
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

