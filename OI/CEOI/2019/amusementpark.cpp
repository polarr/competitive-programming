/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-08
 * Contest: CEOI 2019
 * Problem: amusementpark
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
const ll MOD = 998244353;

void solve(){
    ll n, m; cin >> n >> m;
    vector<int> adj(n, 0);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a] += (1 << b);
        adj[b] += (1 << a);
    }

    // legal = DAG, pair for m
    // consider counting toposort orderings, bijection under indegree 0 "front elements", but the front set must be independent

    int which[1 << n];
    rep(i, 0, n){
        which[1 << i] = i;
    }

    bool indep[1 << n];
    ll ones[1 << n];
    ones[0] = -1;
    indep[0] = true;

    rep(i, 1, 1 << n){
        int prevmask = i & (i - 1);
        int lsb = i ^ prevmask;
        ones[i] = -ones[prevmask];
        if (indep[prevmask] && ((adj[which[lsb]] & prevmask) == 0)){
            indep[i] = true;
        } else {
            indep[i] = false;
        }
    }

    vl dp(1 << n, 0);
    dp[0] = 1;
    rep(i, 1, 1 << n){
        for (int j = i; j != 0; j = (j - 1) & i){
            if (indep[j]){
                // PIE
                dp[i] = (2 * MOD + dp[i] + ones[j] * dp[i ^ j]) % MOD;
            }
        }
    }

    cout << m * dp[(1 << n) - 1] % MOD * (MOD + 1)/2 % MOD << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}