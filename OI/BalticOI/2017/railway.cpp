/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-26
 * Contest: Baltic OI 2017
 * Problem: railway
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
	const T UNIT = std::numeric_limits<T>().max();

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
 * REQUIRE: Segment Tree (or another RMQ structure)
 */
class LCA {
    private: 
        /** IN SEGTREE REMEMBER TO SET UNIT = pii{INT_MAX, INT_MAX} */
        SegmentTree<pii> st;
        vi first;
        vi second;
        vi tour;
        vi d;

    public:
        LCA(int n, vector<vector<int>> &adj) : st(2 * n - 1), first(n), second(n), tour(2 * n - 1), d(n) {
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
                        second[node] = i;
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
            /** IN SPARSE TABLE REMEMBER TO USE INCLUSIVE BOUND range.second */
            return st.query(range.first, range.second + 1).second;
        }

        vi lca(vi &list){
            vector<pii> sortList;

            for (int x : list){
                sortList.pb({first[x], x});
            }

            sort(all(sortList));
            
            int l = st.query(sortList[0].first, sortList[sortList.size() - 1].first + 1).second;

            vi ans = {l};

            rep(i, 0, sortList.size() - 1){
                int x = sortList[i].second;
                int y = sortList[i + 1].second;
                if (second[x] < first[y]){
                    ans.pb(x);
                }
            }

            return ans;
        }

        int dist(int a, int b){
            return d[a] + d[b] - 2 * d[lca(a, b)];
        }
};

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<vi> adj(n);

    map<pii, int> idx;
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;

        adj[a].pb(b);
        adj[b].pb(a);
        idx[{a, b}] = idx[{b, a}] = i + 1;
    }

    LCA lca(n, adj);

    vector<vi> want(m);
    vi cnt(n, 0);
    rep(i, 0, m){
        int s; cin >> s;
        rep(j, 0, s){
            int x; cin >> x;
            --x;
            want[i].pb(x);
        }

        vi a = lca.lca(want[i]);

        int l = a[0];
        cnt[l]++;

        rep(j, 1, a.size()){
            cnt[a[j]]--;
        }
    }

    vi ans;

    function<void(int, int, int)> dfs;
    dfs = [&](int x, int par, int sum){
        if (sum >= k){
            ans.pb(idx[{par, x}]);
        }

        sum += cnt[x];

        for (int node : adj[x]){
            if (node == par) continue;

            dfs(node, x, sum);
        }
    };

    dfs(0, -1, 0);

    cout << ans.size() << endl;
    for (int x : ans){
        cout << x << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}