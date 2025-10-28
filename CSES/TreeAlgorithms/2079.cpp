/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-27
 * Contest: CSES Problemset
 * Problem: 2079
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
    int n; cin >> n;
    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = 0;
    vi st_size(n, 1);
    function<void(int, int)> dfs1, dfs2;
    dfs1 = [&](int node, int par){
        for (int x : adj[node]){
            if (x == par) continue;
            dfs1(x, node);
            st_size[node] += st_size[x];
        }
    };

    dfs2 = [&](int node, int par){
        int centroid = -1;
        for (int x : adj[node]){
            if (x == par) continue;
            if (st_size[x] > n/2){
                centroid = x;
            }
        }

        if (centroid == -1){
            ans = node;
            return;
        }

        dfs2(centroid, node);
    };

    dfs1(0, -1);
    dfs2(0, -1);

    cout << ans + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}