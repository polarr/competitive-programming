/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-19
 * Contest: ICPC Practice Codeforces 1938
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

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
    if (btoa[j] == -1) return 1;
    vis[j] = 1; int di = btoa[j];
    for (int e : g[di])
        if (!vis[e] && find(e, g, btoa, vis)) {
            btoa[e] = di;
            return 1;
        }
    return 0;
}

int dfsMatching(vector<vi>& g, vi& btoa) {
    vi vis;
    rep(i,0,sz(g)) {
        vis.assign(sz(btoa), 0);
        for (int j : g[i])
            if (find(j, g, btoa, vis)) {
                btoa[j] = i;
                break;
            }
    }
    return sz(btoa) - (int)count(all(btoa), -1);
}

void solve(){
    // classically construct bipartite r/c, edge iff both unique
    // then clearly ans = maximal matching!

    int n; cin >> n;
    vector<vi> grid(n, vi(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> grid[i][j];
            --grid[i][j];
        }
    }

    vi r(n, 0), c(n, 0);

    int ans = 0;

    rep(i, 0, n){
        bool unique = true;
        vector<bool> has(n, false);
        rep(j, 0, n){
            int x = grid[i][j];
            if (has[x]){
                unique = false;
                break;
            }

            has[x] = true;
        }

        if (unique){
            ans++;
            r[i] = 1;
        }
    }

    rep(i, 0, n){
        bool unique = true;
        vector<bool> has(n, false);
        rep(j, 0, n){
            int x = grid[j][i];
            if (has[x]){
                unique = false;
                break;
            }

            has[x] = true;
        }

        if (unique){
            ans++;
            c[i] = 1;
        }
    }

    vector<vi> g(n);

    rep(i, 0, n){
        rep(j, 0, n){
            if (r[i] && c[j]){
                g[i].pb(j);
            }
        }
    }

    vi btoa(n, -1);

    int match = dfsMatching(g, btoa);

    ans -= match;

    cout << ans << endl;

    auto change = [&](int k){
        if (k != 0){
            return 0;
        } else {
            return 1;
        }
    };

    rep(i, 0, n){
        if (btoa[i] != -1){
            r[btoa[i]] = 0;
            c[i] = 0;
            int gg = change(grid[btoa[i]][i]);
            grid[btoa[i]][i] = gg;
            cout << btoa[i] + 1 << " " << i + 1 << " " << gg + 1 << endl;
        }
    }

    rep(i, 0, n){
        if (r[i]){
            vector<int> has(n, 0);
            rep(j, 0, n){
                int x = grid[j][0];

                has[x]++;
            }

            int a = grid[i][0];
            if (has[a] == 1 || has[a] > 2){
                int gg = change(a);
                grid[i][0] = gg;
                cout << i + 1 << " " << 1 << " " << gg + 1 << endl;
            } else {
                rep(j, 0, n){
                    if (j != a && has[j] > 0){
                        int gg = j;
                        grid[i][0] = gg;
                        cout << i + 1 << " " << 1 << " " << gg + 1 << endl;
                        break;
                    }
                }
            }
        }
    }

    rep(i, 0, n){
        if (c[i]){
            vector<int> has(n, 0);
            rep(j, 0, n){
                int x = grid[0][j];

                has[x]++;
            }

            int a = grid[0][i];
            if (has[a] == 1 || has[a] > 2){
                int gg = change(a);
                grid[0][i] = gg;
                cout << 1 << " " << i + 1 << " " << gg + 1 << endl;
            } else {
                rep(j, 0, n){
                    if (j != a && has[j] > 0){
                        int gg = j;
                        grid[0][i] = gg;
                        cout << 1 << " " << i + 1 << " " << gg + 1 << endl;
                        break;
                    }
                }
            }
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