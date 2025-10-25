/*
 * Strongly Connected Components (SCC) - Tarjan's Algorithm
 * Lab Assignment   : 7
 * Group No		    : C
 * Submission Date	: 25-10-2025
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define vi vector <int>
#define mem(a, b) memset(a, b, sizeof(a));
#define F first
#define S second

const int N = 1005;
vi G[N], Gt[N], scc[N];
int idx[N], low[N], sccCt, n, m, tempo;
bool vis[N];
stack <int> st;
map <string, int> mp;

void add_edge(int u, int v) {
    G[u].push_back(v);
}

void _clear() {
    for(int i = 0; i < N; i++) 
        G[i].clear();
}

void strong_connect(int u) {
    idx[u] = low[u] = tempo++;
    st.push(u);
    vis[u] = 1;

    for (auto v: G[u]) {
        if (idx[v] == -1) {
            strong_connect(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v]) 
            low[u] = min(low[u], idx[v]);
    }

    if (idx[u] == low[u]) {
        sccCt++;
        int v = -1;
        while (v != u) {
            v = st.top(); st.pop();
            vis[v] = 0;
        }
    }
}

void tarjan() {
    mem(idx, -1);
    mem(low, 0);

    sccCt = 0;
    while (!st.empty()) st.pop();

    for (int i = 0; i < n; i++) 
        if (idx[i] == -1) strong_connect(i);
}

int main(){
    fastio();

    while (cin >> n >> m && n != 0) {
        _clear();
        cin.ignore();

        for (int i = 0; i < n; i++) {
            string ppl; getline(cin,  ppl);
            mp[ppl] = i;
        }

        for (int i = 0; i < m; i++) {
            string a, b; 
            getline(cin, a);
            getline(cin, b);

            int u = mp[a], v = mp[b];
            add_edge(u, v);
        }

        tarjan();

        cout << sccCt << endl;
    }
}
/*
Input:
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
McBride, John
Smith, Peter
0 0

Output:
2
3
*/
