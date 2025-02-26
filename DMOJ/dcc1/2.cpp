/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-21
 * Contest: DMOJ dcc1
 * Problem: 2
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

ll sqsum(ll x){
    return x * (x + 1) % MOD * (2 * x + 1) % MOD * 166374059 % MOD;
}

void solve(){
    ll ans = 1;
    ll a, b; cin >> a >> b;
    if (a > b){
        swap(a, b);
    }

    ll rta = sqrt(a), rtb = sqrt(b), rts = sqrt(a + b);

    ans += sqsum(rta);
    ans %= MOD;
    ans += rta;
    ans %= MOD;

    ans += (a + 1) % MOD * (rtb - rta) % MOD;
    ans %= MOD;
    

    ans += (a + b + 1) % MOD * (rts - rtb) % MOD;
    ans %= MOD;
    ans += sqsum(rtb) + MOD - sqsum(rts);
    ans %= MOD;

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