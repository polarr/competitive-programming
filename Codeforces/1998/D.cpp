/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-11
 * Contest: Codeforces 1998
 * Problem: D
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
		T ans = UNIT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { ans = combine(ans, segtree[start++]); }
			if (end % 2 == 1) { ans = combine(ans, segtree[--end]); }
		}
		return ans;
	}
};

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> adj(n);
    vi mx(n - 1);
    rep(i, 0, n - 1){
        mx[i] = i + 1;
        adj[i].pb(i + 1);
    }

    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        mx[a] = max(mx[a], b);
        adj[a].pb(b);
    }

    vi d(n, -1);
    queue<pii> q;
    q.push({0, 0});
    while (!q.empty()){
        pii curr = q.front();
        q.pop();

        if (d[curr.first] != -1){
            continue;
        }

        d[curr.first] = curr.second;

        for (int node : adj[curr.first]){
            q.push({node, curr.second + 1});
        }
    }
    
    SegmentTree<int> st(n);
    rep(i, 0, n - 1){
        st.set(i, mx[i] - d[i]);
    }

    vi ans(n - 1, 1);
    rep(i, 1, n - 1){
        int query = st.query(0, i);
        if (query > i + 1){
            ans[i] = 0;
        }
    }

    rep(i, 0, n - 1){
        cout << ans[i];
    }

    cout << endl;
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