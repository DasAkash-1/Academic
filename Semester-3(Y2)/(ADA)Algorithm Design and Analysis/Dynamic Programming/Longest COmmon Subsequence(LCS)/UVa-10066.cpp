#include <bits/stdc++.h>
using namespace std;
#define op() ios_base::sync_with_stdio(0);cin.tie(0);
#define mem(a, b) memset(a, b, sizeof(a));
#define vii vector <int>

const int N = 123;
int dp[N][N];

int lcs (vii &a, vii &b) {
    int n = a.size(), m = b.size();
    for (int i = 0; i < m; i++) dp[0][i] = 0;
    for (int i = 0; i < n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main() {
    op();
    int n, m;
    int tc = 1, nl = 0;
    while (cin >> n >> m and (n != 0 and m != 0)) {
        vii a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        cout << "Twin Towers #" << tc++ << endl;
        cout << "Number of Tiles : " << lcs(a, b) << endl;
        cout << endl;
    }
}
