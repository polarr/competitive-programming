/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-25
 * Contest: DMOJ
 * Problem: ray
**/

#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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

const int MAX_N = 100;
const ll MOD = 1e9 + 7;

/** 
 * DATASTRUCTURE: Fast Matrix
 * PURPOSE: Optimized matrix template
 * TIME: O(nmp) for n x m times m x p matrix; supports binary exponentiation
 * SOURCE: KACTL
*/
template<class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(const M& m) const {
		M a;
		rep(i,0,N) { rep(j,0,N) {
            a.d[i][j] = 1e18;
			rep(k,0,N) { a.d[i][j] = min(a.d[i][j], d[i][k] + m.d[k][j]); }}}
		return a;
	}
	array<T, N> operator*(const array<T, N>& vec) const {
		array<T, N> ret{};
		rep(i,0,N) {
            ret[i] = 1e18;
            rep(j,0,N) { ret[i] = min(ret[i], d[i][j] + vec[j]); }}
		return ret;
	}
	M operator^(ll p) const {
		assert(p >= 0);
		M a, b(*this);
		rep(i,0,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};

void solve(){
    int n, m, q; cin >> n >> m >> q;

    Matrix<ll, MAX_N> mat;
    rep(i, 0, MAX_N){
        rep(j, 0, MAX_N){
            mat.d[i][j] = 1e18;
        }
    }

    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        ll c; cin >> c;
        mat.d[b][a] = min(mat.d[b][a], c);
    }

    int lg = log2(1e9) + 1;
    vector<Matrix<ll, MAX_N>> bin(lg);
    rep(i, 0, lg){
        bin[i] = mat;
        mat = mat * mat;
    }

    rep(i, 0, q){
        array<ll, MAX_N> vec;
        rep(j, 0, MAX_N){
            vec[j] = 1e18;
        }
        int u, v, k; cin >> u >> v >> k;
        --u; --v;
        vec[u] = 0;
        rep(j, 0, lg){
            if (k & (1LL << j)){
                vec = bin[j] * vec;
            }
        }
        ll ans = vec[v];
        cout << (ans == 1e18 ? -1 : ans) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}