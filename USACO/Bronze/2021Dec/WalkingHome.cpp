/**
 * Solution by 1egend
 * Date: 2021-12-17
 * Contest: USACO 2021 December Contest
 * Problem: Bronze 
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

int ans = 0;
int n, k;
vector<vector<bool>> farm;

// 0 down 1 right
void floodfill(int r, int c, int turns, int dir){
    if(turns > k) return;
    if(r < 0 || r >= n || c < 0 || c >= n) return;
    if (r == n - 1 && c == n - 1) {
        ++ans;
        return;
    }
    if(!farm[r][c]) return;
    
    floodfill(r + 1, c, turns + (int)(dir == 0), 1);
    floodfill(r, c + 1, turns + (int)(dir == 1), 0);
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    ans = 0;
    cin >> n >> k;
    
    farm.clear();
    for (int i = 0; i < n; ++i){
        vector<bool> row;
        for (int ii = 0; ii < n; ++ii){
            char c; cin >> c;
            if (c == '.'){
                row.pb(true);
            } else {
                row.pb(false);
            }
        }

        farm.pb(row);
    }

    floodfill(0, 0, 0, 2);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        solve();
    }
    return 0;
}