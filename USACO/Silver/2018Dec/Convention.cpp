/**
 * Solution by 1egend
 * Date: 2021-12-19
 * Contest: USACO 2018 December
 * Problem: Silver P1. Convention
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "convention";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<int> times;
int n, m, c;

bool check(int k){
    int b = m;

    int x = 0;
    for (int i = 0; i < n; ++i){
        if (i - x + 1 > c || times[i] - times[x] > k){
            --b;
            x = i;
        }

        if (!b){
            return false;
        }
    }
    return true;
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    fin >> n >> m >> c;

    for (int i = 0; i < n; ++i){
        int t;
        fin >> t;

        times.pb(t);
    }

    sort(times.begin(), times.end());

    long long pos = 0; long long max = 2E9;
    for(long long a = max; a >= 1; a /= 2){
        while(!check(pos+a)) pos += a;
    }
    fout << pos + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}