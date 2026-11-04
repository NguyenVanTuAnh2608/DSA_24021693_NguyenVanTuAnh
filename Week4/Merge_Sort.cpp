
#include <iostream>
using namespace std;

int b[1000];

void merge(int a[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= m)
        b[k++] = a[i++];

    while (j <= r)
        b[k++] = a[j++];

    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int l, int r) {
    if (l >= r)
        return;

    int m = (l + r) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    merge(a, l, m, r);
}

int main() {
    int n, a[1000];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
