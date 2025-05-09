/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-08
 * Contest: Baltic OI 2019
 * Problem: valley
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

/** 
 * ALGORITHM: Euler Tour
 * PURPOSE: Flattens a tree so that each range contains any subtree range
 * CONSTRAINT: Graph must be a tree
 * TIME: O(V)
*/
vector<pii> eulerTour(int n, int rt, vector<vector<int>> &adj){
    vector<pii> ans(n);
    int i = -1;
    function<void(int, int)> tour;
    tour = [&](int node, int parent){
        ans[node].first = ++i;
        for (int x : adj[node]){
            if (x != parent){
                tour(x, node);
            }
        }
        ans[node].second = ++i;
    };

    // root at 0
    tour(rt, -1);

    return ans;
}

void solve(){
    int n, s, q, e; cin >> n >> s >> q >> e;
    --e;

    vector<vi> adj(n);
    vector<vector<pair<int, ll>>> adjl(n);
    vector<pii> edges;
    vector<bool> shop(n, false);
    rep(i, 0, n - 1){
        int a, b; ll w; cin >> a >> b >> w;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
        edges.pb({a, b});
        adjl[a].pb({b, w});
        adjl[b].pb({a, w});
    }

    vector<pii> tour = eulerTour(n, e, adj);

    rep(i, 0, s){
        int c; cin >> c;
        --c;

        shop[c] = true;
    }

    vl dp(n, 1e18);
    vi par(n, -1);
    vi depth(n, 0);
    vl d(n, 0LL);

    function<void(int, int)> dfs;
    dfs = [&](int x, int parent){
        if (shop[x]) {
            dp[x] = d[x];
        }

        for (auto &[node, dist] : adjl[x]){
            if (node == parent){
                continue;
            }

            par[node] = x;
            depth[node] = depth[x] + 1;
            d[node] = d[x] + dist;
            dfs(node, x);

            dp[x] = min(dp[x], dp[node]);
        }
    };

    dfs(e, -1);
    rep(i, 0, n){
        if (dp[i] != 1e18) dp[i] -= 2LL * d[i];
    }

    int lg = log2(n) + 1;
    vector<vector<pair<int, ll>>> jump(n, vector<pair<int, ll>>(lg, {-1, 1e18}));

    rep(i, 0, n){
        int p = par[i];
        if (p == -1) continue;
        jump[i][0].first = p;
        jump[i][0].second = min(dp[i], dp[p]);
    }

    rep(i, 1, lg){
        rep(j, 0, n){
            int p = jump[j][i - 1].first;
            if (p == -1) continue;
            jump[j][i].first = jump[p][i - 1].first;
            jump[j][i].second = min(jump[j][i - 1].second, jump[p][i - 1].second);
        }
    }

    rep(i, 0, q){
        int j, r; cin >> j >> r;
        --j; --r;

        pii edge = edges[j];
        int sub = edge.first; 
        if (depth[edge.second] > depth[edge.first]){
            sub = edge.second;
        }

        if (tour[r].first < tour[sub].first || tour[r].first > tour[sub].second){
            cout << "escaped" << endl;
            continue;
        }

        if (shop[r]){
            cout << 0 << endl;
            continue;
        }

        int dist = depth[r] - depth[sub];

        ll mn = dp[r];
        int pos = r;
        for (int j = lg - 1; j >= 0; j--){
            if (dist & (1 << j)){
                mn = min(mn, jump[pos][j].second);
                pos = jump[pos][j].first;
            }
        }

        if (mn == 1e18){
            cout << "oo" << endl;
            continue;
        }

        cout << mn + d[r] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}