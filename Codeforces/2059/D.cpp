/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-11
 * Contest: Codeforces 2059
 * Problem: D
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

ll INF = 1e19;
vl dijkstra(int n, vector<vector<pair<int, ll>>> &adj, int x){
    vl d(n, INF);
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
    int n; cin >> n;

    int s1, s2; cin >> s1 >> s2;
    --s1; --s2;

    int m1; cin >> m1;

    vector<vi> adj1(n), adj2(n);
    rep(i, 0, m1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj1[a].pb(b);
        adj1[b].pb(a);
    }

    int m2; cin >> m2;

    rep(i, 0, m2){
        int a, b; cin >> a >> b;
        --a; --b;
        adj2[a].pb(b);
        adj2[b].pb(a);
    }

    auto encode = [&](int i, int j){
        return i * n + j;
    };

    vector<vector<pair<int, ll>>> adj(n * n);

    vi good;

    rep(i, 0, n){
        rep(j, 0, n){
            bool good1 = (i == j);
            int node = encode(i, j);
            for (int ii : adj1[i]){
                for (int jj : adj2[j]){
                    bool good2 = (ii == jj);
                    int nx = encode(ii, jj);
                    if (good1 && good2){
                        good.pb(encode(i, j));
                    }

                    adj[node].pb({nx, abs(ii - jj)});
                }
            }
        }
    }

    vl d = dijkstra(n * n, adj, encode(s1, s2));

    ll ans = LLONG_MAX;

    for (int possible : good){
        ans = min(ans, d[possible]);
    }

    if (ans == LLONG_MAX){
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
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