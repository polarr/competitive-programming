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
    int n, m, q; cin >> n >> m >> q;

    vector<vector<ll>> dist(n, vector<ll>(n, 1e15));

    for (int i = 0; i < n; i++){
        dist[i][i] = 0LL;
    }
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        ll c; cin >> c;
        --a; --b;
        c = min(c, dist[a][b]);
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        --a; --b;

        cout << (dist[a][b] == 1e15 ? -1 : dist[a][b]) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}