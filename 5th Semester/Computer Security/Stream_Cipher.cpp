/*
 * Stream Cipher
 * Problem      : 
 * Author		: Das Akash
 * Date	: 25-08-2025
 */
 #include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) ((int)(a).size())
#define pb push_back
#define F first
#define S second
#define endl "\n"

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll, ll>;

double PI = 3.14159265358979323846;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = (int)1e18;

const int N = 1e6 + 123;
ll a[N];
vi comp(N, 0), pr;

string stream(string s, int k)
{
    srand(k);
    string ans = "";

    for (int i = 0; i < sz(s); i++)
    {
        ans += s[i] ^ (char)rand();
    }
    return ans;
}

void solve()
{
    string s; getline(cin, s);
    int k = 123123;

    cout << stream(s, k) << endl; // encript
    cout << stream(stream(s, k), k) << endl; // decr
}

// https://ece.uwaterloo.ca/~ece150/Programming_challenges/C.1/

// hello Its me, Sky :)
 
int32_t main()
{
    fastio();
    //seive();

    cout << fixed << setprecision(10);
    int tc = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    //cin >> tc;
    while(tc--) solve();

    return 0;
}
