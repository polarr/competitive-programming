/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-14
 * Contest: CSES Problemset
 * Problem: 1139
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


void solve(){
    int n; cin >> n;

    vector<vi> adj(n);
    vi d(n);
    rep(i, 0, n){
        cin >> d[i];
    }

    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<pii> tree = eulerTour(n, adj);

    vector<vi> pos(n);
    vi arr(n);
    rep(i, 0, n){
        pos[tree[i].second].pb(i);
        arr[tree[i].first] = d[i];
    }

    SegmentTree<int> st(n);
    vi ans(n);
    map<int, int> last;

    rep(i, 0, n){
        int x = arr[i];
        if (last.contains(x)){
            st.set(last[x], 0);
        }
        last[x] = i;
        st.set(i, 1);

        for (int j : pos[i]){
            ans[j] = st.query(tree[j].first, i + 1);
        }
    }

    rep(i, 0, n){
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}