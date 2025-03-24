/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-21
 * Contest: DMOJ ahscc2
 * Problem: 5
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
 * ALGORITHM: Dijkstra's Algorithm
 * PURPOSE: Finds shortest path in nonnegative weighted simple graph from node x to all nodes
 * TIME: O(V + E)
*/
vector<ll> dijkstra(int n, vector<vector<pair<int, ll>>> &adj, int x){
    vector<ll> d(n, LLONG_MAX);
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
                d[node.first] = dist + node.second;
                pq.push({d[node.first], node.first});
            }
        }
    }

    return d;
}

void solve(){
    int n, m, k; ll t; cin >> n >> m >> k >> t;

    vector<vector<pair<int, ll>>> adj(k + 1);

    vi ext(n, 0);

    int j = 1;

    rep(i, 0, k) {
        int x; cin >> x;
        --x;
        ext[x] = j++;
    }
    
    rep(i, 0, m){
        int x, y; ll d; cin >> x >> y >> d;
        --x; --y;
        x = ext[x], y = ext[y];

        adj[x].pb({y, d});
        adj[y].pb({x, d});
    }

    // rep(i, 0, k + 1){
    //     sort(all(adj[i]));
    //     vector<pair<int, ll>> r;
    //     rep(j, 0, adj[i].size()){
    //         if (j == 0 || adj[i][j].first != adj[i][j - 1].first){
    //             r.pb(adj[i][j]);
    //         }
    //     }

    //     adj[i] = r;
    // }

    vl d = dijkstra(k + 1, adj, 0);

    rep(i, 0, n){
        if (ext[i] == 0){
            cout << 0;
            continue;
        }

        int j = ext[i];

        if (d[j] > t){
            cout << 1;
        } else {
            cout << 0;
        }
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}