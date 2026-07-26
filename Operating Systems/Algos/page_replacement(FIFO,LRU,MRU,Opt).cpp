#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define F first
#define S second
#define endl "\n"

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define inf 3e9


int maxIdx(vi &v) 
{
    int max_idx = 0;
    for (int i = 1; i < v.size(); i++) 
    {
        if (v[i] > v[max_idx]) max_idx = i;
        
    }
    return max_idx;
}

int search(vi &v, int idx, int value) 
{
    for (int i = idx; i < v.size(); i++) 
    {
        if (v[i] == value) return i;
    }
    return inf;
}

void print(vi &v) {

    cout << endl;
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    cout << endl;
}


void print(vi &frames, int page) {

    cout << setfill(' ') << setw(2) << page << " : ";
    for (int i = frames.size() - 1; i >= 0; --i) 
    {
        if (frames[i] == inf) cout << "* ";
        else cout << frames[i] << " ";
    }
    cout << endl;
}


void print(int misses, int hit) 
{

    cout << endl;
    cout << "Total Hits   : " << hit << endl;
    cout << "Total Faults : " << misses << endl;
    cout << endl << "Hit Ratio: " << ((double)hit / (hit + misses)) * 100 << "%";
    cout << ", Miss Ratio: " << ((double)misses / (hit + misses)) * 100 << "%" << endl << endl;
}



void FIFO(vi &a, int num_frames) 
{

    int hit = 0, misses = 0;

    vi frames (num_frames, inf);

    cout << endl;

    for (int i = 0; i < a.size(); i++) 
    {
        int idx = search(frames, 0, a[i]);

        if ( idx == inf) 
        {
            frames.erase(frames.begin());
            frames.pb(a[i]);
            misses++;
        }
        else hit++;
        
        print(frames, a[i]);
    }

    print(misses, hit);
    frames.clear();
}


void LRU(vi &a, int num_frames) 
{

    int misses = 0;
    int hit = 0;

    vi frames (num_frames, inf);

    cout << endl;

    for (int i = 0; i < a.size(); i++) 
    {
        int idx = search(frames, 0, a[i]);

        if (idx == inf) 
        {
            frames.erase(frames.begin());
            frames.pb(a[i]);
            misses++;
        }
        else 
        {
            int temp = frames[idx];
            frames.erase(frames.begin() + idx);
            frames.pb(temp);
            hit++;
        }
        print(frames, a[i]);
    }

    print(misses, hit);
    frames.clear();
}

void MRU(vi &a, int num_frames) 
{

    int misses = 0;
    int hit = 0;

    vi frames (num_frames, inf);

    cout << endl;

    for (int i = 0; i < a.size(); i++) 
    {
        int idx = search(frames, 0, a[i]);

        if ( idx == inf ) 
        {
            if (frames[0] == inf ) 
            {
                frames.erase(frames.begin());
            }
            else frames.erase(frames.end() - 1);
            
            frames.pb(a[i]);
            misses++;
        }
        else 
        {
            int temp = frames[idx];
            frames.erase(frames.begin() + idx);
            frames.pb(temp);
            hit++;
        }


        print(frames, a[i]);
    }

    print(misses, hit);
    frames.clear();
}


void OPTIMAL(vi &a, int num_frames) 
{

    int misses = 0;
    int hit = 0;

    vi frames (num_frames, inf);
    vi idxa (num_frames, inf);

    cout << endl;
    for (int i = 0; i < a.size(); i++) 
    {
        int idx = search(frames, 0, a[i]);

        if ( idx == inf ) 
        {
            frames.erase(frames.begin() + maxIdx(idxa));
            idxa.erase(idxa.begin() + maxIdx(idxa));
            frames.pb(a[i]);
            idxa.pb(search(a, i + 1, a[i]));
            misses++;
        }
        else 
        {
            idxa[idx] = search(a, i + 1, a[i]);
            hit++;
        }
        print(frames, a[i]);
    }

    print(misses, hit);
    frames.clear();
    idxa.clear();
}

int32_t main()
{
    fastio();

    int len, num_frames;
    vi a;

    cout << endl << "Please enter len of sequence: ";cin >> len;
    cin.ignore();

    cout << "sequenc: ";
    for (int i = 0; i < len; i++) 
    {
        int x; cin >> x;
        a.pb(x);
    }

    cout << endl << "Trace entered: ";
    print(a);

    cout << endl << "Please enter the number of frames: ";
    cin >> num_frames;
    cin.ignore();

    cout << endl;
    cout << "First-In First-Out" << endl;
    FIFO(a, num_frames);

    cout << "Least Recently Used" << endl;
    LRU(a, num_frames);

    cout << "Most Recently Used" << endl;
    MRU(a, num_frames);

    cout << "Optimal" << endl;
    OPTIMAL(a, num_frames);

    a.clear();
}
