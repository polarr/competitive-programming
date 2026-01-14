/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-12
 * Contest: CSES Problemset
 * Problem: 1669
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
    stack<int> s;
    bool found = false;
    function<void(int, int)> dfs;
    dfs = [&](int x, int par) {
        visited[x] = true;
        s.push(x);
        for (int node : adj[x]) {
            if (node == par) continue;
            if (visited[node]) {
                found = true;
                vi ans = {node + 1};
                while (s.top() != node) {
                    ans.pb(s.top() + 1);
                    s.pop();
                }
                ans.pb(node + 1);
                cout << sz(ans) << endl;
                rep(i, 0, sz(ans)) {
                    cout << ans[i] << " ";
                }
                cout << endl;
                return;
            }

            color[node] = 1 - color[x];
            dfs(node, x);
            if (found) return;
        }
        s.pop();
    };

    rep(i, 0, n) {
        if (visited[i]) continue;
        dfs(i, -1);
        if (found) return;
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}