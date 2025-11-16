/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-13
 * Contest: 
 * Problem: fibonacci
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
		rep(i,0,N) rep(j,0,N)
			rep(k,0,N) a.d[i][j] = (a.d[i][j] + d[i][k]*m.d[k][j] % MOD) % MOD;
		return a;
	}
	array<T, N> operator*(const array<T, N>& vec) const {
		array<T, N> ret{};
		rep(i,0,N) rep(j,0,N) ret[i] = (ret[i] + d[i][j] * vec[j] % MOD) % MOD;
		return ret;
	}
	M operator^(ull p) const {
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
    ull n; cin >> n;

    n--;
    
    Matrix<ll, 2> m;

    m.d[0][0] = m.d[0][1] = m.d[1][0] = 1;

    array<ll, 2> v = {1, 0};

    m = m ^ n;
    v = m * v;

    cout << v[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}