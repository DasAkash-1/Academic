#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define mem(a, b) memset(a, b, sizeof(a))

const int N = 33, M = 1123;
int dp[N][M], d[N], d1[N], v[N], t, w, n; 
bool taken[N][M], mark[N];

int go(int i, int cur) {
    if (i == n || cur == t) return 0;
    if (dp[i][cur] != -1) return dp[i][cur];

    int notake = go(i + 1, cur), take = 0;
    if (cur + (d[i] * 3 * w) <= t) take = go(i + 1, cur + (d[i] * 3 * w)) + v[i];

    taken[i][cur] = (take > notake);
    return dp[i][cur] = max(notake, take);
}

int main(){
    optimize();

    int nl = 0;
    while (cin >> t >> w) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> d[i] >> v[i];

        mem(dp, -1);
        mem(taken, 0);
        mem(mark, 0);

        if (nl == 1) cout << endl; nl = 1;
        cout << go(0, 0) << endl;
        
        int i = 0, cnt = 0, cur = 0;
        while (i < n) {
            if (taken[i][cur]) {
                mark[i] = 1;
                cnt++;
                cur += d[i] * 3 * w;
            }
            i++;
        }
        cout << cnt << endl;
        for (int i = 0; i < n; i++) {
            if (mark[i]) cout << d[i] << " " << v[i] << endl;
        }
    }
}
