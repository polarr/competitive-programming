/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-24
 * Contest: Project Euler
 * Problem: 458
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

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const ll mod = 1e9;
struct Mod {
	ll x;
    Mod() : x(0) {}
	Mod(ll xx) : x(xx) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1); return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

template<class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(M& m) {
		M a;
		rep(i,0,N) rep(j,0,N)
			rep(k,0,N) a.d[i][j] = a.d[i][j] + d[i][k]*m.d[k][j];
		return a;
	}
	array<T, N> operator*(array<T, N>& vec) {
		array<T, N> ret{};
		rep(i,0,N) rep(j,0,N) ret[i] = ret[i] + d[i][j] * vec[j];
		return ret;
	}
	M operator^(ll p) {
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

ll ITERS = 1e12;

void solve(){
    Matrix<Mod, 6> m;
    rep(i, 0, 6){
        rep(j, 0, i + 1) {
            m.d[j][i] = Mod(1);
        }

        if (i == 5) continue;
        m.d[i + 1][i] = Mod(6 - i);
    }

    ll choose = 1;
    Mod vi = Mod(1);

    array<Mod, 6> v;
    rep(i, 0, 6){
        ll ways = 1;
        rep(j, 0, i + 1) {
            ways *= 7 - j;
        }

        if (i != 5) ways *= i + 1;
        rep(j, i + 3, 7) {
            ways *= 7;
        }

        v[i] = Mod(ways);
    }

    m = m^(ITERS - 6LL);
    v = m*v;

    Mod ans = Mod(0);
    rep(i, 0, 6) {
        ans = ans + v[i];
    }

    cout << ans.x << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}