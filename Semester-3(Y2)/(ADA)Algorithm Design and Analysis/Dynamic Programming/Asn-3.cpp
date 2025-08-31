#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define vi vector <int>
#define vll vector <long long>
#define pii pair<int, int>
#define print_yes cout << "YES" << '\n'
#define print_no cout << "NO" << '\n'
#define srt(v) sort(v.begin(), v.end())

ll mx = 1e5+123, dp[10123], v[123], price, n;

ll go(ll i, ll amt) {
    if (amt == 0) return 0;
    if (i == n) return mx;
    if (dp[amt] != -1) return dp[amt];
    ll ans = mx;
    if (amt - v[i] >= 0) ans = min(go(i + 1, amt), 1 + go(i + 1, amt - v[i]));
    return dp[amt] = ans;
}

int main(){
    optimize();

    int t; cin >> t;
    while (t--) {
        cin >> price >> n;
        for (int i = 0; i < n; i++) cin >> v[i];

        ll mn = 0, amt = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = price; i <= 10000; i++) {
            ll ans = go(0, i);
            if (ans != mx && mn == 0) {
                mn = ans;
                amt = i;
            }
        }
        
        cout << amt << " " << mn << endl;
    }
}
