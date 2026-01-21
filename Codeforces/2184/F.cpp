/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-20
 * Contest: 
 * Problem: F
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
    vector<vi> adj(n);
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    using T = array<bool, 3>;
    vector<T> can(n);
    
    function<void(int, int)> dfs;
    dfs = [&](int node, int par) {
        can[node][1] = true;
        int sum = 0;
        int alt = 0;
        bool all = false;
        for (int x : adj[node]) {
            if (x == par) continue;

            dfs(x, node);

            sum++;
            if (can[x][2]) {
                if (alt != 0) {
                    all = true;
                }

                alt = 1;
            }

            if (can[x][0]) {
                if (alt != 0) {
                    all = true;
                }

                alt = 2;
            }
        }

        if (sum == 0) return;

        if (all) {
            can[node][0] = can[node][2] = true;
        } else {
            sum %= 3;
            can[node][sum] = true;
            can[node][(sum + alt) % 3] = true;
        }
    };

    dfs(0, -1);

    if (can[0][0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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