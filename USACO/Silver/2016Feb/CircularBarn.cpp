/**
 * Solution by 1egend
 * Date: 2021-12-19
 * Contest: USACO 2016 February
 * Problem: P1. Circular Barn
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    cin >> n;

    vector<bool> occupied(n, false);
    vector <pair<int, int>> rooms;
    for (int i = 0; i < n; ++i){
        int t; cin >> t;
        rooms.pb(mp(t, i));
    }

    sort(rooms.end(), rooms.begin());

    int ans = 0;
    for (int i = 0; i < n; ++i){
        int a = rooms[i].second;
        int c = 0;
        while (c < rooms[i].first){
            if (a == n){
                a = 0;
            }

            if (!occupied[a]){
                ++c;
                occupied[a] = true;
                ans += (a - rooms[i].second) * a;
            }
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}