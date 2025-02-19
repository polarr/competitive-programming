/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-18
 * Contest: DMOJ othscc3
 * Problem: 5
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

enum QueryType { ADD, SET, NONE };

struct Tag {
	QueryType type = NONE;
	long double val = 0;
	void apply(const Tag &t) {
		if (t.type == ADD) {
			val += t.val;
			if (type != SET) { type = ADD; }
		} else if (t.type == SET) {
			type = SET;
			val = t.val;
		}
	}
};

struct Info {
	long double sum = 0;
	void apply(const Tag &t, int l, int r) {
		if (t.type == SET) {
			sum = t.val * (r - l + 1);
		} else if (t.type == ADD) {
			sum += t.val * (r - l + 1);
		}
	}
};

/** @return result of joining nodes a and b together */
Info operator+(const Info &a, const Info &b) { return {max(a.sum, b.sum)}; }

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
        if (ind < 0){
            return 0;
        }

		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};

void solve(){
    int n, q; cin >> n >> q;

    vi d(n, -1);
    vector<long double> cap(n);
    vector<vi> adj(n);

    rep(i, 0, n - 1){
        int p; cin >> p;
        --p;
        adj[i + 1].pb(p);
        adj[p].pb(i + 1);
    }

    rep(i, 0, n){
        cin >> cap[i];
    }

    /** 
     * ! MODIFIED
     * ALGORITHM: Euler Tour
     * PURPOSE: Flattens a tree so that each range contains any subtree range
     * CONSTRAINT: Graph must be a tree
     * TIME: O(V)
    */
    vector<pii> tour(n);
    int h = 0;
    int i = -1;
    function<void(int, int)> dfs;
    dfs = [&](int node, int parent){
        d[node] = d[parent] + 1;
        h = max(h, d[node]);
        tour[node].first = ++i;
        for (int x : adj[node]){
            if (x != parent){
                dfs(x, node);
            }
        }
        tour[node].second = ++i;
    };

    // root at 0
    dfs(0, 0);

    vector<long double> mult(n);
    rep(i, 0, n){
        mult[i] = ((long double) pow((long double) 2, (long double) (-h + d[i])));
    }

    LazySegtree<Info, Tag> st(2 * n);
    FT<long double> rq(2 * n);
    vector<bool> reached(n, false);
    vector<long double> curr(n, 0);

    auto set_node = [&](int node, long double val){
        pii t = tour[node];
        rq.set(t.first, val);
        rq.set(t.second, -val);
        st.range_update(0, t.second, Tag{ADD, -val + curr[node]});
        st.range_update(0, t.first, Tag{ADD, val - curr[node]});
        curr[node] = val;
    };

    auto add_node = [&](int node, long double val){
        pii t = tour[node];
        rq.add(t.first, val);
        rq.add(t.second, -val);
        st.range_update(0, t.second, Tag{ADD, -val});
        st.range_update(0, t.first, Tag{ADD, val});
        curr[node] += val;
    };

    auto actual = [&](int i){
        return st.range_query(0, i).sum - st.range_query(i, i).sum;
    };

    rep(i, 0, n){
        long double fac = -cap[i] * mult[i];
        set_node(i, fac);
    }

    rep(i, 0, q){
        int t, x; cin >> t >> x;
        --x;

        if (t == 1){
            long double v; cin >> v;
            if (reached[x]){
                add_node(x, v * mult[x]);
                continue;
            }

            long double acc = actual(tour[x].first);
            long double prev = rq.pref_sum(tour[x].first - 1);
            if (acc <= 0){
                acc = 0;
            }
            acc += curr[x] + cap[x] * mult[x];
            acc /= mult[x];
            long double real = acc + v;
            if (real >= cap[x]){
                reached[x] = true;
                set_node(x, -prev + (real - cap[x]) * mult[x]);
            } else {
                add_node(x, v * mult[x]);
            }
            continue;
        }

        if (reached[x]){
            cout << setprecision(10) << cap[x] << endl;
            continue;
        }

        long double acc = actual(tour[x].first);
        long double prev = rq.pref_sum(tour[x].first - 1);
        if (acc <= 0){
            acc = 0;
        }
        acc += curr[x] + cap[x] * mult[x];
        acc /= mult[x];
        long double real = acc;
        if (real >= cap[x]){
            reached[x] = true;
            set_node(x, -prev + (real - cap[x]) * mult[x]);
            cout << setprecision(10) << cap[x] << endl;
            continue;
        }

        cout << setprecision(10) << real << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}