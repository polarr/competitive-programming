/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-24
 * Contest: USACO 2025 January Silver
 * Problem: 3
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0)), ans = grid;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> grid[i][j];
        }
    }

    vector<pair<int, int>> colors(n);
    rep(i, 0, n - 1){
        colors[i + 1] = {i + 2, 2 * n - i};
    }

    vector<int> givenColors(2 * n + 1, 0);
    rep(i, 0, n){
        rep(j, 0, n){
            givenColors[grid[i][j]]++;
        }
    }

    bool foundFirst = false;

    rep(i, 0, n){
        rep(j, 0, n){
            if (ans[i][j] != 0){
                continue;
            }

            int color = givenColors[grid[i][j]];
            if (color == n){
                ans[i][j] = n + 1;
                continue;
            }

            if (foundFirst){
                // choose lexicographically smallest parity
                ans[i][j] = colors[color].first;
                foundFirst = true;
            }

            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}