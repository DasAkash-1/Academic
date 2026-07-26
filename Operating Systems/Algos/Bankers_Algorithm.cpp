#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define F first
#define S second
#define endl "\n"

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define inf 3e9
const int N = 1e3;
int f[N], cnt[N], ans[N];

void solve()
{
    int n, r; cin >> n >> r;
    int alloc[n][r], max[n][r];
    vi avail(r);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            cin >> alloc[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            cin >> max[i][j];

    for (int i = 0; i < r; i++) cin >> avail[i];

    vector<vi> need(n, vi(r));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int ct = 0;
    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            if (!f[i]) 
            {
                int flag = 0;
                for (int j = 0; j < r; j++) 
                {
                    if (need[i][j] > avail[j]) 
                    {
                        flag = 1;
                        break;
                    }
                }

                if (!flag) 
                {
                    ans[ct++] = i;
                    for (int j = 0; j < r; j++) 
                        avail[j] += alloc[i][j];

                    f[i] = 1;
                }
            }
        }
    }

    cout << endl << "Safe Seq: " ;
    for (int i = 0; i < n; i++) 
    {
        if (i < n - 1) cout << 'P' << ans[i] << " -> ";
        else cout << 'P' << ans[i] << endl;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
            cout << need[i][j] << " ";
        cout << endl;
    }
}

int32_t main()
{
    fastio();

    int t = 1; 
    //cin >> t;
    while (t--) solve();
}

// input 

// 5 3
// 0 0 1
// 3 0 0
// 1 0 1
// 2 3 2
// 0 0 3
// 7 6 3
// 3 2 2
// 8 0 2
// 2 1 2
// 5 2 3
// 2 3 2
// out


// 5 3
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3
// 3 3 2
//out
// 7 4 3 
// 1 2 2 
// 6 0 0 
// 0 1 1 
// 4 3 1 
