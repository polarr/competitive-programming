/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-31
 * Contest: 
 * Problem: D
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

/** 
 * PRECOMPUTE: Factorials and Factorial Inverses
 * PURPOSE: Computes factorials and their inverses modulo m
 * REQUIRE: Modular Exponentiation
 * TIME: O(n + log m)
*/
vector<ll> fac(MAX_N + 1);
vector<ll> fac_inv(MAX_N + 1);
void factorial(ll p) {
	fac[0] = 1;
	for (int i = 1; i <= MAX_N; i++) { fac[i] = fac[i - 1] * i % p; }
}
void factorial_inverses(ll p) {
    fac_inv[0] = 1;
	fac_inv[MAX_N] = mod_exp(fac[MAX_N], p - 2, p);
	for (int i = MAX_N; i >= 1; i--) { fac_inv[i - 1] = fac_inv[i] * i % p; }
}

/** 
 * ALGORITHM: Binomial Coefficient
 * PURPOSE: Computes n choose r
 * CONSTRAINT: 0 <= n, r <= MAX_N
 * REQUIRE: Factorials and Factorial Inverses
 * TIME: O(1)
*/
ll choose(ll n, ll r, ll p) {
    if (r > n){
        return 0;
    }
	return fac[n] * fac_inv[r] % p * fac_inv[n - r] % p;
}

void solve(){
    int n; cin >> n;
    vi score(n + 2, -1);
    int mxscore = 2 * log2(n) + 5;
    rep(i, 0, n) {
        cin >> score[i + 1];
        if (score[i + 1] > mxscore){
            cout << 0 << endl;
            return;
        }
    }

    ll dp[n + 2][n + 2][mxscore + 2][mxscore + 2];
    rep(i1, 0, n + 2){
        rep(i2, 0, n + 2){
            rep(i3, 0, mxscore + 2){
                rep(i4, 0, mxscore + 2){
                    dp[i1][i2][i3][i4] = 0;
                }
            }
        }
    }

    rep(i, 0, n + 1){
        dp[i][i + 1][mxscore + 1][mxscore + 1] = 1;
        dp[i][i + 1][mxscore + 1][0] = 1;
        dp[i][i + 1][0][mxscore + 1] = 1;
        dp[i][i + 1][0][0] = 1;
    }

    rep(len, 2, n + 2){
        rep(l, 0, n + 2 - len){
            int r = l + len;
            rep(a, 0, mxscore + 2){
                rep(b, 0, mxscore + 2){
                    rep(x, l + 1, r){
                        int na = a, nb = b;
                        if (l == 0 || (r != n + 1 && r - x < x - l)){
                            if (nb != mxscore + 1) nb--;
                        } else {
                            if (na != mxscore + 1) na--;
                        }

                        if (na < 0 || nb < 0){
                            continue;
                        }

                        ll mult = choose(len - 2, x - l - 1, MOD);
                        
                        if (score[x] == -1){
                            dp[l][r][a][b] += mult * dp[l][x][na][mxscore + 1] % MOD * dp[x][r][mxscore + 1][nb] % MOD;
                            dp[l][r][a][b] %= MOD;
                            continue;
                        }

                        rep(sc, 0, score[x] + 1){
                            dp[l][r][a][b] += mult * dp[l][x][na][sc] % MOD * dp[x][r][score[x] - sc][nb] % MOD;
                            dp[l][r][a][b] %= MOD;
                        }
                    }
                }
            }
        }
    }

    cout << dp[0][n + 1][mxscore + 1][mxscore + 1] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    factorial(MOD);
    factorial_inverses(MOD);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}