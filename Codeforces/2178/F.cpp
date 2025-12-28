/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-27
 * Contest: 
 * Problem: F
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

void solve(){
    int n; cin >> n;

    vector<vi> adj(n);
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi color(n, 1);
    vl sizes;

    ll initSize;

    function<int(int, int)> dfs;
    dfs = [&](int x, int par) {
        int size = 1;
        for (int node : adj[x]) {
            if (node == par) continue;
            size += dfs(node, x);
            color[x] ^= color[node];
        }

        if (x == 0) {
            initSize = size;
        }
        else if (color[x] == 0) {
            sizes.pb(size);
            size = 0;
        }

        return size;
    };

    dfs(0, -1);

    if (sz(sizes) == 0) {
        cout << 1 << endl;
        return;
    }

    int k = sz(sizes);

    ll ans = 0;
    rep(i, 0, k) {
        ans += mod_exp(sizes[i], MOD - 2, MOD);
        ans %= MOD;
    }

    ll prod = initSize;
    prod *= fac[k - 1];
    prod %= MOD;

    rep(i, 0, k) {
        prod *= sizes[i];
        prod %= MOD;
        prod *= sizes[i];
        prod %= MOD;
    }

    ans *= prod;
    ans %= MOD;

    cout << ans << endl;
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