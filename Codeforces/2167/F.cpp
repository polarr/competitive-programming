/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-13
 * Contest: 
 * Problem: F
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
    int n, k; cin >> n >> k;

    vector<vi> adj(n);

    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi subtr(n, 1);

    ll ans = 0;
    
    function<void(int, int)> dfs;
    dfs = [&](int node, int par){
        ans++;
        for (int x : adj[node]){
            if (x == par) continue;
            dfs(x, node);
            subtr[node] += subtr[x];
        }

        if (subtr[node] >= k){
            ans += n - subtr[node];
        }

        for (int x : adj[node]){
            if (x == par) continue;
            if (n - subtr[x] >= k){
                ans += subtr[x];
            }
        }
    };

    dfs(0, -1);

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