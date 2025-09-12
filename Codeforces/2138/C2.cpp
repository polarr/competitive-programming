/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-11
 * Contest: Codeforces 2138
 * Problem: C2
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
 * ALGORITHM: FFT Convolution
 * PURPOSE: Computes coefficients of polynomial ab
 * TIME: O(n log n) where n = deg a + deg b
 * REQUIRE: Fast Fourier Transform
 * SOURCE: KACTL
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

vl makeOne(vl a){
    rep(i, 0, sz(a)){
        if (a[i] != 0) {
            a[i] = 1;
        }
    }

    return a;
}

void solve(){
    ll n, k; cin >> n >> k;

    vl depth(n, 0);
    vector<vi> children(n);
    rep(i, 0, n - 1){
        int p; cin >> p;
        --p;
        children[p].pb(i + 1);
    }

    ll mindepth = n;

    function<void(int, int)> dfs;
    dfs = [&](int node, ll d){
        depth[d]++;
        if (children[node].size() == 0){
            mindepth = min(mindepth, d);
        }

        for (int x : children[node]){
            dfs(x, d + 1);
        }
    };

    dfs(0, 0);
    ll extra = 0;
    rep(i, mindepth + 1, n){
        extra += depth[i];
    }

    // can k knapsack?
    function<vl(int, int)> rec;
    rec = [&](int l, int r){
        if (l == r) {
            int k = depth[l];
            vl ans(k + 1, 0);
            ans[0] = 1;
            ans[k] = 1;
            return ans;
        }

        int mid = (l + r)/2;
        return makeOne(convMod<(int)MOD>(rec(l, mid), rec(mid + 1, r)));
    };

    vl knapsack = rec(0, mindepth);

    if (k - extra <= 0){
        cout << mindepth + 1 << endl;
        return;
    }

    rep(i, k - extra, min(k + 1, (ll)knapsack.size())){
        if (knapsack[i] != 0){
            cout << mindepth + 1 << endl;
            return;
        }
    }

    // rep(i, 0, knapsack.size()){
    //     cout << knapsack[i] << "a";
    // }

    cout << mindepth << endl;
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