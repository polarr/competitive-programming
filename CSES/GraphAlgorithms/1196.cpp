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
    int n, m, k; cin >> n >> m >> k;

    ll INF = 1e15;

    vector<multiset<ll>> dist(n, {INF});
    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        ll c; cin >> c;

        adj[a].pb({b, c});
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[0] = {0};
    pq.push({0LL, 0});

    auto add = [&](int nn, ll v){
        if ((int)dist[nn].size() == k && v >= *prev(dist[nn].end())){
            return false;
        }
        dist[nn].insert(v);
        if ((int)dist[nn].size() > k){
            dist[nn].erase(prev(dist[nn].end()));
        }

        return true;
    };

    while(!pq.empty()){
        auto [ndist, nn] = pq.top();
        pq.pop();

        if (!dist[nn].contains(ndist)) { continue; }

        for (pair<int, ll> &node: adj[nn]){
            ll nd = ndist + node.second;
            if (add(node.first, nd)){
                pq.push({nd, node.first});
            }
        }
    }

    for (ll d : dist[n - 1]){
        cout << d << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}