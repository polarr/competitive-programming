/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-23
 * Contest: IOI 2014
 * Problem: wall
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

const int MAX_N = 2e6 + 1;
const ll MOD = 1e9 + 7;

enum TagType { CLAMP, NONE };

int ans[MAX_N];

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
			if (lazy[v].type != NONE)
                push_down(v, l, r); 
                
			int m = (l + r) / 2;
			range_update(2 * v, l, m, ql, qr, x);
			range_update(2 * v + 1, m + 1, r, ql, qr, x);
			// tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}

	Info range_query(int v, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) { return Info(); }
		if (l >= ql && r <= qr) { return tree[v]; }
		if (lazy[v].type != NONE)
            push_down(v, l, r);
		int m = (l + r) / 2;
		return range_query(2 * v, l, m, ql, qr) +
		       range_query(2 * v + 1, m + 1, r, ql, qr);
	}

    void collect_leaves(int v, int l, int r) {
        if (l == r) {
            ans[l] = tree[v].val;
            return;
        }
        
        if (lazy[v].type != NONE)
            push_down(v, l, r);   
            
        int m = (l + r) / 2;
        collect_leaves(2 * v, l, m);
        collect_leaves(2 * v + 1, m + 1, r);
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

    void materialize() {
        collect_leaves(1, 0, n - 1);
    }
};

struct Tag {
    TagType type = NONE;
    int lo = INT_MIN;
    int hi = INT_MAX;
	void apply(const Tag &t) {
        if (t.type == NONE) return;
		if (type == NONE){
            type = t.type;
            lo = t.lo;
            hi = t.hi;
            return;
        }

        if (t.lo > hi){
            lo = t.lo;
            hi = t.lo;
            return;
        }

        if (t.hi < lo){
            lo = t.hi;
            hi = t.hi;
            return;
        }

        hi = min(hi, t.hi);
        lo = max(lo, t.lo);
	}
};

struct Info {
	int val = 0;
	void apply(const Tag &t, int l, int r) {
		if (t.type == CLAMP){
            val = max(t.lo, val);
            val = min(t.hi, val);
        }
	}
};

/** @return result of joining nodes a and b together */
Info operator+(const Info &a, const Info &b) { 
    return a;
}

void solve(){
    int n, q; cin >> n >> q;
    LazySegtree<Info, Tag> st(n);
    rep(i, 0, q){
        int c, l, r, h; cin >> c >> l >> r >> h;
        if (c == 1){
            st.range_update(l, r, Tag{CLAMP, h, INT_MAX});
        } else {
            st.range_update(l, r, Tag{CLAMP, INT_MIN, h});
        }
    }

    st.materialize();

    rep(i, 0, n){
        cout << ans[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}