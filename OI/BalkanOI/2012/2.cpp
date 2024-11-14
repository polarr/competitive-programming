/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-13
 * Contest: Balkan OI 2012
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    /** NOTE: incomplete, incorrect idea */
    int n, m, a, b; cin >> n >> m >> a >> b;
    --a; --b;

    int dist[n];
    fill(dist, dist + n, INT_MAX);
    int tdist[n];
    bool lucky[n];
    fill(lucky, lucky + n, false);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        --u; --v;

        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    int k; cin >> k;
    int paths[k];
    for (int i = 0; i < k; i++){
        int curr; cin >> curr;
        --curr;
        lucky[curr] = true;
        paths[i] = curr;
    }

    using T = pair<int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[a] = 0;

    pq.push({0, a});
    while(!pq.empty()){
        auto [ndist, nn] = pq.top();
        pq.pop();

        if (ndist != dist[nn]) { continue; }

        for (pair<int, int> &node: adj[nn]){
            ll nd = ndist + node.second;
            if (nd < dist[node.first]){
                dist[node.first] = nd;
                pq.push({nd, node.first});
            }
        }
    }

    for (int i = 0; i < k - 1; i++){
        int pa = paths[i], pb = paths[i + 1];
        lucky[pa] = false;

        fill(tdist, tdist + n, INT_MAX);
        tdist[a] = 0;
        pq.push({0, a});
        while(!pq.empty()){
            auto [ndist, nn] = pq.top();
            pq.pop();

            if (ndist != tdist[nn]) { continue; }

            if (lucky[nn]){
                tdist[b] = tdist[nn] + dist[b] - dist[nn];
                break;
            }

            for (pair<int, int> &node: adj[nn]){
                if (nn == pa && node.first == pb || nn == pa && node.first == pb){
                    continue;
                }
                ll nd = ndist + node.second;
                if (nd < tdist[node.first]){
                    tdist[node.first] = nd;
                    pq.push({nd, node.first});
                }
            }
        }

        cout << (tdist[b] == INT_MAX ? -1 : tdist[b]) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}