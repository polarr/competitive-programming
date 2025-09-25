/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-23
 * Contest: CSES Problemset
 * Problem: 2166
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
 * DATASTRUCTURE: Lazy Segment Tree - Affine
 * PURPOSE: Lazy Segment Tree supporting affine updates
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

struct Tag {
    ll mult = 1;
	ll add = 0;
	void apply(const Tag &t) {
		mult *= t.mult;
        add *= t.mult;
        add += t.add;
	}
};

struct Info {
	ll sum = -1e17;
	void apply(const Tag &t, int l, int r) {
		sum *= t.mult;
        sum += t.add;
	}
};

/** @return result of joining nodes a and b together */
Info operator+(const Info &a, const Info &b) { 
    return Info{max(a.sum, b.sum)};
}

void solve(){
    int n, q; cin >> n >> q;
    
    LazySegtree<Info, Tag> st(n);
    st.range_update(0, n - 1, Tag{0, 0});
    rep(i, 0, n){
        ll a; cin >> a;
        st.range_update(i, n - 1, Tag{1, a});
    }

    rep(i, 0, q){
        ll c, a, b; cin >> c >> a >> b;
        --a;
        if (c == 1){
            ll pb = st.range_query(a, a).sum - (a == 0 ? 0LL : st.range_query(a - 1, a - 1).sum);
            st.range_update(a, n - 1, Tag{1, b - pb});
        } else {
            --b;
            ll ans = st.range_query(a, b).sum - (a == 0 ? 0LL : st.range_query(a - 1, a - 1).sum);
            cout << max(0LL, ans) << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}