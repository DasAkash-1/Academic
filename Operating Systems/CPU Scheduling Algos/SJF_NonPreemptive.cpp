#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from 0)..
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define vi vector <int>
#define vec(x) vector <x>
#define vll vector <long long>
#define mll map <ll, ll>
#define pii pair<int, int>
#define print_yes cout << "YES" << '\n'
#define print_no cout << "NO" << '\n'
#define ln cout << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend() 
#define mem(a, b) memset(a, b, sizeof(a));
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rep1(i, a, n) for(int i = a; i <= n; i++)
#define F first
#define S second

const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 3e18;

const int N = 2e4 + 123;
int v[N], cnt[N], num, pref[N]; 
vi comp(N + 1, 0), divs[N], primes, spf;
vec(bool) is_prime(N + 1, 0);
set <int> s;

void seive()
{
    comp[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        if(comp[i]) continue;
        //pr.push_back(i);
        for(int j = i + i; j <= N; j += i)
            comp[j] = 1;
    }
}

struct process
{
    int pid, at, bt, ct, tat, wt;
};

bool cmp(const process &p1, const process &p2)
{
    return p1.at < p2.at;
}

void CT(vec(process) &pr, int n)
{
    vec(bool) done(n, 0);
    int fin = 0, tempo = 0;
    while (fin < n)
    {
        ll mn = INF, idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (pr[i].at <= tempo && !done[i])
            {
                if (pr[i].bt < mn)
                {
                    idx = i;
                    mn = pr[i].bt;
                }
            }
        }
        if (idx == -1) tempo++;
        else
        {
            tempo += pr[idx].bt;
            pr[idx].ct = tempo;
            done[idx] = 1;
            fin++;
        }
    }
}

void TAT(vec(process) &pr, int n)
{
    for (int i = 0; i < n; i++) // kokhon complt hoise - at = total kotkhhon system e chilo (wt + bt = tat)
        pr[i].tat = pr[i].ct - pr[i].at; // tat = ct - at
}

void WT(vec(process) &pr, int n)
{
    for (int i = 0; i < n; i++) // wt = tat - bt, turnarnd theke burst bad jabe
        pr[i].wt = (pr[i].tat - pr[i].bt < 0) ? 0 : pr[i].tat - pr[i].bt;
}

int main()
{
    //fastio();

    cout << "Enter num of procss: ";
    int n; cin >> n;
    vec(process) pr(n);

    cout << "Enter PID, AT, BT\n";
    for (int i = 0; i < n; i++)
        cin >> pr[i].pid >> pr[i].at >> pr[i].bt;

    sort(all(pr), cmp);

    CT(pr, n);
    TAT(pr, n);
    WT(pr, n);

    cout << "PID\t" << "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\t" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << pr[i].pid << "\t" << pr[i].at << "\t"
             << pr[i].bt << "\t" << pr[i].ct << "\t" << pr[i].tat << "\t"
             << pr[i].wt << endl; 
    }

} // *_* dasky *_*
