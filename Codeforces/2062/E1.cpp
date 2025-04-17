/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-17
 * Contest: Codeforces 2062
 * Problem: E1
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
	const T UNIT = std::numeric_limits<T>().min();

    T combine(T a, T b){
        return max(a, b);
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
        if (end <= start){
            return UNIT;
        }
		T ans = UNIT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { ans = combine(ans, segtree[start++]); }
			if (end % 2 == 1) { ans = combine(ans, segtree[--end]); }
		}
		return ans;
	}
};

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
        ans[node].second = ++i;
    };

    // root at 0
    tour(0, 0);

    return ans;
}

void solve(){
    int n; cin >> n;

    vi w(n);
    rep(i, 0, n){
        cin >> w[i];
    }

    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<pii> tour = eulerTour(n, adj);
    vector<bool> good(n, false);

    SegmentTree<int> st(2 * n + 2);
    rep(i, 0, n){
        st.set(tour[i].first, w[i]);
        st.set(tour[i].second, w[i]);
    }

    rep(i, 0, n){
        int mx1 = st.query(0, tour[i].first);
        int mx2 = st.query(tour[i].second + 1, 2 * n + 1);

        if (mx1 > w[i] || mx2 > w[i]){
            good[i] = true;
        }
    }

    int maxW = 0;
    int ans = -1;

    rep(i, 0, n){
        if (good[i]){
            if (w[i] > maxW){
                maxW = w[i];
                ans = i;
            }
        }
    }

    if (ans == -1){
        cout << 0 << endl;
        return;
    }

    cout << ans + 1 << endl;
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