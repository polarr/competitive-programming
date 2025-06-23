/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-23
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

    vector<vi> adj(n);

    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<pii> ans;
    bool found = false;

    function<void(int, int, int)> dfs;

    dfs = [&](int x, int par, bool d){
        for (int node : adj[x]){
            if (node == par) continue;

            bool dir = !d;

            if (!found && adj[x].size() == 2){
                found = true;
                dir = !dir;
            }

            if (dir){
                ans.pb({x, node});
            } else {
                ans.pb({node, x});
            }

            dfs(node, x, dir);
        }
    };

    dfs(0, -1, 0);

    if (!found){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    for (pii ansi : ans){
        cout << ansi.first + 1 << " " << ansi.second + 1 << endl;
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