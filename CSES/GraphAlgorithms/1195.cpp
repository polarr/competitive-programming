/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-12
 * Contest: CSES Problemset - Graph Algorithms
 * Problem: 1195
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;

    vector<ll> sdist(n, 1e15);
    vector<ll> edist(n, 1e15);
    vector<vector<pair<int, ll>>> adj(n);
    vector<vector<pair<int, ll>>> radj(n);
    vector<pair<int, int>> edges(m);
    map<pair<int, int>, ll> edgemap;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        ll c; cin >> c;
        
        edges[i] = {a, b};
        if (edgemap[{a, b}] == 0){
            edgemap[{a, b}] = c;
        } else {
            edgemap[{a, b}] = min(c, edgemap[{a, b}]);
        }
        adj[a].pb({b, c});
        radj[b].pb({a, c});
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    sdist[0] = 0;
    pq.push({0LL, 0});

    while(!pq.empty()){
        auto [ndist, k] = pq.top();
        pq.pop();

        if (ndist != sdist[k]) { continue; }

        for (pair<int, ll> &node: adj[k]){
            if (ndist + node.second < sdist[node.first]){
                sdist[node.first] = ndist + node.second;
                pq.push({sdist[node.first], node.first});
            }
        }
    }

    edist[n - 1] = 0;
    pq.push({0LL, n - 1});

    while(!pq.empty()){
        auto [ndist, k] = pq.top();
        pq.pop();

        if (ndist != edist[k]) { continue; }

        for (pair<int, ll> &node: radj[k]){
            if (ndist + node.second < edist[node.first]){
                edist[node.first] = ndist + node.second;
                pq.push({edist[node.first], node.first});
            }
        }
    }

    ll ans = LLONG_MAX;

    for (int i = 0; i < m; i++){
        auto [a, b] = edges[i];
        ll c = edgemap[edges[i]];
        ans = min(ans, c/2 + sdist[a] + edist[b]);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}