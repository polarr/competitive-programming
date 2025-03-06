/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-01
 * Contest: APIO 2014
 * Problem: beads
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
    vector<vector<pii>> adj(n);
    rep(i, 0, n - 1){
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    if (n < 3){
        cout << 0 << endl;
        return;
    }

    // { any, cannot abb }
    vector<pii> dp(n);
    vi par(n);
    function<void(int, int, int)> dfs1;
    dfs1 = [&](int node, int parent, int last){
        int a = 0;
        int mx = INT_MIN;

        par[node] = parent;

        for (auto &[child, cost] : adj[node]){
            if (child == parent){
                continue;
            }

            dfs1(child, node, cost);

            a += dp[child].first;
            mx = max(mx, cost + dp[child].second - dp[child].first);
        }

        if (last != -1 && mx != INT_MIN){
            mx += a;
            mx += last;
        } else {
            mx = 0;
        }

        dp[node] = {max(a, mx), a};
    };

    // when 0 is the starting bead
    dfs1(0, -1, -1);

    vi brcost(n, 0);
    vector<multiset<int>> br(n);

    // precompute
    rep(i, 0, n){
        for (auto &[child, cost] : adj[i]){
            if (child == par[i]){
                continue;
            }

            br[i].insert(cost + dp[child].second - dp[child].first);
            brcost[i] += dp[child].first;
        }
    }

    int ans = dp[0].second;

    function<void(int)> dfs2;
    // transition to check when each node is the starting bead
    dfs2 = [&](int node){
        for (auto &[child, cost] : adj[node]){
            if (child == par[node]){
                continue;
            }

            // no connect
            int x = brcost[node] - dp[child].first;
            ans = max(ans, x + dp[child].second);

            // connect
            int adjustment = cost + dp[child].second - dp[child].first;
            br[node].erase(br[node].find(adjustment));

            if (!br[node].empty()){
                int c = *br[node].rbegin();
                ans = max(ans, c + x + cost + dp[child].second);

                int a = max(x, c + x + cost);

                br[child].insert(cost + x - a);
                brcost[child] += a;
            } else {
                ans = max(ans, dp[child].second);
                br[child].insert(cost);
            }

            br[node].insert(adjustment);

            dfs2(child);
        }
    };

    dfs2(0);

    cout << ans << endl;

    // previous direct dp attempt, does not work but maybe possible
    // dfs = [&](ll node, ll parent, ll last){
    //     ll a = INT_MIN, b1 = 0, b2 = 0, c = INT_MIN;
    //     ll mx1 = INT_MIN, mx2 = INT_MIN;

    //     ll x = 0;

    //     for (auto &[child, cost] : adj[node]){
    //         if (child == parent){
    //             continue;
    //         }

    //         dfs(child, node, cost);

    //         c = max(c, dp[child][0] - dp[child][2]);
    //         x += dp[child][2];

    //         if (last != -1){
    //             b1 = max(b1, last + cost + dp[child][3] - dp[child][2]);
    //             b2 = max(b2, last + cost + dp[child][4] - dp[child][2]);
    //         }

    //         ll change1 = cost + dp[child][3] - dp[child][2];
    //         ll change2 = cost + dp[child][4] - dp[child][2];

    //         a = max(a, change1 + mx2);
    //         a = max(a, change2 + mx1);

    //         mx1 = max(mx1, change1);
    //         mx2 = max(mx2, change2);
    //     }

    //     if ((parent == -1 && adj[node].size() == 1) || adj[node].size() > 1){
    //         c += x;
    //     } else {
    //         c = 0;
    //     }

    //     if ((parent == -1 && adj[node].size() == 2) || adj[node].size() > 2){
    //         a += x;
    //     } else {
    //         a = 0;
    //     }

    //     if (last != -1){
    //         b1 += x;
    //         b2 += x;
    //     } else {
    //         b1 = 0;
    //         b2 = 0;
    //     }

    //     ll b = max(b1, b2);

    //     ll ac = max(a, c);

    //     dp[node] = {max(ac, b), max(ac, b1), max(ac, b2), ac, c};
    // };
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}