/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-08
 * Contest: IOI 2011
 * Problem: crocodile
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

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n);

    rep(i, 0, m){
        int a, b; ll c; cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    vector<pair<ll, ll>> d(n, {LLONG_MAX, LLONG_MAX});
    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    rep(i, 0, k){
        int x; cin >> x;
        d[x] = {0, 0};
        pq.push({0, x});
    }

    while(!pq.empty()){
        auto [dist, k] = pq.top();
        pq.pop();

        if (dist != d[k].second) { continue; }

        for (auto &[node, c] : adj[k]){
            ll ndist = dist + c;
            if (ndist < d[node].first){
                if (d[node].first < d[node].second){
                    pq.push({d[node].first, node});
                }
                d[node].second = d[node].first;
                d[node].first = ndist;
            }
            else if (ndist < d[node].second){
                d[node].second = ndist;
                pq.push({ndist, node});
            }
        }
    }

    cout << d[0].second << endl;

    // bad but fun idea lol... just reinventing dijkstra terribly wrongly
    // while(dp[0] == LLONG_MAX){
    //     stack<int> rev;

    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();
    //         rev.push(node);
    //         escape[node] = true;
    //         ll mn1 = LLONG_MAX, mn2 = LLONG_MAX;
    //         for (auto &[x, c] : adj[node]){
    //             if (!escape[x]){
    //                 continue;
    //             }

    //             ll a = c + dp[x];

    //             if (a >= mn1){
    //                 mn2 = min(mn2, a);
    //             } else {
    //                 mn2 = mn1;
    //                 mn1 = a;
    //             }
    //         }
    //         dp[node] = mn2;
    //     }

    //     while(!rev.empty()){
    //         int node = rev.top();
    //         rev.pop();
    //         ll mn1 = LLONG_MAX, mn2 = LLONG_MAX;
    //         for (auto &[x, c] : adj[node]){
    //             if (!assigned[x]){
    //                 deg[x]++;
    //                 if (deg[x] > 1){
    //                     assigned[x] = true;
    //                     q.push(x);
    //                 }
    //                 continue;
    //             }

    //             ll a = c + dp[x];

    //             if (a >= mn1){
    //                 mn2 = min(mn2, a);
    //             } else {
    //                 mn2 = mn1;
    //                 mn1 = a;
    //             }
    //         }
    //         dp[node] = mn2;
    //     }
    // }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}