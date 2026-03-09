/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-08
 * Contest: 
 * Problem: D
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
    int n, k, v; cin >> n >> k >> v;
    --v;

    vector<vi> adj(n);
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if (sz(adj[v]) == 1) {
        cout << "YES" << endl;
        return;
    }

    function<int(int, int)> dfs;
    dfs = [&](int node, int par) {
        bool isLeaf = true;
        vi vals;
        for (int x : adj[node]) {
            if (x == par) continue;
            isLeaf = false;
            vals.pb(dfs(x, node));
        }

        sort(all(vals));

        if (isLeaf) {
            return 0;
        }

        if (sz(vals) == 1) {
            return vals[0] + 1;
        }

        if (vals[0] + vals[1] + 2 <= k + 1) {
            return 0;
        }

        return vals[0] + 1;
    };

    int ans = dfs(v, -1);
    if (ans == 0) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
    return;
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