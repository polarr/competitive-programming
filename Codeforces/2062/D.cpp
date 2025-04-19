/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-18
 * Contest: Codeforces 2062
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
    vector<pii> ranges(n);
    rep(i, 0, n){
        int l, r; cin >> l >> r;
        ranges[i] = {l, r};
    }

    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll ans = 0;

    vl dp(n);

    vi par(n, -1);
    function<void(int)> dfs;
    dfs = [&](int node){
        ll mx = -1;
        for (int x : adj[node]){
            if (x == par[node]) continue;
            par[x] = node;
            dfs(x);
            mx = max(mx, dp[x]);
        }

        if (mx < ranges[node].first){
            dp[node] = ranges[node].first;
            return;
        }

        if (mx > ranges[node].second){
            for (int x : adj[node]){
                if (x == par[node]) continue;
                ans += max(0LL, dp[x] - ranges[node].second);
            }
            dp[node] = ranges[node].second;
            return;
        }

        dp[node] = mx;
    };

    dfs(0);

    cout << ans + dp[0] << endl;
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