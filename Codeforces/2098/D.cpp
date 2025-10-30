/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-29
 * Contest: Codeforces 2098
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

void solve(){
    int n, m; cin >> n >> m;
    int k; cin >> k;

    auto idx = [&](int x, int y) {
        return x * m + y;
    };

    vector<bool> taken(n * m, false);
    ll ans = 1;
    auto take = [&](int x, int y){
        if (taken[idx(x, y)]){
            ans = 0;
        }

        taken[idx(x, y)] = true;
    };

    vector<vi> adj(n * m);
    pii at;
    cin >> at.first >> at.second;
    at.first--; at.second--;
    
    take(at.first, at.second);

    rep(i, 0, k){
        int x, y; cin >> x >> y;
        --x; --y;

        take(x, y);
        
        int dist = abs(at.first - x) + abs(at.second - y);
        if (dist != 2){
            ans = 0;
            at.first = x;
            at.second = y;
            continue;
        }

        if (abs(at.first - x) != 1){
            int mx = (at.first + x)/2;
            int my = (at.second + y)/2;

            take(mx, my);
        } else {
            int x1 = at.first, y1 = y;
            int x2 = x, y2 = at.second;

            adj[idx(x1, y1)].pb(idx(x2, y2));
            adj[idx(x2, y2)].pb(idx(x1, y1));
        }
        
        at.first = x;
        at.second = y;
    }

    if (ans == 0){
        cout << 0 << endl;
        return;
    }

    vector<bool> visited(n * m, false);
    ll deg = 0, cnt = 0, took = 0;
    function<void(int)> dfs;
    dfs = [&](int node){
        if (visited[node]) return;
        visited[node] = true;
        if (taken[node]){
            took++;
        }
        deg += adj[node].size();
        cnt++;
        for (int x : adj[node]){
            dfs(x);
        }
    };

    rep(i, 0, n * m){
        if (visited[i] || adj[i].empty()) continue;

        deg = 0;
        cnt = 0;
        took = 0;
        dfs(i);
        deg /= 2;

        cnt -= took;

        if (deg > cnt){
            ans *= 0;
        } else if (deg == cnt){
            if (took == 0) ans *= 2LL;
            ans %= MOD;
        } else {
            ans *= cnt % MOD;
            ans %= MOD;
        }
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