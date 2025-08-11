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

bool cmp3 (string &a, string &b) { return a + b > b + a; }

void quick_sort(vector<string> &a, ll l, ll r) {
    ll i = l, j = r;
    string pivot = a[(l + r) / 2];

    while (i <= j) {
        while (cmp3(a[i], pivot)) i++;
        while (cmp3(pivot, a[j])) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if (l < j) quick_sort(a, l, j);
    if (r > i) quick_sort(a, i, r);
}

int main(){
    optimize();
    
    ll n;
    while (cin >> n && n != 0) {
        vector <string> a(n);
        
        for (int i = 0; i < n; i++) cin >> a[i];

        quick_sort(a, 0, n - 1);

        for (int i = 0; i < n; i++) cout << a[i];
    
        cout << endl;
    }
}