/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-14
 * Contest: CSES Problemset
 * Problem: 1688
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
 * DATASTRUCTURE: Segment Tree
 * PURPOSE: Range Updates and Queries
 * TIME: O(log n) to update and query
*/
template <class T> class SegmentTree {
  private:
	const T UNIT = pii{INT_MAX, INT_MAX};

    T combine(T a, T b){
        return min(a, b);
    }

	vector<T> segtree;
	int len;

  public:
	SegmentTree(int len) : len(len), segtree(len * 2, UNIT) {}

	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = combine(segtree[ind], segtree[ind ^ 1]);
		}
	}

    // [start, end)
	T query(int start, int end) {
		T ans = UNIT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { ans = combine(ans, segtree[start++]); }
			if (end % 2 == 1) { ans = combine(ans, segtree[--end]); }
		}
		return ans;
	}
};

/**
 * ALGORITHM: Lowest Common Ancestor
 * PURPOSE: Lowest common ancestor node of two nodes, also supports depth and distance of nodes
 * TIME: O(n) preprocessing, O(log N) lca query
 * REQUIRE: Segment Tree
 */
class LCA {
    private: 
        /** REMEMBER TO SET UNIT = pii{INT_MAX, INT_MAX} */
        SegmentTree<pii> st;
        vi first;
        vi tour;
        vi d;

    public:
        LCA(int n, vector<vector<int>> &adj) : st(2 * n - 1), first(n), tour(2 * n - 1), d(n) {
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

            rep(i, 0, 2 * n - 1){
                st.set(i, {d[tour[i]], tour[i]});
            }
        }

        int depth(int node){
            return d[node];
        }

        int lca(int a, int b){
            pii range = minmax(first[a], first[b]);
            return st.query(range.first, range.second + 1).second;
        }

        int dist(int a, int b){
            return d[a] + d[b] - 2 * d[lca(a, b)];
        }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int a; cin >> a;
        --a;
        adj[i + 1].pb(a);
        adj[a].pb(i + 1);
    }

    LCA lca = LCA(n, adj);

    rep(i, 0, q){
        int a, b; cin >> a >> b;
        --a; --b;
        cout << lca.lca(a, b) + 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}