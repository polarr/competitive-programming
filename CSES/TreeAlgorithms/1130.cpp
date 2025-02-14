/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-11
 * Contest: CSES Problemset
 * Problem: 1130
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
vi dp1, dp2;

void dfs(int node){
    visited[node] = true;

    bool isLeaf = true;

    int a = 0, b = INT_MIN;

    for (int x : adj[node]){
        if (visited[x]){
            continue;
        }

        dfs(x);

        a += dp1[x];
        b = max(b, 1 + dp2[x] - dp1[x]);
    }

    if (b == INT_MIN){
        dp1[node] = 0;
        dp2[node] = 0;
        return;
    }

    dp1[node] = max(a, a + b);
    dp2[node] = a;
}

void solve(){
    int n; cin >> n;
    adj = vector<vi>(n);
    visited = vector<bool>(n, false);
    dp1 = vi(n), dp2 = vi(n);

    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0);

    cout << dp1[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}