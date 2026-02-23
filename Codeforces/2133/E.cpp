/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-22
 * Contest: Codeforces 2133
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

void solve(){
    int n; cin >> n;
    vector<vi> adj(n);
    vi deg(n, 0);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
    }

    vector<bool> removed(n, false);
    vector<pii> ans;
    auto re = [&](int node) {
        ans.pb({2, node + 1});
        deg[node] = 0;
        removed[node] = true;
        for (int x : adj[node]){
            if (removed[x]) continue;
            deg[x]--;
        }
    };

    vector<bool> visited(n, false);

    function<void(int, int)> dfs;
    dfs = [&](int node, int par) {
        visited[node] = true;
        if (removed[node]) return;

        bool remove = false;

        for (int x : adj[node]) {
            if (removed[x] || x == par) continue;
            dfs(x, node);
            if (deg[x] >= 3) {
                remove = true;
            }
        }

        remove |= (deg[node] >= 4);
        remove |= (par == -1 && deg[node] == 3);

        if (remove) {
            re(node);
        }
    };

    rep(i, 0, n) {
        if (!visited[i]) dfs(i, -1);
    }

    function<int(int, int)> find_leaf;
    function<void(int, int)> solve_line;
    find_leaf = [&](int node, int par) {
        if (removed[node]) return node;
        for (int x : adj[node]) {
            if (removed[x] || x == par) continue;
            return find_leaf(x, node);
        }

        return node;
    };

    solve_line = [&](int node, int par) {
        visited[node] = true;
        ans.pb({1, node + 1});
        if (removed[node]) return;
        for (int x : adj[node]) {
            if (removed[x] || x == par) continue;
            return solve_line(x, node);
        }
    };

    visited = vector<bool>(n, false);
    rep(i, 0, n) {
        if (visited[i]) continue;
        int x = find_leaf(i, -1);
        solve_line(x, -1);
    }

    cout << sz(ans) << '\n';
    rep(i, 0, sz(ans)) {
        cout << ans[i].first << " " << ans[i].second << '\n';
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