/**
 * Solution by 1egend
 * Date: 7/15/2021
 * Contest: USACO 2018 February Contest
 * Problem: Silver - P1. Rest Stops
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "reststops";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    ull l, n, f, b;
    fin >> l >> n >> f >> b;

    ull r = f - b;
    vector <pair<ull, ull>> stops;
    multiset <ull> t;

    for (int i = 0; i < n; ++i){
        static ull a, b;
        fin >> a >> b;

        stops.pb(mp(a, b));
        t.insert(b);
    }
    // sort(stops.begin(), stops.end());

    ull ans = 0;
    ull lastStop = 0;
    for (int i = 0; i < n; ++i){
        if (stops[i].second == *(--t.end())){
            ans += r * (stops[i].first - lastStop) * stops[i].second;
            lastStop = stops[i].first;
        }
        
        t.erase(t.lower_bound(stops[i].second));
    }

    fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}