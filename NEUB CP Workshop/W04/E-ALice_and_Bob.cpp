#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main(){
    optimize();
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;

        vector<pair<int, int>> alice(n);
        vector<pair<int, int>> bob(n);

        for (int i = 0; i < n; i++) cin >> alice[i].first >> alice[i].second;
        
        for (int i = 0; i < n; i++) cin >> bob[i].first >> bob[i].second;

        sort(alice.rbegin(), alice.rend());
        sort(bob.rbegin(), bob.rend());

        multiset<int> width;
        int i = 0;

        for (int j = 0; j < n; j++)
        {
            int bh = bob[j].first, bw = bob[j].second;

            while (i < n && alice[i].first >= bh)
            {
                width.insert(alice[i].second);
                i++;
            }
            auto it = width.lower_bound(bw);

            if (it != width.end())
            {
                sum++;
                width.erase(it);
            }
        }
        cout << sum << endl;
    }
}
