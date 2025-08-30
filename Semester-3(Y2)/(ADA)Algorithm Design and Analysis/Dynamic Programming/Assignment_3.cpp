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

ll mx = 1e9, mx_c = 10000;

int main(){
    optimize();

    //Sieve();

    int t; cin >> t;
    while (t--) {
        ll price, n; cin >> price >> n;
        vll v(n), dp(mx_c, mx);

        for (int i = 0; i < n; i++) cin >> v[i];

        ll mn = 0, amt = 0;
        dp[0] = 0;
        for (int i = 1; i <= mx_c; i++) {
            for (int j = 0; j < n; j++) {
                if (i - v[j] >= 0 && dp[i - v[j]] != mx) dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
        for (int i = price; i <= mx_c; i++) {
        if (dp[i] != mx && mn == 0) {
                amt = i;
                mn = dp[i];
            }
        }
        cout << amt << " " << mn << endl;
    }
}
