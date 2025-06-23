/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-22
 * Contest: Codeforces 2075
 * Problem: E
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

/** 
 * ALGORITHM: Modular Exponentiation 
 * PURPOSE: Computes x^n (mod m)
 * CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 * TIME: O(log n)
*/
ll mod_exp(ll x, ll n, ll m) {
	x %= m;

	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}

	return res;
}

// unfinished but perfect idea, I hate digit dp

void solve(){
    ll n, m, a, b; cin >> n >> m >> a >> b;

    ll ans = 0;
    ll c1 = (a + 1) % MOD * (b + 1) % MOD * b % MOD * (mod_exp(2, m, MOD) + MOD - 2) % MOD;
    ll c2 = (a + 1) % MOD * (b + 1) % MOD * a % MOD * (mod_exp(2, n, MOD) + MOD - 2) % MOD;
    ll c3 = (a + 1) % MOD * (b + 1) % MOD;
    ans += c1;
    ans %= MOD;
    ans += c2;
    ans %= MOD;
    ans += c3;
    ans %= MOD;

    vi arr(29, 0), brr(29, 0);
    int aa = a, bb = b;
    int i = 0;
    while (aa > 0){
        arr[i] = aa % 2;
        aa /= 2;
        i++;
    }

    i = 0;
    while (bb > 0){
        brr[i] = bb % 2;
        bb /= 2;
        i++;
    }

    reverse(all(arr));
    reverse(all(brr));

    ll dp[29][2][2][2];

    rep(i, 0, 29){
        rep(j, 0, 2){
            rep(k, 0, 2){
                rep(l, 0, 2){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    function<ll(int,int,int,int)> dp;
    dp = [&](int x, int lowerX, int lowerY, int toggled){
        if (x == -1) {
            if (toggled) return 1;
            return 0;
        }

        if (dp[x][lowerX][lowerY][toggled] != -1){
            return dp[x][lowerX][lowerY][toggled];
        }

        ll curr;

        if (lowerX){
            if (brr[x] == 0){
                return dp[x][lowerX][lowerY][toggled] = dp(x - 1, lowerX, lowerY, toggled) % MOD;
            } else {
                ll curr = 0;
                return dp(x - 1, lowerX, lowerY, toggled) % MOD;
            }
        } else if (lowerY){

        } else {

        }
    };

    ans += dp[28][28][0][0];
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