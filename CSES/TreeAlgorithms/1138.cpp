/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-14
 * Contest: CSES Problemset
 * Problem: 1138
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
	const T UNIT = 0;

    T combine(T a, T b){
        return a + b;
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

class PathQuery {
    private: 
        /** REMEMBER TO SET UNIT = pii{INT_MAX, INT_MAX} */
        SegmentTree<ll> st;
        vector<pii> range;
        vi tour;
        vl w;

    public:
        PathQuery(int n, vector<vector<int>> &adj, vl &weights) : st(2 * n), range(n), tour(2 * n), w(n) {
            w = weights;
            int i = -1;
            function<void(int, int, int)> dfs;
            dfs = [&](int node, int parent, int depth){
                tour[++i] = node;
                range[node].first = i;
                for (int x : adj[node]){
                    if (x != parent){
                        dfs(x, node, depth + 1);
                    }
                }

                tour[++i] = node;
                range[node].second = i;
            };

            // root at 0
            dfs(0, 0, 0);

            rep(i, 0, n){
                st.set(range[i].first, w[i]);
                st.set(range[i].second, -w[i]);
            }
        }

        void update(int a, ll weight){
            w[a] = weight;
            st.set(range[a].first, w[a]);
            st.set(range[a].second, -w[a]);
        }

        ll query(int a){
            return st.query(0, range[a].first + 1);
        }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<vi> adj(n);
    vl weights(n);
    rep(i, 0, n){
        cin >> weights[i];
    }
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    PathQuery p(n, adj, weights);

    rep(i, 0, q){
        int t; cin >> t;
        if (t == 1){
            int s; ll x; cin >> s >> x;
            --s;
            p.update(s, x);
            continue;
        }

        int s; cin >> s;
        --s;
        cout << p.query(s) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}