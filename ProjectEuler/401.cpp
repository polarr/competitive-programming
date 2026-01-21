/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-20
 * Contest: 
 * Problem: 401
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
const ll MOD = 1e9;

void solve(){
    ll n = 1e15;

    auto sqsum = [&](ll x) -> ll {
        ll a = x, b = x + 1, c = 2 * x + 1;
        if (x % 2 == 0) {
            a /= 2;
        } else {
            b /= 2;
        }

        if (x % 3 == 0) {
            a /= 3;
        } else if (x % 3 == 2) {
            b /= 3;
        } else {
            c /= 3;
        }

        a %= MOD;
        b %= MOD;
        c %= MOD;

        return a % MOD * b % MOD * c % MOD;
    };

    ll ans = 0;
    ll rt = sqrt(n);
    for (ll d = 1; d <= rt; d++) {
        ans += d % MOD * d % MOD * (n/d % MOD) % MOD;
    }

    for (ll k = 1; k <= rt; k++) {
        ll hi = n/k;
        ll lo = max(rt + 1, (n + 1 + k)/(k + 1));

        if (lo > hi) continue;
        
        ll add = sqsum(hi);
        add += MOD - sqsum(lo - 1);
        add %= MOD;
        add *= k;
        add %= MOD;

        ans += add;
        ans %= MOD;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}