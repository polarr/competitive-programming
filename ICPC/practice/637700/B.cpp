/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-24
 * Contest: 
 * Problem: B
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
const ll INF = LLONG_MAX;

/** 
 * ALGORITHM: Dijkstra's Algorithm
 * PURPOSE: Finds shortest path in nonnegative weighted simple graph from node x to all nodes
 * TIME: O(V + E)
*/
vi dijkstra(int n, vector<vector<pair<int, ll>>> &adj, int x){
    vector<ll> d(n, INF);
    vi firstDis(n, -1);
    d[x] = 0;

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    pq.push({0, x});

    while(!pq.empty()){
        auto [dist, k] = pq.top();
        pq.pop();

        if (dist != d[k]) { continue; }

        for (pair<int, ll> &node: adj[k]){
            if (dist + node.second < d[node.first]){
                firstDis[node.first] = k;
                d[node.first] = dist + node.second;
                pq.push({d[node.first], node.first});
            }
        }
    }

    vi ans;
    if (d[n - 1] == INF){
        return {};
    }
    int curr = n - 1;
    while (curr != -1){
        ans.pb(curr);
        curr = firstDis[curr];
    }
    reverse(all(ans));

    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n);
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        if (a == b) continue;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    rep(i, 0, n){
        sort(all(adj[i]));
        vector<pair<int, ll>> x;
        int curr = -1;
        ll mn = INF;
        rep(j, 0, adj[i].size()){
            if (adj[i][j].first != curr){
                if (curr != -1){
                    x.pb({curr, mn});
                }

                curr = adj[i][j].first;
                mn = adj[i][j].second;
            }

            mn = min(mn, adj[i][j].second);
        }

        if (curr != -1){
            x.pb({curr, mn});
        }

        adj[i] = x;
    }

    vi ans = dijkstra(n, adj, 0);
    if (ans.size() == 0){
        cout << -1 << endl;
        return;
    }
    for (int x : ans){
        cout << x + 1 << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}