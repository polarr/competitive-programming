/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-07
 * Contest: 
 * Problem: C
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

    vector<set<pii>> adj(n);
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].insert({b, i});
        adj[b].insert({a, i});
    }

    vi s(n);
    rep(i, 0, n) {
        cin >> s[i];
        --s[i];
    }

    vi ans(m, 1);

    int curr = 1e9;
    int idx = 1;

    bool impossible = false;
    bool completed = false;

    vector<bool> visited(n, false);
    function<void(int, int)> dfs;
    dfs = [&](int node, int par) {
        if (idx == n) {
            completed = true;
            return;
        }
        visited[node] = true;
        auto pNode = adj[node].upper_bound({par, -1});
        if (pNode != adj[node].end() && (*pNode).first == par) {
            adj[node].erase(pNode);
        }
        while (!adj[node].empty()) {
            int x = s[idx];
            auto xNode = adj[node].upper_bound({x, -1});
            if (xNode != adj[node].end() && (*xNode).first == x) {
                ans[(*xNode).second] = curr;
                curr--;
                adj[node].erase(xNode);
            } else {
                for (pii remain : adj[node]) {
                    if (!visited[remain.first]) {
                        impossible = true;
                        completed = true;
                        break;
                    }
                }

                adj[node] = {};
                return;
            }
            idx++;
            dfs(x, node);
            if (completed) return;
        }
    };

    if (s[0] != 0) {
        cout << "impossible" << endl;
        return;
    }

    dfs(0, -1);

    if (impossible) {
        cout << "impossible" << endl;
        return;
    }

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}