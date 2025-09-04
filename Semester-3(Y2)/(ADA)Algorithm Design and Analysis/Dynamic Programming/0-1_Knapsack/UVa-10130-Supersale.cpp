/**
    * Task          : 0-1 Knapsack
    * Example       : UVa - 10130 - SuperSale
    * Algo          : DP, 0-1 Knapsack
    * Complexity    : O(n * cap * g) time, O(n * cap) space
    * Author        : Akash Das
    * Last Modified : 03 - 09 - 2025
*/

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

int mx = 1e5+105;
int dp[1005][105], p[1005], w[1005], n, cap;

int go(int i, int curW) {
    if (i == n) return 0;
    if (dp[i][curW] != -1) return dp[i][curW];

    int not_take = go(i + 1, curW), take = 0;
    if (w[i] + curW <= cap) take = p[i] + go(i + 1, w[i] + curW);

    return dp[i][curW] = max(not_take, take);
}

int main(){
    optimize();

    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> p[i] >> w[i];
        
        int g; cin >> g;
        ll ans = 0;
        while (g--) {
            cin >> cap;
            memset(dp, -1, sizeof(dp));
            ans += go(0, 0);
        }
        cout << ans << endl;
    }
}

/*Sample Input
2
3
72 17
44 23
31 24
1
26
6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
26
*/
/*output
72
514
*/
