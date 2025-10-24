/**
 * Strongly Connected Components (SCC) - Kosraju's Algorithm
 * Problem      : UVA - 11709
 * Author		: Das Akash
 * Date			: 25-10-2025
 * */

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
bool vis[N];
vi G[N], Gt[N], scc[N];
int v, sccCt;
stack <int> st;
map <string, int> mp;

void add_edge(int u, int v) {
    G[u].push_back(v);
    Gt[v].push_back(u);
}

void dfs_1(int u) {
    vis[u] = 1;

    for (auto v: G[u])  
        if (!vis[v]) dfs_1(v);
    st.push(u);
}

void dfs_2(int u) {
    vis[u] = 1;

    for (auto v: Gt[u]) 
        if (!vis[v]) dfs_2(v);
}

int main(){
    fastio();

    int p, t;
    while (cin >> p >> t && p != 0) {
        for(int i = 0; i < N; i++) {
            G[i].clear();
            Gt[i].clear();
        }

        cin.ignore();

        mem(vis, 0);
        for (int i = 0; i < p; i++) {
            string ppl; getline(cin,  ppl);
            mp[ppl] = i;
        }

        for (int i = 0; i < t; i++) {
            string a, b; 
            getline(cin, a);
            getline(cin, b);

            int u = mp[a], v = mp[b];
            add_edge(u, v);
        }

        for (int i = 0; i < p; i++) {
            if (!vis[i]) dfs_1(i);
        }

        mem(vis, 0);
        sccCt = 0;
        while (!st.empty()) {
            int u = st.top(); st.pop();

            if (!vis[u]) {
                dfs_2(u);
                sccCt++;
            }
        }
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
