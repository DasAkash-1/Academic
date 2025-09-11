#include <bits/stdc++.h>
using namespace std;
#define op() ios_base::sync_with_stdio(0);cin.tie(0);
#define vii vector<int>

const int N = 100123;
int A[N], L[N], Lis[N], lis_len;
vii s;

int lis(vii &a) {
    int n = a.size();
    A[0] = -1e9;
    for (int i = 1; i <= n; i++) A[i] = 1e9;
    int k = 0;

    for (int i = 0; i < n; i++) {
        int l = 0, r = k;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[i] > A[mid]) l = mid + 1;
            else r = mid - 1;
        }
        A[l] = a[i];
        L[i] = l;
        k = max(k, l);
    }
    return k;
}

void Lis_prnt() {
    int len = lis_len, n = s.size();

    int i = 1;
    for (int j = 0; j < n; j++) {
        if (L[j] == len) i = j;
    }

    int top = L[i] - 1;
    Lis[top--] = s[i];

    for (int j = i - 1; j >= 0; j--) {
        if (L[j] == L[i] - 1 && s[j] < s[i]) {
            Lis[top--] = s[j];
            i = j;
        }
    }

    for (int i = 0; i < len; i++) cout << Lis[i] << endl;
}

int main() {
    op();
    int n;
    while (cin >> n) {
        s.push_back(n);
    }
    lis_len = lis(s);
    cout << lis_len << endl << '-' << endl;
    Lis_prnt();
}
