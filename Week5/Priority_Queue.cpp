
#include <iostream>
#include <algorithm>
using namespace std;

class PriorityQueue {
private:
    int a[100];
    int n = 0;

    void Swim(int k) {
        while (k > 1 && a[k / 2] < a[k]) {
            swap(a[k], a[k / 2]);
            k = k / 2;
        }
    }

    void Sink(int k) {
        while (2 * k <= n) {
            int j = 2 * k;

            if (j < n && a[j] < a[j + 1])
                j++;

            if (a[k] >= a[j])
                break;

            swap(a[k], a[j]);
            k = j;
        }
    }

public:

    void insert(int x) {
        if (n == 99) return;

        a[++n] = x;
        Swim(n);
    }

    int top() {
        if (n == 0) {
            cout << "Heap rong!";
            return -1;
        }

        return a[1];
    }

    int delMax() {
        if (n == 0) return -1;

        int max = a[1];

        swap(a[1], a[n]);
        n--;

        Sink(1);

        return max;
    }

    bool empty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    void display() {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";

        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(30);
    pq.insert(50);
    pq.insert(20);
    pq.insert(80);
    pq.insert(10);

    cout << "Heap: ";
    pq.display();

    cout << "Max: " << pq.top() << endl;

    cout << "Xoa: " << pq.delMax() << endl;

    cout << "Heap sau khi xoa: ";
    pq.display();

    return 0;
}
