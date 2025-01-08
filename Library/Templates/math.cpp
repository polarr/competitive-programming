/**
 * Template by 1egend (polarity.sh)
 * Template: math
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

/** ALGORITHM: Modular Exponentiation 
 *  PURPOSE: Computes x^n (mod m)
 *  CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 *  TIME: O(log n)
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

/** DATASTRUCTURE: Floor Interval Array
 *  PURPOSE: Computes x^n (mod m)
 *  CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 *  TIME: O(log n)
*/
class FIArray {
    public:
        ll n;
        ll sqrtn;
		ll len;
        vector<ll> arr;
        vector<ll> keys;
    
        FIArray(ll num){
            n = num;
            sqrtn = sqrt(num);
            len = 2 * sqrtn;
            if (n/sqrtn == sqrtn){
                len--;
            }

            arr = vector<ll>(len);
            keys = vector<ll>(len);

            for (ll i = 1; i <= sqrtn; i++){
                keys[i - 1] = i;
            }

            for (ll i = 1; i <= sqrtn; i++){
                keys[len - i] = n/i;
            }
        }

        ll query(ll i){
            if (i <= sqrtn){
                return arr[i - 1];
            }

            return arr[len - n/i];
        }

        void set(ll i, ll x){
            if (i <= sqrtn){
                arr[i - 1] = x;
                return;
            }

            arr[len - n/i] = x;
        }
};

/** ALGORITHM: Dirichlet Hyperbola Method
 *  PURPOSE: Computes prefix sum of (f (*) g)
 *  CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 *  TIME: O(sqrt(n)) for O(1) individual prefix sums
*/
template<ll m> class DirichletProduct {
	public:
		ll f(ll n){
			return 1;
		}

		ll g(ll n){
			return 1;
		}

		FIVector sumf(ll n){
			return n;
		}

		FIVector sumg(ll n){
			return n;
		}

		ll hyperbola(long double c){
			ll k = pow((long double)n, c);
			ll l = pow((long double)n, 1 - c);

			FIVector computef = sumf(n);
			FIVector computeg = sumg(n);

			// cout << k << " " << l << endl;

			ll ans = 0;

			for (ll i = 1; i <= k; i++){
				ll c = f(i);
				c *= computeg.query(n/i);
				// c *= sumg(n/i);
				c %= m;

				ans += c;
				ans %= m;
			}

			for (ll i = 1; i <= l; i++){
				ll c = g(i);
				c *= computef.query(n/i);
				// c *= sumf(n/i);
				c %= m;

				ans += c;
				ans %= m;
			}

			ans += m - ((computef.query(k) * computeg.query(l)) % m);
			// ans += m - ((sumf(k) * sumg(l)) % m);

			return ans % m;
		}
};

/** ALGORITHM: Linear Sieve
 *  PURPOSE: Sieves first n values of f
 *  CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 *  TIME: O(n) for multiplicative f
*/
vector <ll> prime;
bool is_composite[MAX_N];
ll phi[MAX_N];
ll prefg[PREF_N];

void sieve (ll n) {
    fill(is_composite, is_composite + n, false);
	phi[1] = 1;
	for (ll i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.pb(i);
			phi[i] = i - 1;
		}
		for (ll j = 0; j < prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			}
		}
	}
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;

const ll MOD = 1e9 + 7;

/** ALGORITHM: Fast Fourier Transform
 *  PURPOSE: Computes prefix sum of (f (*) g)
 *  CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 *  TIME: O(sqrt(n)) for O(1) individual prefix sums
 *  SOURCE: KACTL
*/
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

/** ALGORITHM: FFT Convolution
 *  PURPOSE: Computes prefix sum of (f (*) g)
 *  CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 *  TIME: O(sqrt(n)) for O(1) individual prefix sums
 *  SOURCE: KACTL
*/
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

typedef vector<ll> vl;

/** ALGORITHM: FFT Convolution with Modulus
 *  PURPOSE: Computes prefix sum of (f (*) g)
 *  CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 *  TIME: O(sqrt(n)) for O(1) individual prefix sums
 *  SOURCE: KACTL
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	DirichletProduct test = 
    return 0;
}