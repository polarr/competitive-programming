/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-09
 * Contest: CSES Problemset
 * Problem: 1740
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

const int PAD = 1e6;

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

void solve(){
    int n; cin >> n;
    vector<pii> h(n, {0, INT_MIN});
    vector<vector<pii>> xs(2 * PAD + 1);
    vector<vector<pii>> v(2 * PAD + 1);

    rep(i, 0, n){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += PAD;
        y1 += PAD;
        x2 += PAD;
        y2 += PAD;

        if (x1 == x2){
            v[x1].pb(minmax(y1, y2));
            continue;
        }

        h[i] = {0, y1};
        xs[min(x1, x2)].pb({0, i});
        xs[max(x1, x2)].pb({1, i});
    }

    SegmentTree<int> st(2 * PAD + 2);
    vi y(2 * PAD + 1);

    ll ans = 0;

    rep(x, 0, 2 * PAD + 1){
        for (pii vert : v[x]){
            y[vert.first]++;
            y[vert.second + 1]--;
            st.set(vert.first, y[vert.first]);
            st.set(vert.second + 1, y[vert.second + 1]);
        }

        for (pii event : xs[x]){
            int add = st.query(0, h[event.second].second + 1);
            if (event.first == 0){
                h[event.second].first = add;
            } else {
                ans += (ll)(add - h[event.second].first);
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}