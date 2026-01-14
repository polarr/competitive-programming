/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-12
 * Contest: CSES Problemset
 * Problem: 1668
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

    vector<vi> adj(n);
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi color(n);
    vector<bool> visited(n, false);
    bool bad = false;
    function<void(int, int)> dfs;
    dfs = [&](int x, int par) {
        visited[x] = true;
        for (int node : adj[x]) {
            if (node == par) continue;
            if (visited[node]) {
                if (color[x] == color[node]) {
                    bad = true;
                }
                continue;
            }

            color[node] = 1 - color[x];
            dfs(node, x);
        }
    };

    rep(i, 0, n) {
        if (visited[i]) continue;
        color[i] = 0;
        dfs(i, -1);
    }

    if (bad) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    rep(i, 0, n) {
        cout << color[i] + 1 << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}