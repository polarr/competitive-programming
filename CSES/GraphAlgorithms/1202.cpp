/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-13
 * Contest: CSES Problemset - Graph Algorithms
 * Problem: 1202
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

    vector<ll> dist(n, 1e15);
    vector<int> ways(n, 0);
    vector<int> minFlight(n, 1e9);
    vector<int> maxFlight(n, 0);
    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        ll c; cin >> c;

        adj[a].pb({b, c});
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    ways[0] = 1;
    minFlight[0] = 0;
    maxFlight[0] = 0;
    dist[0] = 0;
    pq.push({0LL, 0});

    while(!pq.empty()){
        auto [ndist, k] = pq.top();
        pq.pop();

        if (ndist != dist[k]) { continue; }

        for (pair<int, ll> &node: adj[k]){
            if (ndist + node.second == dist[node.first]){
                minFlight[node.first] = min(minFlight[node.first], minFlight[k] + 1);
                maxFlight[node.first] = max(maxFlight[node.first], maxFlight[k] + 1);
                ways[node.first] += ways[k];
                ways[node.first] %= MOD;
            }

            if (ndist + node.second < dist[node.first]){
                dist[node.first] = ndist + node.second;
                ways[node.first] = ways[k];
                minFlight[node.first] = minFlight[k] + 1;
                maxFlight[node.first] = maxFlight[k] + 1;
                pq.push({dist[node.first], node.first});
            }
        }
    }

    cout << dist[n - 1] << " " << ways[n - 1] << " " << minFlight[n - 1] << " " << maxFlight[n - 1] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}