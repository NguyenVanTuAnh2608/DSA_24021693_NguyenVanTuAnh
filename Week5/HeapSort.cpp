
#include <iostream>
#include <algorithm>
using namespace std;

void Sink(int* a, int n, int k) {
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

void buildHeap(int* a, int n) {
    for (int k = n / 2; k >= 1; k--) {
        Sink(a, n, k);
    }
}

void heapSort(int* a, int n) {
    buildHeap(a, n);

    while (n > 1) {
        swap(a[1], a[n]);
        n--;
        Sink(a, n, 1);
    }
}

int main() {
    int a[] = {0, 4, 10, 3, 5, 1};
    int n = 5;

    heapSort(a, n);

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
