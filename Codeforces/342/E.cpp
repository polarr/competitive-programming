/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-27
 * Contest: Codeforces 342
 * Problem: E
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
const int INF = 1e6;

template <typename T> class SparseTable {
  private:
	int n, log2dist;
	vector<vector<T>> st;

  public:
    SparseTable() = default;
	SparseTable(const vector<T> &v) {
        build(v);
    }
	void build(const vector<T> &v) {
		n = (int)v.size();
		log2dist = 1 + (int)log2(n);
		st.resize(log2dist);
		st[0] = v;
		for (int i = 1; i < log2dist; i++) {
			st[i].resize(n - (1 << i) + 1);
			for (int j = 0; j + (1 << i) <= n; j++) {
				st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	/** @return minimum on the range [l, r] */
	T query(int l, int r) {
		int i = (int)log2(r - l + 1);
		return min(st[i][l], st[i][r - (1 << i) + 1]);
	}
};

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

struct CentroidDecomposition {
	vector<vector<int>> adj;
    vector<bool> is_removed;
    vector<int> subtree_size;

    /** DFS to calculate the size of the subtree rooted at `node` */
    int get_subtree_size(int node, int parent = -1) {
        subtree_size[node] = 1;
        for (int child : adj[node]) {
            if (child == parent || is_removed[child]) { continue; }
            subtree_size[node] += get_subtree_size(child, node);
        }
        return subtree_size[node];
    }

    /**
     * Returns a centroid (a tree may have two centroids) of the subtree
     * containing node `node` after node removals
     * @param node current node
     * @param tree_size size of current subtree after node removals
     * @param parent parent of u
     * @return first centroid found
     */
    int get_centroid(int node, int tree_size, int parent = -1) {
        for (int child : adj[node]) {
            if (child == parent || is_removed[child]) { continue; }
            if (subtree_size[child] * 2 > tree_size) {
                return get_centroid(child, tree_size, node);
            }
        }
        return node;
    }

    /** Build up the centroid decomposition recursively */
    void build_centroid_decomp(int node, int par, vector<int> &ans) {
        int centroid = get_centroid(node, get_subtree_size(node));

        ans[centroid] = par;

        is_removed[centroid] = true;

        for (int child : adj[centroid]) {
            if (is_removed[child]) { continue; }
            build_centroid_decomp(child, centroid, ans);
        }
    }

    vector<int> build(int n, vector<vi> a){
        adj = a;
        is_removed = vector<bool>(n);
        subtree_size = vector<int>(n);
        vector<int> ans(n, -1);

        build_centroid_decomp(0, -1, ans);
        return ans;
    }
};

void solve(){
    int n, m; cin >> n >> m;

    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    LCA lca(n, adj);
    CentroidDecomposition centroid;
    vector<int> par = centroid.build(n, adj);
    vi st_ans(n, INF);

    auto update = [&](int node){
        int curr = node;
        while (curr != -1){
            st_ans[curr] = min(st_ans[curr], lca.dist(curr, node));
            curr = par[curr];
        }
    };

    auto query = [&](int node){
        int ans = INF;
        int curr = node;
        while (curr != -1){
            ans = min(ans, lca.dist(node, curr) + st_ans[curr]);
            curr = par[curr];
        }

        return ans;
    };

    update(0);

    rep(i, 0, m){
        int c, v; cin >> c >> v;
        --c; --v;
        if (c == 0){
            update(v);
        } else {
            cout << query(v) << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}