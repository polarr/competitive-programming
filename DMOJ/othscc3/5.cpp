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

/** TOOL: Debug
 *  PURPOSE: Prints various data types to terminal
 *  SOURCE: tourist
*/
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

/** 
 * DATASTRUCTURE: Lazy Segment Tree
 * PURPOSE: Lazy updates on a segment tree, supports range updates
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
		if (qr < l || ql > r) { return Info{}; }
		if (l >= ql && r <= qr) { return tree[v]; }
		push_down(v, l, r);
		int m = (l + r) / 2;

        return range_query(2 * v, l, m, ql, qr) + range_query(2 * v + 1, m + 1, r, ql, qr);
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
			sum = t.val;
		} else if (t.type == ADD) {
			sum += t.val;
		}
	}
};

/** @return result of joining nodes a and b together */
Info operator+(const Info &a, const Info &b) { return {min(a.sum, b.sum)}; }

const int MAX = 1e5; // Max size of array
long double tree[4*MAX]; // Segment tree
long double lazy[4*MAX]; // Lazy array to propagate updates

// Function to build the tree
void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = 0;
    }
    else
    {
        int mid = (start + end) / 2;
        // Recur for the 2 children
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        // Internal node will have the minimum of both of its children
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

// Function to update a node
void update(int node, int start, int end, int l, int r, long double val)
{
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] += lazy[node]; // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if(start > end or start > r or end < l) return; // Current segment is not within range [l, r]
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, l, r, val); // Updating left child
    update(node*2 + 1, mid + 1, end, l, r, val); // Updating right child
    tree[node] = min(tree[node*2], tree[node*2+1]); // Updating root with min value 
}

// Function to query the tree
long double query(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l) return std::numeric_limits<long double>::max(); // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += lazy[node]; // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if(start >= l and end <= r) // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    long double p1 = query(node*2, start, mid, l, r); // Query left child
    long double p2 = query(node*2 + 1, mid + 1, end, l, r); // Query right child
    return min(p1, p2);
}


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
        // cap[i] /= 1000000000;
    }

    /** 
     * ! MODIFIED
     * ALGORITHM: Euler Tour
     * PURPOSE: Flattens a tree so that each range contains any subtree range
     * CONSTRAINT: Graph must be a tree
     * TIME: O(V)
    */
    vector<pii> tour(n);
    vector<int> idx(2 * n);
    int h = 0;
    int i = -1;
    int s = -1;
    function<void(int, int)> dfs;
    dfs = [&](int node, int parent){
        d[node] = d[parent] + 1;
        h = max(h, d[node]);
        tour[node].first = ++i;
        idx[i] = s + 1;
        for (int x : adj[node]){
            if (x != parent){
                dfs(x, node);
            }
        }
        tour[node].second = ++i;
        idx[i] = ++s;
    };

    // root at 0
    dfs(0, 0);

    vector<long double> mult(n);
    rep(i, 0, n){
        mult[i] = ((long double) pow((long double) 2, (long double) (-h + d[i])));
    }

    LazySegtree<Info, Tag> st(n);
    build(1, 0, n-1);

    vector<long double> curr(n, 0);

    auto add_node = [&](int node, long double val){
        pii t = tour[node];
        assert(val <= 0);
        assert(idx[t.second] >= idx[t.first]);
        st.range_update(idx[t.second], n - 1, Tag{ADD, -val});
        st.range_update(idx[t.first], n - 1, Tag{ADD, val});
        update(1, 0, n - 1, idx[t.second], n - 1, -val);
        update(1, 0, n - 1, idx[t.first], n - 1, val);
        
        curr[node] += val;
    };

    auto query_node = [&](int i){
        return -query(1, 0, n - 1, i, n - 1) + query(1, 0, n - 1, i, i);
        // return -st.range_query(i, n - 1).sum + st.range_query(i, i).sum;
    };

    rep(i, 0, n){
        long double fac = -cap[i] * mult[i];

        add_node(i, fac);


        rep(j, 0, n){
            cout << query(1, 0, n - 1, j, j) << " ";
        }

        cout << endl;
    }

    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);

    rep(i, 0, q){
        int t, x; cin >> t >> x;
        --x;

        if (t == 1){
            long double v; cin >> v;
            // add_node(x, v * mult[x]);

            continue;
        }

        long double propagated = query_node(idx[tour[x].second]);
        long double actual = propagated + curr[x] + cap[x] * mult[x];
        actual /= mult[x];

        cout << min(actual, cap[x]) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}