/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-01
 * Contest: Balkan OI
 * Problem: reading
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

const int MAX_N = 150;
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
			rep(k,0,N) { a.d[i][j] += d[i][k]*m.d[k][j] % MOD; a.d[i][j] %= MOD; }
		return a;
	}
	array<T, N> operator*(const array<T, N>& vec) const {
		array<T, N> ret{};
		rep(i,0,N) rep(j,0,N) { ret[i] += d[i][j] * vec[j] % MOD; ret[i] %= MOD; }
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
    ll n; cin >> n;
    int m; cin >> m;
    vector<vi> vals(26, vi(26, 1));
    vector<vi> adj(27 + 26 * 4);

    rep(i, 0, m){
        char c, d; cin >> c >> d;
        int a = c - 'a', b = d - 'a';
        int k; cin >> k;
        vals[a][b] = vals[b][a] = k;
    }

    adj[26].pb(26);
    rep(i, 0, 26){
        adj[i].pb(26);
        adj[27 + i].pb(i);
        rep(j, 1, 4){
            adj[27 + 26 * j + i].pb(1 + 26 * j + i);
        }
    }

    rep(i, 0, 26){
        rep(j, 0, 26){
            int k = vals[i][j];

            if (k == 1){
                adj[i].pb(j);
            } else {
                adj[i].pb(27 + 26 * (k - 2) + j);
            }
        }
    }

    // cout << sz(adj) << endl;
    Matrix<ll, MAX_N> mat;
    rep(i, 0, sz(adj)){
        for (int j : adj[i]){
            mat.d[j][i] = 1;
        }
    }

    mat = mat ^ n;

    array<ll, MAX_N> v;
    rep(i, 0, 26){
        v[i] = 1;
    }

    v = mat * v;
    ll ans = 0;
    rep(i, 0, 27){
        ans += v[i];
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