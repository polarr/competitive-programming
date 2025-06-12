/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-12
 * Contest: 
 * Problem: D1
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
    int n; ll k; cin >> n >> k;
    vector<vector<vi>> good(n, vector<vi>(k, vi(2, -1)));
    vector<vector<vi>> loaded(n, vector<vi>(k, vi(2, 0)));

    vl pos(n);
    rep(i, 0, n){
        cin >> pos[i];
    }

    vl delay(n);
    rep(i, 0, n){
        cin >> delay[i];
    }

    function<void(int, ll, int)> dfs;
    dfs = [&](int i, ll kk, int dir){
        if (good[i][kk][dir] != -1){
            return;
        }

        if (loaded[i][kk][dir] == 1){
            loaded[i][kk][dir] = 0;
            return;
        }

        loaded[i][kk][dir] = 1;

        if (delay[i] == kk){
            // traffic
            int ndir = 1 - dir;
            if (ndir == 0){
                if (i == 0){
                    good[i][kk][dir] = 1;
                } else {
                    ll nx = abs(pos[i - 1] - pos[i]);
                    dfs(i - 1, (kk + nx) % k, 0);
                    good[i][kk][dir] = good[i - 1][(kk + nx) % k][0];
                }
            } else {
                if (i == n - 1){
                    good[i][kk][dir] = 1;
                } else {
                    ll nx = abs(pos[i + 1] - pos[i]);
                    dfs(i + 1, (kk + nx) % k, 1);
                    good[i][kk][dir] = good[i + 1][(kk + nx) % k][1];
                }
            }
        } else {
            // no traffic
            if (dir == 0){
                if (i == 0){
                    good[i][kk][dir] = 1;
                } else {
                    ll nx = abs(pos[i - 1] - pos[i]);
                    dfs(i - 1, (kk + nx) % k, 0);
                    good[i][kk][dir] = good[i - 1][(kk + nx) % k][0];
                }
            } else {
                if (i == n - 1){
                    good[i][kk][dir] = 1;
                } else {
                    ll nx = abs(pos[i + 1] - pos[i]);
                    dfs(i + 1, (kk + nx) % k, 1);
                    good[i][kk][dir] = good[i + 1][(kk + nx) % k][1];
                }
            }
        }
    };

    rep(i, 0, n){
        rep(j, 0, k){
            rep(d, 0, 2){
                if (good[i][j][d] == -1){
                    dfs(i, j, d);
                }
            }
        }
    }

    int q; cin >> q;

    rep(i, 0, q){
        ll a; cin >> a;
        auto j = lower_bound(pos.begin(), pos.end(), a);
        if (j == pos.end()){
            cout << "YES" << endl;
            continue;
        }

        int kk = j - pos.begin();
        ll nx = pos[kk] - a;
        if (good[kk][nx % k][1] == 1){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
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