/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-01
 * Contest: Project Euler
 * Problem: 721
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
const ll MOD = 999999937;


ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const ll mod = MOD;
struct Mod {
	ll x;
    Mod() : x(0) {}
	Mod(ll xx) : x(xx%mod) {}
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

void solve(){
    ll n = 5e6;

    Mod ans = 0;
    for (ll a = 1; a <= n; a++) {
        ll k = ceil(sqrt(a));
        if (k * k != a) {
            ans = ans + Mod(MOD - 1);
        }
        k %= MOD;
        Matrix<Mod, 2> m;
        m.d[0] = {Mod(0), Mod(1)};
        m.d[1] = {Mod(a + MOD - (k * k % MOD)), Mod(2 * k)};
        m = m ^ (a * a);

        array<Mod, 2> v = {Mod(2), Mod(2 * k)};
        v = m * v;
        ans = ans + v[0];
    }

    cout << ans.x << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}