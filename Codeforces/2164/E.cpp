/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-22
 * Contest: 
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
    int n, m; cin >> n >> m;

    using T = array<ll, 2>;
    vector<vector<T>> adj(n);
    vector<array<ll, 3>> edges(m);

    vi deg(n, 0);
    ll ans = 0;
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        ll w; cin >> w;
        --a; --b;
        ans += w;
        edges[i] = {a, b, w};
        adj[a].pb({b, w});
        adj[b].pb({a, w});
        deg[a]++;
        deg[b]++;
    }

    int curr = n;
    vi comp(n + m), par(n + m, -1);
    vl cost(n + m);
    rep(i, 0, n) {
        comp[i] = i;
    }

    function<int(int)> find;
    find = [&](int x) {
        return (comp[x] == x ? x : (comp[x] = find(comp[x])));
    };

    vector<vi> child(n + m);

    rep(i, 0, m) {
        auto [a, b, w] = edges[i];
        int A = find(a);
        int B = find(b);

        comp[curr] = curr;
        comp[A] = curr;
        comp[B] = curr;
        par[A] = curr;
        par[B] = curr;
        child[curr].pb(A);
        if (B != A) child[curr].pb(B);

        cost[curr] = w;
        curr++;
    }

    curr--;
    function<vi(int, ll)> dfs;
    dfs = [&](int node, ll val) -> vi {
        if (node < n) {
            if (deg[node] % 2 == 1) {
                return {node};
            }

            return {};
        }

        val = min(val, cost[node]);
        vi has;
        for (int x : child[node]) {
            vi a = dfs(x, val);
            if (!a.empty()) {
                has.pb(a[0]);
            }
        }

        if (sz(has) == 2) {
            ans += val;
            has = {};
        }

        return has;
    };

    dfs(curr, LLONG_MAX);

    cout << ans << endl;
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