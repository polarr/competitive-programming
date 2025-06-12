/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-12
 * Contest: 
 * Problem: E
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

// LETS GOOO GM TPR!

void solve(){
    int n, m; cin >> n >> m;

    vector<vi> grid(n, vi(m, 0));
    int py = 0, px = 0;
    if (n > m){
        py = (n - m)/2;
    } else if (m > n){
        px = (m - n)/2;
    }
    
    int my = (n - 1)/2, mx = (m - 1)/2;

    vector<pii> ans;

    auto sandwich = [&](int layer){
        if (n > m){
            ans.pb({my - layer, mx});
            ans.pb({my + layer, mx});
            rep(j, 1, mx + 1){
                ans.pb({my - layer, mx - j});
                ans.pb({my + layer, mx + j});
                ans.pb({my - layer, mx + j});
                ans.pb({my + layer, mx - j});
            }
        }else {
            ans.pb({my, mx + layer});
            ans.pb({my, mx - layer});
            rep(j, 1, my + 1){
                ans.pb({my + j, mx + layer});
                ans.pb({my - j, mx - layer});
                ans.pb({my - j, mx + layer});
                ans.pb({my + j, mx - layer});
            }
        }
    };

    auto ring = [&](int layer){
        if (layer == 0){
            ans.pb({my, mx});
            return;
        }

        if (layer == 1){
            ans.pb({my - 1, mx});
            ans.pb({my + 1, mx});
            ans.pb({my, mx + 1});
            ans.pb({my, mx - 1});
            ans.pb({my - 1, mx + 1});
            ans.pb({my + 1, mx - 1});
            ans.pb({my + 1, mx + 1});
            ans.pb({my - 1, mx - 1});
            return;
        }

        ans.pb({my - layer, mx});
        ans.pb({my + layer, mx});
        ans.pb({my, mx + layer});
        ans.pb({my, mx - layer});

        int lvl = 0;
        int need = layer - 1;
        while (lvl < need){
            int j = lvl + 1;
            ans.pb({my - layer, mx - j});
            ans.pb({my + layer, mx + j});
            ans.pb({my - layer, mx + j});
            ans.pb({my + layer, mx - j});
            ans.pb({my + j, mx + layer});
            ans.pb({my - j, mx - layer});
            ans.pb({my - j, mx + layer});
            ans.pb({my + j, mx - layer});
            lvl++;
        }

        ans.pb({my - layer, mx + layer});
        ans.pb({my + layer, mx - layer});
        ans.pb({my + layer, mx + layer});
        ans.pb({my - layer, mx - layer});
    };

    // color square 
    int layer = 0;
    for (int d = 1; d <= min(m, n); d += 2){
        ring(layer);
        layer++;
    }

    while (layer <= max(my, mx)){
        sandwich(layer);
        layer++;
    }

    for (pii coord : ans){
        cout << coord.first + 1 << " " << coord.second + 1 << endl;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}