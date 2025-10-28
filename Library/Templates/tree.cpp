/**
 * Template by 1egend (polarity.sh)
 * Template: tree
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
const ll INF = LLONG_MAX;

/** 
 * ALGORITHM: Topological Sort
 * PURPOSE: Sorts a DAG's vertices such that each directed edge points forward
 * CONSTRAINT: Graph must be a DAG
 * TIME: O(V)
*/
vector<int> toposort(int n, vector<vector<int>> &adj){
    vector<int> degree(n, 0);
    queue<int> q; // use pq for lexicographical sorting
    for (int i = 0; i < n; i++){
        for (int j : adj[i]){
            degree[j]++;
        }
    }

    for (int i = 0; i < n; i++){
        if (degree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int i = q.front();
        ans.pb(i);
        q.pop();

        for (int j : adj[i]){
            if (degree[j] == 0){
                continue;
            }

            degree[j]--;
            if (degree[j] == 0){
                q.push(j);
            }
        }
    }

    return ans;
}

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

/**
 * ALGORITHM: Lowest Common Ancestor
 * PURPOSE: Lowest common ancestor node of two nodes, also supports depth and distance of nodes
 * TIME: O(n log n) preprocessing, O(1) lca query
 * REQUIRE: Sparse Table (or another RMQ structure)
 */
class LCA {
    private: 
        /** IN SEGTREE REMEMBER TO SET UNIT = pii{INT_MAX, INT_MAX} */
        SparseTable<pii> st;
        vi first;
        vi tour;
        vi d;

    public:
        LCA(int n, vector<vector<int>> &adj) : first(n), tour(2 * n - 1), d(n) {
            int i = -1;
            function<void(int, int, int)> dfs;
            dfs = [&](int node, int parent, int depth){
                tour[++i] = node;
                first[node] = i;
                d[node] = depth;
                for (int x : adj[node]){
                    if (x != parent){
                        dfs(x, node, depth + 1);
                        tour[++i] = node;
                    }
                }
            };

            // root at 0
            dfs(0, 0, 0);

            vector<pii> table(2 * n - 1);

            rep(i, 0, 2 * n - 1){
                table[i] = {d[tour[i]], tour[i]};
            }

            st.build(table);

            /**
             * rep(i, 0, 2 * n - 1){
                st.set(i, {d[tour[i]], tour[i]});
                }
             */
        }

        int depth(int node){
            return d[node];
        }

        int lca(int a, int b){
            pii range = minmax(first[a], first[b]);
            /** IN SPARSE TABLE REMEMBER TO USE INCLUSIVE BOUND range.second, Segtree use exclusive bound range.second + 1 */
            return st.query(range.first, range.second).second;
        }

        int dist(int a, int b){
            return d[a] + d[b] - 2 * d[lca(a, b)];
        }
};

/**
 * Binary jumping
int lg = log2(n) + 1;
vector<vi> jp(n + 1, vi(lg, n));
vector<vector<pii>> jmp(n + 1, vector<pii>(lg, {n, 0}));

rep(j, 1, lg){
    rep(i, 0, n){
        int k = jp[i][j - 1];
        jp[i][j] = jp[k][j - 1];
    }
}

rep(j, 1, lg){
    rep(i, 0, n){
        pii a = jmp[i][j - 1];
        pii b = jmp[a.first][j - 1];
        jmp[i][j] = {b.first, a.second + b.second};
    }
}
 */

/** A data structure that can answer point update & range max queries. */
template <class T> class MaxSegmentTree {
  private:
	// const T DEFAULT = std::numeric_limits<T>().max();
	const T DEFAULT = 0;

	int len;
	vector<T> segtree;

  public:
	MaxSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = std::max(segtree[ind], segtree[ind ^ 1]);
		}
	}

	T range_max(int start, int end) {
		T max = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { max = std::max(max, segtree[start++]); }
			if (end % 2 == 1) { max = std::max(max, segtree[--end]); }
		}
		return max;
	}
};

template <class T, bool VALS_IN_EDGES> class HLD {
  private:
	int N, R, tim = 0;  // n, root node, time
	vector<vector<int>> adj;
	vector<int> par, siz, depth, rt, pos;  // parent, size, depth, root, position arrays
	MaxSegmentTree<T> segtree;             // Modify as needed

	/** Compute the size of each subtree and set parent-child relationship
	 * Subtree of node v corresponds to segment [ pos[v], pos[v] + sz[v] ) */
	void dfs_sz(int v) {
		if (par[v] != -1) adj[v].erase(find(adj[v].begin(), adj[v].end(), par[v]));
		for (int &u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfs_sz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}

	/** Assign positions for nodes
	  * Path from v to the last vertex in ascending heavy path
	    corresponds to [ pos[rt[v]], pos[v] ] */
	void dfs_hld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfs_hld(u);
		}
	}

	/** process all heavy path and combine their results */
	template <class B> void process(int u, int v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v]);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_IN_EDGES, pos[v]);
	}

  public:
	HLD(vector<vector<int>> adj_, int _R)
	    : N(adj_.size()), R(_R), adj(adj_), par(N, -1), siz(N, 1), depth(N), rt(N),
	      pos(N), segtree(N)  // modify as needed
	{
		rt[R] = R;
		dfs_sz(R);
		dfs_hld(R);
	}

	T query_path(int u, int v) {
		T res = 0;  // default value, modify depending on problem
		process(u, v, [&](int l, int r) {
			res = max(res, segtree.range_max(l, r + 1));  // modify depending on problem
		});
		return res;
	}

	void modify_node(int u, T val) { segtree.set(pos[u], val); }
};

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	int n, q;
// 	cin >> n >> q;
// 	vector<int> v(n);
// 	vector<vector<int>> adj(n);
// 	for (int i = 0; i < n; i++) { cin >> v[i]; }

// 	for (int i = 0; i < n - 1; i++) {
// 		int a, b;
// 		cin >> a >> b;
// 		--a, --b;
// 		adj[a].push_back(b);
// 		adj[b].push_back(a);
// 	}

// 	HLD<int, 0> H(adj, 0);

// 	for (int i = 0; i < n; i++) { H.modify_node(i, v[i]); }

// 	while (q--) {
// 		int type, s, a, b, x;
// 		cin >> type;
// 		if (type == 1) {
// 			cin >> s >> x;
// 			--s;
// 			H.modify_node(s, x);
// 		} else if (type == 2) {
// 			cin >> a >> b;
// 			--a, --b;
// 			cout << H.query_path(a, b) << " ";
// 		}
// 	}
// }