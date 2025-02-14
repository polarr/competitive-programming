
/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-13
 * Contest: Atcoder dp
 * Problem: P
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
vl dp1, dp2;

void dfs(int node){
    visited[node] = true;

    ll a = 1, b = 1;

    for (int x : adj[node]){
        if (visited[x]){
            continue;
        }

        dfs(x);

        a *= (dp1[x] + dp2[x]);
        a %= MOD;

        b *= dp1[x];
        b %= MOD;
    }

    dp1[node] = a;
    dp2[node] = b;
}

void solve(){
    int n; cin >> n;
    adj = vector<vi>(n);
    visited = vector<bool>(n, false);
    dp1 = vl(n), dp2 = vl(n);

    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0);

    cout << (dp1[0] + dp2[0]) % MOD << endl;
}

int main(){
    solve();
    return 0;
}