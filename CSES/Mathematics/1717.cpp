/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-14
 * Contest: CSES Problemset
 * Problem: 1717
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
    vl dp(n + 1, 0);
    dp[0] = 1; dp[1] = 0;
    ll a = 1;
    rep(i, 2, n + 1){
        dp[i] = a;
        a += dp[i - 1];
        a %= MOD;
        a *= i;
        a %= MOD;
    }

    cout << dp[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}