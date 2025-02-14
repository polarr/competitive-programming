
/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-13
 * Contest: POI 2016
 * Problem: parade
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

vector<vi> adj;
vector<bool> visited;
vl dp, dp1, dp2;

void dfs(int node){
    visited[node] = true;

    ll a = -1, b = -1;

    for (int x : adj[node]){
        if (visited[x]){
            continue;
        }

        dfs(x);

        if (dp[x] <= a){
            b = max(b, dp[x]);
        } else {
            b = a;
        }

        a = max(a, dp[x]);
    }

    if (a == -1){
        dp[node] = 1;
        dp1[node] = 0;
        dp2[node] = 0;
        return;
    }

    dp1[node] = (ll)adj[node].size() - 2 + a;
    dp[node] = max((ll)adj[node].size(), dp1[node]);

    if (b == -1){
        dp2[node] = 0;
        return;
    }

    dp2[node] = (ll)adj[node].size() - 4 + a + b;
}

void solve(){
    int n; cin >> n;
    adj = vector<vi>(n);
    visited = vector<bool>(n, false);
    dp = vl(n, 0), dp1 = vl(n, 0), dp2 = vl(n, 0);

    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0);

    ll ans = 0;
    rep(i, 0, n){
        ans = max(ans, dp1[i]);
        ans = max(ans, dp2[i]);
    }

    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}