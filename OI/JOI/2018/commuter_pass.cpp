/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-13
 * Contest: JOI 2018
 * Problem: 4
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
    int s, t; cin >> s >> t;
    int u, v; cin >> u >> v;
    --s; --t; --u; --v;

    vector<ll> dist(n, 1e15);
    vector<ll> udist(n, 1e15);
    vector<ll> vdist(n, 1e15);
    vector<ll> minU(n, 1e15);
    vector<ll> minV(n, 1e15);
    vector<ll> minS(n, 1e15);
    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        ll c; cin >> c;

        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    udist[u] = 0;
    pq.push({0, u});

    // U dijkstra
    while(!pq.empty()){
        auto [ndist, k] = pq.top();
        pq.pop();

        if (ndist != udist[k]) { continue; }

        for (pair<int, ll> &node: adj[k]){
            if (ndist + node.second < udist[node.first]){
                udist[node.first] = ndist + node.second;
                pq.push({udist[node.first], node.first});
            }
        }
    }

    vdist[v] = 0;
    pq.push({0, v});

    // V dijkstra
    while(!pq.empty()){
        auto [ndist, k] = pq.top();
        pq.pop();

        if (ndist != vdist[k]) { continue; }

        for (pair<int, ll> &node: adj[k]){
            if (ndist + node.second < vdist[node.first]){
                vdist[node.first] = ndist + node.second;
                pq.push({vdist[node.first], node.first});
            }
        }
    }

    dist[s] = 0;
    minU[s] = udist[s];
    minV[s] = vdist[s];
    minS[s] = minU[s] + minV[s];
    pq.push({0, s});

    while(!pq.empty()){
        auto [ndist, k] = pq.top();
        pq.pop();

        if (ndist != dist[k]) { continue; }

        for (pair<int, ll> &node: adj[k]){
            if (ndist + node.second == dist[node.first]){
                minS[node.first] = min(minS[node.first], minS[k]);
                minS[node.first] = min(minS[node.first], minU[k] + vdist[node.first]);
                minS[node.first] = min(minS[node.first], minV[k] + udist[node.first]);
                minS[node.first] = min(minS[node.first], udist[node.first] + vdist[node.first]);
                minV[node.first] = min(minV[node.first], minV[k]);
                minU[node.first] = min(minU[node.first], minU[k]);
                //pq.push({dist[node.first], node.first});
            }

            else if (ndist + node.second < dist[node.first]){
                dist[node.first] = ndist + node.second;
                minS[node.first] = min(minS[k], minU[k] + vdist[node.first]);
                minS[node.first] = min(minS[node.first], minV[k] + udist[node.first]);
                minS[node.first] = min(minS[node.first], udist[node.first] + vdist[node.first]);
                minV[node.first] = min(minV[k], vdist[node.first]);
                minU[node.first] = min(minU[k], udist[node.first]);
                pq.push({dist[node.first], node.first});
            }
        }
    }

    cout << min(vdist[u], minS[t]) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}