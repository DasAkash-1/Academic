#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define vi vector <int>
#define pii pair<int, int>
#define ln cout << endl
#define F first
#define S second
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define mem(a, b) memset(a, b, sizeof(a));

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

const int N = 105;
char g[N][N];
bool vis[N][N];
int d[N][N], n;

void bfs(int x, int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) vis[i][j] = 0;
    }

    int x1, y1;
    queue <pii> q;
    q.push({x, y});

    vis[x][y] = 1;
    d[x][y] = 0;

    while (!q.empty()) {
        x = q.front().F;
        y = q.front().S;
        q.pop();

        for (int i = 0; i < 4; i++) {
            x1 = x + dx[i];
            y1 = y + dy[i];

            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n
                && !vis[x1][y1] && g[x1][y1] != 'O') 
            {
                vis[x1][y1] = 1;
                d[x1][y1] = d[x][y] + 1;
                q.push({x1, y1});   
            }
        }
    }
}

int main(){
    fastio();

    int ax, ay, bx, by;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j] == '@') {
                ax = i; ay = j;
            }
            if (g[i][j] == 'X') {
                bx = i; by = j;
            }
        }
    }
    bfs(ax, ay);

    if (!vis[bx][by]) cout << "N" << endl;
    else {
        cout << "Y" << endl;
        cout << d[bx][by] << endl;
    }

}

