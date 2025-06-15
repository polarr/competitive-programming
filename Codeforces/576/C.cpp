/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-14
 * Contest: Codeforces 576
 * Problem: C
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
const int BLOCK = 1e3;

// how is this 2100...
void solve(){
    int n; cin >> n;
    
    vector<vector<vector<array<int, 3>>>> blocks(BLOCK + 1, vector<vector<array<int, 3>>>(BLOCK + 1));

    rep(i, 0, n){
        int x, y; cin >> x >> y;
        blocks[y/BLOCK][x/BLOCK].pb({x, y, i});
    }

    vi ans;

    rep(i, 0, BLOCK + 1){
        if (i % 2 == 0){
            rep(j, 0, BLOCK + 1){
                for (auto [x, y, k]: blocks[i][j]){
                    ans.pb(k);
                }
            }
        } else {
            for (int j = BLOCK; j >= 0; j--){
                for (auto [x, y, k]: blocks[i][j]){
                    ans.pb(k);
                }
            }
        }
    }

    for (int i : ans){
        cout << i + 1 << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}