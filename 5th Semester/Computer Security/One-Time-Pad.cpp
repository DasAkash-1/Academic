/*
 * One Time Pad
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

string encrypt(string s, string k)
{
    string ans = "";

    int n = k.size();
    int cipher[n];

    for (int i = 0; i < n; i++)
    {
        cipher[i] = s[i] - 'A' + k[i] - 'A';
        cipher[i] %= 26;

        ans += (char)(cipher[i] + 'A');
    }
    return ans;
}

string decrypt(string s, string k)
{
    string ans = "";

    int n = k.size();
    int cipher[n];

    for (int i = 0; i < n; i++)
    {
        cipher[i] = (s[i] - 'A') - (k[i] - 'A');
        cipher[i] = (cipher[i] < 0 ? cipher[i] + 26 : cipher[i]);

        ans += (char)(cipher[i] + 'A');
    }
    return ans;
}

void solve()
{
    string s, k; cin >> s >> k; string ss = s;

    for (int i = 0; i < sz(s); i++) s[i] = toupper(s[i]);
    for (int i = 0; i < sz(k); i++) k[i] = toupper(k[i]);

    string en = encrypt(s, k);
    string de = decrypt(en, k);

    for (int i = 0; i < sz(s); i++)
    {
        de[i] = (islower(ss[i]) ? tolower(de[i]) : de[i]);
    }
    cout << en << endl;
    cout << de << endl;
}

// https://ece.uwaterloo.ca/~ece150/Programming_challenges/C.1/

// Hello
// MONEY
 
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
