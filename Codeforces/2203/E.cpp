/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-05
 * Contest: 
 * Problem: E
**/
#include <bits/stdc++.h>
using namespace std;

// Order statistic tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
 * DATASTRUCTURE: Fenwick Tree
 * PURPOSE: Point update and prefix sums
 * TIME: O(log n) to update and query
*/
template <class T> class FT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	FT(int size) : size(size), bit(size + 1), arr(size) {}

	/** Sets the value at index ind to val. */
	void set(int ind, T val) { add(ind, val - arr[ind]); }

	/** Adds val to the element at index ind. */
	void add(int ind, T val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	/** @return The sum of all values in [0, ind]. */
	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}

    T range_sum(int l, int r) {
        if (r < l) return T();
        if (l == 0) {
            return pref_sum(r);
        }

        return pref_sum(r) - pref_sum(l - 1);
    }
};

void solve(){
    int m; cin >> m;

    vector<pair<ll, int>> arr(m);
    rep(i, 0, m) {
        ll x; cin >> x;
        arr[i] = {x, i};
    }

    sort(all(arr));

    vector<pair<ll, int>> idx(m);
    rep(i, 0, m) {
        auto [x, j] = arr[i];
        idx[j] = {x, i};
    }

    FT<ll> st(m);

    Tree<int> ord;

    auto compute = [&](int mid, int q) -> pair<ll, ll> {
        ll l = 0;
        auto j = ord.find_by_order(mid);
        int i = *j;

        if (j != ord.begin()) {
            int p = *prev(j);
            l = arr[p].first * mid - st.range_sum(0, i - 1);
        }

        ll r = 0;
        if (next(j) != ord.end()) {
            int n = *next(j);
            r = st.range_sum(i + 1, m - 1) - arr[n].first * (q - mid);
        }

        return {l, r};
    };

    rep(q, 0, m) {
        auto [x, i] = idx[q];

        ord.insert(i);
        st.set(i, x);

        if (q < 2) continue;

        int lo = 1, hi = q - 1;
        while (lo < hi) {
            int mid = (lo + hi)/2;
            
            auto [l, r] = compute(mid, q);

            if (l < r) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        pair<ll, ll> c1 = compute(lo, q), c2 = compute(lo - 1, q);
        ll ans = min(max(c1.first, c1.second), max(c2.first, c2.second)) % MOD;
        ans *= mod_exp(q - 1, MOD - 2, MOD);
        ans %= MOD;
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}