/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-10
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
const ll MOD = 1e9 + 7;

/** 
 * DATASTRUCTURE: Lazy Segment Tree
 * PURPOSE: Segment Tree with lazy updates
 * TIME: O(log n) to update and query
*/
template <class Info, class Tag> class LazySegtree {
  private:
	const int n;
	vector<Info> tree;
	vector<Tag> lazy;

	/** builds the segtree values in O(N) time */
	void build(int v, int l, int r, const vector<Info> &a) {
		if (l == r) {
			tree[v] = a[l];
		} else {
			int m = (l + r) / 2;
			build(2 * v, l, m, a);
			build(2 * v + 1, m + 1, r, a);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}

	/** applies update x to lazy[v] and tree[v] */
	void apply(int v, int l, int r, const Tag &x) {
		tree[v].apply(x, l, r);
		lazy[v].apply(x);
	}

	/** pushes lazy updates down to the children of v */
	void push_down(int v, int l, int r) {
		int m = (l + r) / 2;
		apply(2 * v, l, m, lazy[v]);
		apply(2 * v + 1, m + 1, r, lazy[v]);
		lazy[v] = Tag();
	}

	void range_update(int v, int l, int r, int ql, int qr, const Tag &x) {
		if (qr < l || ql > r) { return; }
		if (ql <= l && r <= qr) {
			apply(v, l, r, x);
		} else {
			push_down(v, l, r);
			int m = (l + r) / 2;
			range_update(2 * v, l, m, ql, qr, x);
			range_update(2 * v + 1, m + 1, r, ql, qr, x);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}

	Info range_query(int v, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) { return Info(); }
		if (l >= ql && r <= qr) { return tree[v]; }
		push_down(v, l, r);
		int m = (l + r) / 2;
		return range_query(2 * v, l, m, ql, qr) +
		       range_query(2 * v + 1, m + 1, r, ql, qr);
	}

  public:
	LazySegtree() {}

	LazySegtree(int n) : n(n) {
		tree.assign(4 << __lg(n), Info());
		lazy.assign(4 << __lg(n), Tag());
	}

	LazySegtree(const vector<Info> &a) : n(a.size()) {
		tree.assign(4 << __lg(n), Info());
		lazy.assign(4 << __lg(n), Tag());
		build(1, 0, n - 1, a);
	}

	/** updates [ql, qr] with the arbitrary update chosen */
	void range_update(int ql, int qr, const Tag &x) {
		range_update(1, 0, n - 1, ql, qr, x);
	}

	/** @return result of range query on [ql, qr] */
	Info range_query(int ql, int qr) { return range_query(1, 0, n - 1, ql, qr); }
};

enum QueryType { ADDMX, NONE };

struct Tag {
	QueryType type = NONE;
	ll add = 0;
    ll mx = 0;
	void apply(const Tag &t) {
		if (t.type == ADDMX) {
            add += t.add;
            mx = max(mx + t.add, t.mx);
            type = ADDMX;
		}
	}
};

struct Info {
	ll val = 0;
	void apply(const Tag &t, int l, int r) {
		if (t.type == ADDMX) {
            val += t.add;
            val = max(val, t.mx);
		}
	}
};

/** @return result of joining nodes a and b together */
Info operator+(const Info &a, const Info &b) { return {max(a.val, b.val)}; }

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<map<int, ll>> cnt(n), mult(n);
    ll ans = 0;
    vl s(n, 0);

    rep(i, 0, n){
        ll empty = 0;
        set<int> cols;
        rep(j, 0, m){
            ll x; cin >> x;
            if (x == -1){
                s[i]++;
                continue;
            }

            x--;
            cols.insert(x);
            cnt[i][x]++;
            if (i < n - 1){
                mult[i + 1][x]++;
            }

            if (i > 0){
                mult[i - 1][x]++;
            }
        }

        if (i > 0){
            for (int col : cols){
                ans += cnt[i][col] * cnt[i - 1][col];
            }
        }
    }

    LazySegtree<Info, Tag> st(k);

    rep(i, 0, n){
        if (i > 0){
            ll mx = st.range_query(0, k - 1).val;
            st.range_update(0, k - 1, Tag{ADDMX, s[i] * s[i - 1], mx});
        }

        for (auto [color, c] : mult[i]){
            st.range_update(color, color, Tag{ADDMX, s[i] * c, 0});
        }
    }

    cout << ans + st.range_query(0, k - 1).val << endl;
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