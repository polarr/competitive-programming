/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-13
 * Contest: JOI 2021
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
    /** NOTE: incomplete, correct idea but implementation tedious */
    int n, m; cin >> n >> m;

    vector<ll> dist(n, 1e15);
    map<pair<int, int>, vector<pair<int, int>>> multiple;
    map<pair<int, int>, ll> colorSum;
    vector<vector<tuple<int, int, ll>>> adj(n);
    for (int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        --a; --b; --c;
        ll d; cin >> d;

        colorSum[{a, c}] += d;
        multiple[{a, c}].pb({b, d});
        colorSum[{b, c}] += d;
        multiple[{b, c}].pb({a, d});

        adj[a].pb({b, c, d});
        adj[b].pb({a, c, d});
    }

    using T = tuple<ll, int, int, int, bool, ll>;
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[0] = 0;
    pq.push({0LL, 0, -1, -1, true, 0LL});

    while(!pq.empty()){
        auto [ndist, k, c, prevk, prevchange, len] = pq.top();
        pq.pop();

        if (ndist != dist[k]) { continue; }

        map<int, ll> minPastColor;

        for (tuple<int, int, ll> &node: adj[k]){
            int kk = get<0>(node);
            if (kk == 0 || kk == prevk){
                continue;
            }
            int color = get<1>(node);
            ll cost = get<2>(node);
            bool changed = true;

            if (c != color || !prevchange){
                ll minPast = LLONG_MAX;
                ll other = colorSum[{k, color}];
                other -= cost;

                if (!minPastColor.contains(color)){
                    for (pair<int, int> &prevNode: multiple[{k, color}]){
                        if (prevNode.first == kk || prevNode.first == prevk){
                            continue;
                        }
                        minPast = min(minPast, dist[prevNode.first]);
                    }

                    minPastColor[color] = minPast;
                } else {
                    minPast = minPastColor[color];
                }

                minPast = min(ndist, minPast);

                if (minPast + other < ndist + cost){
                    ndist = minPast;
                    cost = other;
                    changed = false;
                }
            } else {
                ll other = colorSum[{k, color}] - cost - len;
            
                if (other < cost){
                    cost = other;
                    changed = false;
                }
            }

            if (ndist + cost < dist[kk]){
                dist[kk] = ndist + cost;
                pq.push({dist[kk], kk, color, k, changed, get<2>(node)});
            } else if (ndist + cost == dist[kk] && changed){
                pq.push({dist[kk], kk, color, k, changed, get<2>(node)});
            }

            /**
            else if (multiple[{kk, color}].size() == 2){
                int t = multiple[{kk, color}][0].first;
                if (t == k){
                    t = multiple[{kk, color}][1].first;
                }
                if (ndist + get<2>(node) < dist[t]){
                    dist[t] = ndist + get<2>(node);
                    pq.push({dist[t], t, color});
                }
            }
            **/
        }
    }

    cout << (dist[n - 1] == 1e15 ? -1: dist[n - 1])<< endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}