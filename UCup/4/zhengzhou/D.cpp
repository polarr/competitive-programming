/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-29
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
    int n; cin >> n;
    vector<vi> adj(n + 1);
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        --a; --b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi par1(n + 1, -1);
    vi d(n);
    vector<pii> best(n);
    vi mxdepth(n, 0);
    int diam = 0;
    function<void(int, int)> dfs;
    dfs = [&](int node, int par) {
        par1[node] = par;
        int a = 0, b = 0, mx = 0;
        for (int x : adj[node]) {
            if (x == par) continue;
            dfs(x, node);
            mx = max(mx, d[x]);
            int c = 1 + mxdepth[x];
            mxdepth[node] = max(mxdepth[node], c);
            if (c >= a){
                b = a;
                a = c;
            } else if (c >= b) {
                b = c;
            }
        }

        best[node] = {a, b};
        d[node] = a + b;
        if (d[node] >= mx) {
            diam = node;
        }
    };

    dfs(0, -1);
    int len = d[diam];

    vector<bool> inDiam(n + 1, false);

    int root = diam;
    function<void(int)> dfs2;
    dfs2 = [&](int node) {
        inDiam[node] = true;
        if (mxdepth[node] == len/2) {
            root = node;
        }
        for (int x : adj[node]) {
            if (x == par1[node]) continue;
            int c = 1 + mxdepth[x];
            if ((node == diam && c < best[node].second) || (node != diam && c != best[node].first)) {
                // not good
                continue;
            }
            dfs2(x);
        }
    };

    dfs2(diam);
    if (len % 2 == 1) {
        int p = par1[root];
        adj[root].erase(find(all(adj[root]), p));
        adj[p].erase(find(all(adj[p]), root));
        adj[root].pb(n);
        adj[n].pb(root);
        adj[p].pb(n);
        adj[n].pb(p);
        root = n;
        inDiam[root] = true;
    }

    // cout << root << endl;

    int leaf = 0;
    vi par(n + 1, -1);
    function<void(int)> dfs3;
    dfs3 = [&](int node) {
        int c = 0;
        for (int x : adj[node]) {
            if (!inDiam[x]) continue;
            if (x == par[node]) continue;
            c++;
            par[x] = node;
            dfs3(x);
        }

        if (c == 0) {
            leaf++;
        }
    };

    dfs3(root);
    vi ans(len, 1);
    rep(i, 0, len - 1) {
        ans[i] = leaf + i;
    }

    rep(i, 0, len) {
        cout << ans[i] << " ";
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