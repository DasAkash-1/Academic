#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define mxe max_element
#define mne min_element
#define vi vector <int>
#define vll vector <long long>
#define pii pair<int, int>
#define pss pair<string, string>
#define psi pair<pss, int>
#define mii map <int, int>
#define mll map <long long, long long>
#define umii unordered_map <int, int>
#define ust unordered_set <int>
#define umst unordered_multiset <int>
#define print_yes cout << "yes" << '\n'
#define print_no cout << "no" << '\n'
#define srt(v) sort(v.begin(), v.end())

bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int gcd(int a, int b) { return b ? gcd (b, a % b) : a; }
int lcm(int a, int b) { return abs(a * (b / gcd(a, b))); }

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int digit_sum (int a) {
    return (a == 0) ? 0 : a % 10 + digit_sum(a / 10);
}

int lb (vll &v, ll tgt) {
    ll n = v.size();
    ll l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (v[mid] < tgt) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

int ub (vll &v, ll tgt) {
    ll n = v.size();
    ll l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (v[mid] <= tgt) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

int main(){
    optimize();

    //Sieve();

    int t, tc = 1;
    cin >> t;
    
    while (t--) {
        
        ll n, q;
        cin >> n >> q;
        
        vll v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        cout << "Case " << tc++ << ":" << endl;
        while (q--) {
            ll a, b;
            cin>> a >> b;

            cout << ub(v, b) - lb(v, a) << endl;
        }
    }
}
