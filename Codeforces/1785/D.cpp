/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-30
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

const int MAX_N = (1 << 20) + 1;
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

/** ALGORITHM: Fast Fourier Transform
 *  SOURCE: KACTL
*/
using C = complex<double>;
using vd = vector<double>;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}

/** 
 * ALGORITHM: FFT Convolution with Modulus
 * PURPOSE: Computes coefficients of polynomial ab, modulo m
 * TIME: O(n log n) where n = deg a + deg b
 * REQUIRE: Fast Fourier Transform
 * SOURCE: KACTL
*/
template<int M> vl convMod(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	vl res(sz(a) + sz(b) - 1);
	int B=32-__builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(M));
	vector<C> L(n), R(n), outs(n), outl(n);
	rep(i,0,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
	rep(i,0,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	rep(i,0,n) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	rep(i,0,sz(res)) {
		ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
		ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
		res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
	}
	return res;
}

void solve(){
    int n; cin >> n;

    vl pow2(n + 1, 1);
    rep(i, 1, n + 1){
        pow2[i] = pow2[i - 1] * 2;
    }

    ll dp[n + 1][pow2[n]];
    rep(i, 0, n + 1){
        rep(j, 0, pow2[n]){
            dp[i][j] = 0;
        }
    }

    dp[1][1] = 2;

    rep(i, 2, n + 1){
        vl a(pow2[i - 1] + 1, 0);
        rep(j, 1, pow2[i - 1] + 1){
            a[j] = fac_inv[j - 1] * fac_inv[pow2[i - 1] - j] % MOD;
        }
        vl b(pow2[i - 1], 0);
        rep(j, 0, pow2[i - 1]){
            b[j] = dp[i - 1][j] * fac_inv[j] % MOD * fac_inv[pow2[i - 1] - 1 - j] % MOD; 
        }

        vl c = convMod<MOD>(a, b);
        rep(j, 1, pow2[i]){
            dp[i][j] = 2LL * fac[pow2[i - 1]] % MOD * fac[j - 1] % MOD * fac[pow2[i] - 1 - j] % MOD * c[j] % MOD;
        }
    }

    rep(i, 0, pow2[n]){
        cout << dp[n][i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    factorial(MOD);
    factorial_inverses(MOD);

    solve();
    return 0;
}