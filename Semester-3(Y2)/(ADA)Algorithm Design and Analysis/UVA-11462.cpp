#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define mxe max_element
#define mne min_element
#define vi vector <int>
#define vll vector <long long>
#define pii pair<ll, ll>
#define pss pair<string, string>
#define psi pair<pss, ll>
#define mll map <ll, ll>
#define pb push_back
#define print_yes cout << "yes" << '\n'
#define print_no cout << "no" << '\n'
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())

bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int gcd(int a, int b) { return b ? gcd (b, a % b) : a; }
int lcm(int a, int b) { return abs(a * (b / gcd(a, b))); }

bool cmp (psi a, psi b) {
    if (a.first.first == b.first.first && a.first.second == b.first.second) return a.second > b.second;
    else if (a.first.second == b.first.second) return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}
bool cmp2 (int a, int b) { return a > b; }

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int digit_sum (int a) {
    return (a == 0) ? 0 : a % 10 + digit_sum(a / 10);
}

void merge(vll &a, vll &ans, ll l, ll r) {
    ll mid = l + (r - l) / 2;
    ll i1 = l, i2 = mid + 1, j = l;

    while (i1 <= mid && i2 <= r) {
        if (a[i1] < a[i2]) ans[j] = a[i1++];
        else ans[j] = a[i2++];
        j++;
    }
    while (i1 <= mid) {
        ans[j++] = a[i1++];
    }
    while (i2 <= r) {
        ans[j++] = a[i2++];
    }
    for (ll i = l; i <= r; i++) a[i] = ans[i];
}

void merge_sort(vll &a, vll &ans, ll l, ll r) {
    if (l == r) return;

    ll mid = l + (r - l) / 2;
    merge_sort(a, ans, l, mid);
    merge_sort(a, ans, mid + 1, r);
    merge(a, ans, l, r);
}

int main(){
    optimize();
    
    ll n;
    while (cin >> n && n != 0) {
        vll a(n);
        vll ans(n);
        
        for (int i = 0; i < n; i++) cin >> a[i];

        merge_sort(a, ans, 0, n - 1);

        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i != n - 1) cout << " ";
        }
        cout << endl;
    }
}