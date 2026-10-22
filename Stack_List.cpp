
#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    list<int> l;

public:
    bool isEmpty() {
        return l.empty();
    }

    void push(int x) {
        l.push_back(x);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }

        int x = l.back();
        l.pop_back();
        return x;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }

        return l.back();
    }

    int size() {
        return (int)l.size();
    }

    void display() {
        cout << "Stack (tu day den dinh): ";

        for (int x : l)
            cout << x << " ";

        cout << endl;
    }
};

int main() {
    Stack s;

    while (1) {
        cout << "\n========== STACK - LIST ==========\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Kiem tra rong\n";
        cout << "6. In Stack\n";
        cout << "0. Thoat\n";

        int lc;
        cout << "Nhap lua chon: ";
        cin >> lc;

        if (lc == 1) {
            int x;
            cout << "Nhap gia tri: ";
            cin >> x;
            s.push(x);
        }
        else if (lc == 2) {
            if (!s.isEmpty())
                cout << "Gia tri lay ra: " << s.pop() << endl;
            else
                s.pop();
        }
        else if (lc == 3) {
            if (!s.isEmpty())
                cout << "Dinh Stack: " << s.top() << endl;
            else
                s.top();
        }
        else if (lc == 4) {
            cout << "So phan tu: " << s.size() << endl;
        }
        else if (lc == 5) {
            if (s.isEmpty())
                cout << "Stack rong\n";
            else
                cout << "Stack khong rong\n";
        }
        else if (lc == 6) {
            s.display();
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

