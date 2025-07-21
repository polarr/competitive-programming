/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-20
 * Contest: 
 * Problem: D
**/

#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
const ll INF = LLONG_MAX;

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> adj(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll k = 3 * n;

    int d[n * k][2];
    rep(i, 0, n * k){
        rep(j, 0, 2){
            d[i][j] = INT_MAX;
        }
    }

    d[0][0] = 0;
    d[0][1] = 0;
    deque<int> dq;
    dq.push_front(0);
    deque<int> q;
    while (!q.empty() || !dq.empty()) {
        if (q.empty()){
            q = dq;
            dq = {};
        }

        int v = q.front();
        q.pop_front();

        int i = v/k;
        int j = v % k;
        if (j == k - 1) continue;
        int target = adj[i][j % adj[i].size()];
        int targetnode = target * k + j + 1;
        vector<pii> a = {{v + 1, 1}, {targetnode, 0}};
        for (auto edge : a) {
            int u = edge.first;
            pii w = {1, edge.second};
            pii nx = {d[v][0] + 1, d[v][1] + edge.second};
            if (nx.first < d[u][0] || (nx.first == d[u][0] && nx.second < d[u][1])) {
                d[u][0] = nx.first;
                d[u][1] = nx.second;
                if (w.second == 1)
                    dq.push_back(u);
                else
                    dq.push_front(u);
            }
        }
    }

    rep(i, 0, k){
        if (d[(n - 1) * k + i][0] != INT_MAX){
            cout << d[(n - 1) * k + i][0] << " " << d[(n - 1) * k + i][1] << endl;
            return;
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