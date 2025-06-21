/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-20
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

enum QueryType { ADD, NONE };

struct Tag {
	QueryType type = NONE;
	int val = 0;
	void apply(const Tag &t) {
		val = max(val, t.val);
	}
};

struct Info {
	int sum = 0;
	void apply(const Tag &t, int l, int r) {
		sum = max(sum, t.val);
	}
};

/** @return result of joining nodes a and b together */
Info operator+(const Info &a, const Info &b) { return {a.sum + b.sum}; }

void solve(){
    int n, m; cin >> n >> m;

    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vi b = a;
    sort(all(b));
    int compress = 0;
    map<int, int> mp;
    rep(i, 0, n){
        if (i == 0 || b[i] != b[i - 1]){
            mp[b[i]] = compress++;
        }
    }

    rep(i, 0, n){
        a[i] = mp[a[i]];
    }

    vector<vi> eventStart(n), eventEnd(n);
    rep(i, 0, m){
        int l, r; cin >> l >> r;
        --l; --r;
        eventStart[l].pb(r);
        eventEnd[r].pb(l);
    }

    vi last(n, -1);
    vector<set<int>> occur(n);


    set<pii> s;

    LazySegtree<Info, Tag> st(n);
    rep(i, 0, n){
        st.range_update(i, i, Tag{ADD, i});
    }

    bool canZero = true;
    int maxL = n - 1;

    rep(i, 0, n){
        for (int r : eventStart[i]){
            s.insert({i, r});
        }

        int lo = n + 1;
        if (!s.empty()){
            lo = s.begin()->first;
        }

        int lst = last[a[i]];
        auto fst = occur[a[i]].lower_bound(lo);

        last[a[i]] = i;
        occur[a[i]].insert(i);

        if (lst >= lo){
            maxL = min(maxL, i);
            canZero = false;
            st.range_update(0, lst, Tag{ADD, lst});
            st.range_update(*fst + 1, i, Tag{ADD, i});
        }

        for (int l : eventEnd[i]){
            s.erase({l, i});
        }
    }

    if (canZero) {
        cout << 0 << endl;
        return;
    }

    int ans = n;
    rep(i, 0, maxL + 1){
        cerr << st.range_query(i, i).sum - i + 1 << " ";
        ans = min(ans, st.range_query(i, i).sum - i + 1);
    }

    cerr << endl;
    cout << ans << endl;
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