#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define sz 100000

vector <int> a(sz);
vector <int> ans(sz);

void heapify(int i, int n) {
    int largest = i;
    int l = 2 * i + 1, r = 2* i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[largest], a[i]);
        heapify(largest, n);
    }
}

void heap_sort(int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(0, i);
    }
}

void merge(int l, int r) {
    int mid = l + (r - l) / 2;
    int i1 = l, i2 = mid + 1, j = l;

    while (i1 <= mid && i2 <= r) {
        if (a[i1] < a[i2]) ans[j] = a[i1++];
        else ans[j] = a[i2++];
        j++;
    }
    while (i1 <= mid) {
        ans[j++] = a[i1++];
    }
    while (i2 <= r) {
        ans[j++] = a[i2++];
    }
    for (int i = l; i <= r; i++) a[i] = ans[i];
}

void merge_sort(int l, int r) {
    if (l == r) return;

    int mid = l + (r - l) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, r);
}

void quick_sort(int l, int r) {
    int i = l, j = r;
    int pivot = a[(l + r) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if (l < j) quick_sort(l, j);
    if (r > i) quick_sort(i, r);
}

int main(){
    //optimize();

    for (int i = 0; i < sz; i++) a[i] = rand();
    vector <int> arr = a;

    for (int i = 0; i < sz; i++) a[i] = arr[i];
    auto start1 = clock();
    heap_sort(sz);
    auto end1 = clock();
    double m_t = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Heap Sort -> " << m_t << " seconds" << endl << endl;

    for (int i = 0; i < sz; i++) a[i] = arr[i];
    auto start = clock();
    merge_sort(0, sz - 1);
    auto end = clock();
    double h_t = double(end - start) / CLOCKS_PER_SEC;
    cout << "Merge Sort -> " << h_t << " seconds" << endl << endl;

    for (int i = 0; i < sz; i++) a[i] = arr[i];
    auto start3 = clock();
    quick_sort(0, sz - 1);
    auto end3 = clock();
    double q_t = double(end3 - start3) / CLOCKS_PER_SEC;
    cout << "Quick Sort -> " << q_t << " seconds" << endl;
}
