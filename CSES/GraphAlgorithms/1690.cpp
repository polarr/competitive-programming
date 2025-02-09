/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-08
 * Contest: CSES Problemset
 * Problem: 1690
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
    vector<vector<int>> adj(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[b].pb(a);
    }

    vector<vl> dp(1 << n, vl(n, 0));
    dp[0][0] = 0;
    dp[1][0] = 1;

    rep(i, 0, 1 << n){
        if (!(i & 1)){
            continue;
        }
        if ((i & (1 << n)) && i != (1 << n) - 1){
            continue;
        }
        rep(j, 0, n){
            if (!(i & (1 << j))){
                continue;
            }

            for (int x : adj[j]){
                if (!(i & (1 << x))){
                    continue;
                }
                dp[i][j] += dp[i ^ (1 << j)][x];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}