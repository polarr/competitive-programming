/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-24
 * Contest: Codeforces 838
 * Problem: B
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
 * ALGORITHM: Euler Tour
 * PURPOSE: Flattens a tree so that each range contains any subtree range
 * CONSTRAINT: Graph must be a tree
 * TIME: O(V)
*/
vector<pii> eulerTour(int n, vector<vector<int>> &adj){
    vector<pii> ans(n);
    int i = -1;
    function<void(int, int)> tour;
    tour = [&](int node, int parent){
        ans[node].first = ++i;
        for (int x : adj[node]){
            if (x != parent){
                tour(x, node);
            }
        }
        ans[node].second = i;
    };

    // root at 0
    tour(0, 0);

    return ans;
}

vector<pii> eulerTour2(int n, vector<vector<int>> &adj){
    vector<pii> ans(n);
    int i = -1;
    function<void(int, int)> tour;
    tour = [&](int node, int parent){
        ans[node].first = ++i;
        for (int x : adj[node]){
            if (x != parent){
                tour(x, node);
            }
        }
        ans[node].second = ++i;
    };

    // root at 0
    tour(0, 0);

    return ans;
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
};

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

struct Tag {
	ll val = 0;
	void apply(const Tag &t) {
		val += t.val;
	}
};

struct InfoMin {
	ll sum = 1e16;
	void apply(const Tag &t, int l, int r) {
		sum += t.val;
	}
};

/** @return result of joining nodes a and b together */
InfoMin operator+(const InfoMin &a, const InfoMin &b) {
    return a.sum < b.sum ? a : b; 
}

void solve(){
    int n, q; cin >> n >> q;
    vl w(n, 0), up(n, 0);
    vector<vi> adj(n);
    vector<array<ll, 3>> edges;
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        ll c; cin >> c;
        w[b] = c;
        edges.pb({a, b, c});
    }

    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        ll c; cin >> c;
        up[a] = c;
        edges.pb({a, b, c});
    }

    vector<pii> tour = eulerTour(n, adj), tour2 = eulerTour2(n, adj);

    FT<ll> st(2 * n);

    rep(i, 0, n){
        st.add(tour2[i].first, w[i]);
        st.add(tour2[i].second, -w[i]);
    }

    vector<InfoMin> arr(n);

    rep(i, 0, n){
        arr[tour[i].first] = {up[i] + st.pref_sum(tour2[i].first)};
    }

    LazySegtree<InfoMin, Tag> st2(arr);

    rep(ii, 0, q){
        int c; cin >> c;
        if (c == 1){
            int j; ll ww; cin >> j >> ww;
            j--;
            if (j < n - 1){
                int i = edges[j][1];
                st.add(tour2[i].first, -w[i] + ww);
                st.add(tour2[i].second, w[i] - ww);
                st2.range_update(tour[i].first, tour[i].second, Tag{-w[i] + ww});
                w[i] = ww;
            } else {
                int i = edges[j][0];
                st2.range_update(tour[i].first, tour[i].first, Tag{-up[i] + ww});
                up[i] = ww;
            }
        } else {
            int u, v; cin >> u >> v;
            --u; --v;
            ll toU = st.pref_sum(tour2[u].first);
            ll toV = st.pref_sum(tour2[v].first);
            if (tour[u].first <= tour[v].first && tour[v].first <= tour[u].second){
                cout << toV - toU << endl;
            } else {
                ll mn = st2.range_query(tour[u].first, tour[u].second).sum;
                cout << toV + mn - toU << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}