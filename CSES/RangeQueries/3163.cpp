/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-23
 * Contest: 
 * Problem: 3163
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
    int n, q; cin >> n >> q;

    vi vals;
    vi arr(n + 1, 0);
    rep(i, 0, n) {
        cin >> arr[i + 1];
        vals.pb(arr[i + 1]);
    }

    vi ans(q, 0);
    vector<vector<array<int, 3>>> l(n + 1), r(n + 1);
    rep(i, 0, q) {
        int a, b; cin >> a >> b;
        int c, d; cin >> c >> d;
        vals.pb(c);
        vals.pb(d);
        l[a - 1].pb({i, c, d});
        r[b].pb({i, c, d});
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    auto compress = [&](int x) -> int {
        return lower_bound(all(vals), x) - vals.begin();
    };

    FT<int> st(sz(vals));

    rep(i, 0, n + 1) {
        if (i != 0) {
            st.add(compress(arr[i]), 1);
        }

        rep(k, 0, sz(l[i])) {
            auto [j, c, d] = l[i][k];
            int cc = compress(c), dd = compress(d);
            ans[j] -= st.range_sum(cc, dd);
        }

        rep(k, 0, sz(r[i])) {
            auto [j, c, d] = r[i][k];
            int cc = compress(c), dd = compress(d);
            ans[j] += st.range_sum(cc, dd);
        }
    }

    rep(i, 0, q) {
        cout << ans[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}