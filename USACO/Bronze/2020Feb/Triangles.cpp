/**
 * Solution by 1egend
 * Date: 7/8/2021
 * Contest: USACO 2020 February Contest 
 * Problem: Bronze - P1. Triangles
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

const iofilename = "";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        p.pb(make_pair(a, b));
    }

    ull ans = 0;
    for (int a = 0; a < n - 2; ++a){
        for (int b = a + 1; b < n - 1; ++b){
            for (int c = b + 1; c < n; ++c){
                if ((p[a].first == p[b].first || p[b].first == p[c].first || p[c].first == p[a].first) && (p[a].second == p[b].second || p[b].second == p[c].second || p[c].second == p[a].second)){
                    ans = max<ull>(ans, )
                }
            }
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}