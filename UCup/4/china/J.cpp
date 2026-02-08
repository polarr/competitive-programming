/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-07
 * Contest: 
 * Problem: J
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

    int anscount = 0;
    vector<vector<pii>> ans(n);
    vi depth(n, 0);
    vi rem(n, -1);
    function<void(int, int)> dfs;
    dfs = [&](int node, int par) {
        vi singles;
        for (int x : adj[node]) {
            if (x == par) continue;
            depth[x] = depth[node] + 1;
            dfs(x, node);
            if (rem[x] != -1) {
                singles.pb(rem[x]);
            }
        }

        rep(i, 0, sz(singles)/2) {
            int a = singles[2 * i], b = singles[2 * i + 1];
            anscount++;
            ans[depth[node]].pb({a, b});
        }

        if (sz(singles) % 2 == 1) {
            rem[node] = singles.back();
        }

        if (sz(singles) == 0) {
            rem[node] = node;
        }

        if (node == 0 && rem[node] != -1) {
            anscount++;
            ans[depth[node]].pb({node, rem[node]});
        }
    };

    dfs(0, -1);

    cout << anscount << '\n';
    rep(i, 0, n) {
        for (pii p : ans[i]) {
            cout << p.first + 1 << " " << p.second + 1 << '\n';
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