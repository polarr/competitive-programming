/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-11
 * Contest: IOI 2007
 * Problem: training
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
 * DATASTRUCTURE: Sparse Table
 * PURPOSE: Efficient RMQ
 * TIME: O(n log n) preprocessing and O(1) queries
 */
template <typename T> class SparseTable {
  private:
	int n, log2dist;
    vector<vector<T>> st;

  public:
	SparseTable(const vector<T> &v) {
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
 * TIME: O(n) preprocessing, O(log N) lca query
 * REQUIRE: Segment Tree (or another RMQ structure)
 */
class LCA {
    private: 
        /** IN SEGTREE REMEMBER TO SET UNIT = pii{INT_MAX, INT_MAX} */
        SparseTable<pii> st;
        vi first;
        vi last;
        vi tour;
        vi d;

    public:
        LCA(int n, vector<vector<int>> &adj) : st({{0, 0}}), first(n), last(n), tour(2 * n - 1), d(n) {
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
                last[node] = i;
            };

            // root at 0
            dfs(0, 0, 0);

            vector<pii> arr = vector<pii>(2 * n - 1);

            rep(i, 0, 2 * n - 1){
                arr[i] = {d[tour[i]], tour[i]};
            }

            st = SparseTable<pii>(arr);
        }

        int idx(int node){
            return first[node];
        }

        int depth(int node){
            return d[node];
        }

        int inSubtree(int a, int b){
            return first[a] <= first[b] && first[b] <= last[a];
        }

        int lca(int a, int b){
            pii range = minmax(first[a], first[b]);
            /** IN SPARSE TABLE REMEMBER TO USE INCLUSIVE BOUND range.second */
            return st.query(range.first, range.second).second;
        }

        int dist(int a, int b){
            return d[a] + d[b] - 2 * d[lca(a, b)];
        }
};

vector<vi> adj;
vi par;
vi branches;
vi branch;
vi bipartition;

void dfs(int node, int parent, int depth){
    par[node] = parent;
    branch[node] = 1 << branches[parent];
    branches[parent]++;
    bipartition[node] = depth % 2;

    for (int x : adj[node]){
        if (x == parent){
            continue;
        }

        dfs(x, node, depth + 1);
    }
}

void solve(){
    int n, m; cin >> n >> m;

    vector<array<int, 4>> edges(m);
    
    vector<vi> dp(n, vi(1 << 10));
    adj = vector<vi>(n);
    par = vi(n);
    branches = vi(n, 0);
    branch = vi(n);
    bipartition = vi(n, 0);

    int total = 0;

    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        if (c == 0){
            adj[a].pb(b);
            adj[b].pb(a);
        } else {
            total += c;
        }

        edges[i] = {0, c, a, b};
    }

    LCA lca = LCA(n, adj);

    rep(i, 0, m){
        edges[i][0] = lca.lca(edges[i][2], edges[i][3]);
    }

    // dp up the tree
    auto cmp = [&](array<int, 4> &x, array<int, 4> &y) { 
        return lca.idx(x[0]) > lca.idx(y[0]);
    };

    sort(all(edges), cmp);

    dfs(0, 0, 0);

    rep(i, 0, m){
        auto [x, c, a, b] = edges[i];

        // bad edges
        if (bipartition[a] != bipartition[b] && c != 0){
            continue;
        }

        // if connect a-b in subtree x
        int add = c;

        // remove path edges and add along the way
        int masked;
        int msk = 0;
        int curr = a;
        while(curr != x){
            add += dp[curr][msk];
            msk = branch[curr];
            curr = par[curr];
        }

        masked = msk;

        msk = 0, curr = b;
        while(curr != x){
            add += dp[curr][msk];
            msk = branch[curr];
            curr = par[curr];
        }

        masked |= msk;

        // go through all removals
        for (int mask = (1 << branches[x]) - 1; mask >= 0; mask--){
            if ((mask & masked) != 0){
                continue;
            }

            dp[x][mask] = max(dp[x][mask], add + dp[x][mask | masked]);
        }
    }

    cout << total - dp[0][0] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}