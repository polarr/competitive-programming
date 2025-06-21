/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-19
 * Contest: 
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

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> grid(m, vi(n));
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> grid[j][i];
        }
    }

    pii ans = {0, 0};

    rep(i, 0, n){
        bool broken = false;
        rep(j, 1, m){
            if (grid[j][i] < grid[j - 1][i]){
                int cnt = 0;
                for (int k = j - 1; k >= 0; k--){
                    if (grid[k][i] != grid[j - 1][i]) break;
                    cnt++;
                }

                if (cnt == 1){
                    int lst = j;
                    rep(k, j, m){
                        if (grid[k][i] <= grid[j][i]){
                            lst = k;
                        }
                    }

                    swap(grid[j - 1], grid[lst]);
                    ans = {j - 1, lst};
                    broken = true;
                    break;
                } else {
                    swap(grid[j], grid[j - cnt]);
                    ans = {j - cnt, j};
                    broken = true;
                    break;
                }
            }
        }

        if (broken) break;
    }

    rep(i, 0, n){
        rep(j, 1, m){
            if (grid[j][i] < grid[j - 1][i]){
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1 << endl;
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