#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int n = 32000;
vector<bool> is_prime(n+1, true);

void Sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long) i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
        }
    }
}
int main(){
    optimize();

    Sieve();

    int L, R;
    vector <int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
  
    int total = primes.size();
    vector<vector<int>> dprimes;
    int prev_gap = 0, curr_gap = 0;
    for(int i = 2; i < total; i++) {
        curr_gap = primes[i] - primes[i - 1];
        if(curr_gap == prev_gap) {
            vector<int> v;
            v.push_back(primes[i - 2]);
            v.push_back(primes[i - 1]);
            v.push_back(primes[i]);
            for(int j = i + 1; j < total; j++) {
                if(primes[j] - primes[j - 1] == curr_gap) {
                    v.push_back(primes[j]);
                    i++;
                }
                else break;
            }
            dprimes.push_back(v);
        }
        prev_gap = curr_gap;
    }
    
    while((cin >> L >> R) && (L + R)) {
        if(L > R) swap(L, R);
        for(auto v: dprimes) {
                if(v[0] >= L && v.back() <= R) {
                    for (int i = 0; i < v.size(); i++) {
                        cout << v[i];
                        if (i != v.size() - 1) cout << " ";
                        else cout << endl;
                    }
                }
        }
    }
}
