/**
 * Solution by 1egend
 * Date: 2020-12-19
 * Contest: USACO 2015 December
 * Problem: Silver P3. Breed Counting
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "bcount";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, q;
    fin >> n >> q;

    vector<int> h = {0};
    vector<int> g = {0};
    vector<int> j = {0};

    int hh = 0, gg = 0, jj = 0;
    for (int i = 0; i < n; ++i){
        int t; fin >> t;
        if (t == 1){
            ++hh;
        } else if (t == 2){
            ++gg;
        } else {
            ++jj;
        }

        h.pb(hh);
        g.pb(gg);
        j.pb(jj);
    }

    for (int i = 0; i < q; ++i){
        int a, b;
        fin >> a >> b;
        --a;
        fout << h[b] - h[a] << " " << g[b] - g[a] << " " << j[b] - j[a] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}