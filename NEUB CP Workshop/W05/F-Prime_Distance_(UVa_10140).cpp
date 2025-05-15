#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

vector<bool> is_prime;

void segmented_sieve(int L, int R) {
    long long limit = sqrt(R) + 1;
    vector <char> mark(limit + 1, true);
    vector<long long> primes;

    primes.push_back(2);
    mark[0] = mark[1] = false;
    for(int i = 4; i <= limit; i += 2) mark[i] = false;

    for(int i = 3; i <= limit; i += 2) {
        if(mark[i]) {
            primes.push_back(i);
            for(int j = i * i; j <= limit; j += i) {
                mark[j] = false;
            }
        }
    }

    is_prime.assign(R - L + 1, true);

    for(long long p: primes) {
        long long start = max(p * p, (L + p - 1) / p * p);
        for(long long j = start; j <= R; j += p) {
            is_prime[j - L] = false;
        }
    }
    if(L == 1) is_prime[1] = false; //corner case,
}
int main(){
    optimize();

    long long L, R;
    while(cin >> L >> R) {
        segmented_sieve(L, R);

        int count = 0;

        long long ming = INT_MAX, maxg = -1, c1, c2, d1, d2;
        long long prevp = -1, currp;
        for(int i = L; i <= R; i ++) {
            if(is_prime[i - L]) {
                    if(prevp == -1) {
                        prevp = i;
                        continue;
                    }
                    currp = i;
                    long long gap = currp - prevp;
                    if(gap < ming) {
                        ming = gap;
                        c1 = prevp;
                        c2 = currp;
                    }
                    if(gap > maxg) {
                        maxg = gap;
                        d1 = prevp;
                        d2 = currp;
                    }
                    prevp = currp;

                    if(is_prime[R - L]) count++;
            }
        }
        if(count > 2) cout << c1 << "," << c2 << " are closest, " << d1 << "," << d2 << " are most distant." << endl;
        else cout << "There are no adjacent primes." << endl;
        
    }
}
