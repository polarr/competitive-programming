/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-24
 * Contest: aaaa1
 * Problem: 4
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
const int INF = 1e6;

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
	return fac[n] * fac_inv[n - r] % p;
}

/** 
 * DATASTRUCTURE: 2D Prefix Sum
 * PURPOSE: Fast range sum queries on a matrix
 * CONSTRAINT: Must input a non-degenerate 2 dimensional matrix
 * TIME: O(nm) to precompute, O(1) to query
*/
template <class T> class Prefix2D {
    private:
        vector<vector<T>> matrix;
    public:
        Prefix2D(vector<vector<T>> &grid){
            matrix = vector<vector<T>>(grid.size() + 1, vector<T>(grid[0].size() + 1, 0));

            for (int i = 0; i < grid.size(); i++){
                for (int j = 0; j < grid[0].size(); j++){
                    matrix[i + 1][j + 1] = grid[i][j] + matrix[i][j + 1] + matrix[i + 1][j] - matrix[i][j];
                }
            }
        }

        /**
         * CONSTRAINT: 1 <= y1 <= y2 <= height, 1 <= x1 <= x2 <= width
         * RETURN: sum of submatrix with top-left corner x1, y1 and bottom right corner x2, y2 */
        T query(int x1, int y1, int x2, int y2){
            x1++; y1++; x2++; y2++;
            if (x2 < x1 || y2 < y1) {
                return T();
            }

            --x1; --y1;
            return matrix[y2][x2] + matrix[y1][x1] - matrix[y2][x1] - matrix[y1][x2];
        }
};

void solve(){
    int n, m; cin >> n >> m;
    int K = n * m;
    vector<array<int, 2>> pos(K);
    vector<vi> grid(n, vi(m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            pos[grid[i][j]] = {i, j};
        }
    }

    if (n == 1 && m == 1) {
        cout << 1 << endl;
        return;
    }

    int l = INF, r = -INF, u = INF, d = -INF;

    auto bounded = [&](int l, int r, int u, int d, int y, int x) -> bool {
        return u <= y && y <= d && l <= x && x <= r;
    };

    vi achieveable;
    rep(i, 0, K - 1) {
        array<int, 2> loc = pos[i];
        u = min(u, loc[0]);
        d = max(d, loc[0]);
        l = min(l, loc[1]);
        r = max(r, loc[1]);

        if (!bounded(l, r, u, d, pos[i + 1][0], pos[i + 1][1])) {
            achieveable.pb(i + 1);
        }
    }

    achieveable.pb(K);

    int k = sz(achieveable);
    // cout << k << endl;

    vector<vl> dp(n + 1, vl(m + 1, 0));
    dp[1][1] = 1;

    Prefix2D<ll> sum(dp);

    rep(i, 1, k) {
        vector<vl> ndp(n + 1, vl(m + 1, 0));
        int val = achieveable[i];
        int pre = achieveable[i - 1];

        // already placed 0 ... pre - 1
        // place pre ... val - 1 where pre determines the bounding box

        int place = val - pre;

        rep(h, 1, n + 1) {
            rep(w, 1, m + 1) {
                int tot = h * w;
                if (tot < val) {
                    continue;
                }

                ll curr = choose(tot - pre - 1, place - 1, MOD);
                ll tran = sum.query(w, 1, w, h - 1) % MOD * (ll)(2 * w) % MOD;
                // cout << tran << endl;
                tran += sum.query(1, h, w - 1, h) % MOD * (ll)(2 * h) % MOD;
                // cout << sum.query(1, h, w - 1, h) % MOD * 4LL % MOD << endl;
                tran %= MOD;

                tran += sum.query(1, 1, w - 1, h - 1) % MOD * 4LL % MOD;
                // cout << sum.query(1, 1, w - 1, h - 1) % MOD * 4LL % MOD << endl;
                tran %= MOD;

                // cout << curr << " " << tran << endl;

                ndp[h][w] = curr * tran % MOD;
            }
        }

        dp = ndp;
        sum = Prefix2D<ll>(dp);
    }

    cout << dp[n][m] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    factorial(MOD);
    factorial_inverses(MOD);
    solve();
    return 0;
}