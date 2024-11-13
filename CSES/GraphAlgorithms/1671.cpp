/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-12
 * Contest: CSES Problemset - Graph Algorithms
 * Problem: 1672
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
    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        ll c; cin >> c;

        adj[a].pb({b, c});
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[0] = 0;
    pq.push({0LL, 0});

    while(!pq.empty()){
        auto [ndist, n] = pq.top();
        pq.pop();

        if (ndist != dist[n]) { continue; }

        for (pair<int, ll> &node: adj[n]){
            if (ndist + node.second < dist[node.first]){
                dist[node.first] = ndist + node.second;
                pq.push({dist[node.first], node.first});
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << dist[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}