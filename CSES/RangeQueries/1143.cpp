/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-12
 * Contest: CSES Problemset
 * Problem: 1143
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
 * DATASTRUCTURE: Recursive Segment Tree
 * PURPOSE: Segment Tree with more extensibility
 * TIME: O(log n) to update and query, but worse constant factor than the iterative version
*/
template <class T> class RecSegmentTree {
  private:
	const T UNIT = 0;

	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) { return max(a, b); }

	void build(const vector<T> &arr, int at, int at_left, int at_right) {
		if (at_left == at_right) {
			segtree[at] = arr[at_left];
			return;
		}
		int mid = (at_left + at_right) / 2;
		build(arr, 2 * at, at_left, mid);
		build(arr, 2 * at + 1, mid + 1, at_right);
		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

	void set(int ind, T val, int at, int at_left, int at_right) {
		if (at_left == at_right) {
			segtree[at] = val;
			return;
		}
		int mid = (at_left + at_right) / 2;
		if (ind <= mid) {
			set(ind, val, 2 * at, at_left, mid);
		} else {
			set(ind, val, 2 * at + 1, mid + 1, at_right);
		}
		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

	T range_sum(int start, int end, int at, int at_left, int at_right) {
		if (at_right < start || end < at_left) { return UNIT; }
		if (start <= at_left && at_right <= end) { return segtree[at]; }
		int mid = (at_left + at_right) / 2;
		T left_res = range_sum(start, end, 2 * at, at_left, mid);
		T right_res = range_sum(start, end, 2 * at + 1, mid + 1, at_right);
		return combine(left_res, right_res);
	}

    int query(int at, int at_left, int at_right, T cmp) {
		if (at_left == at_right) {
			return at_left;
		}
		int mid = (at_left + at_right) / 2;
		if (segtree[2 * at] >= cmp) return query(2 * at, at_left, mid, cmp);
		return query(2 * at + 1, mid + 1, at_right, cmp);
	}

  public:
	RecSegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, UNIT); };

	RecSegmentTree(const vector<T> &arr) : len(arr.size()) {
		segtree = vector<T>(len * 4, UNIT);
		build(arr, 1, 0, len - 1);
	}

	void set(int ind, T val) { set(ind, val, 1, 0, len - 1); }

    int query(T cmp) { return query(1, 0, len - 1, cmp); }

    // [start, end]
	T range_sum(int start, int end) { return range_sum(start, end, 1, 0, len - 1); }
};

void solve(){
    int n, m; cin >> n >> m;

    RecSegmentTree<int> st(n);

    vi h(n);
    rep(i, 0, n){
        cin >> h[i];
        st.set(i, h[i]);
    }

    vi r(m);
    rep(i, 0, m){
        cin >> r[i];
    }

    rep(i, 0, m){
        int mx = st.range_sum(0, n - 1);
        if (mx < r[i]) {
            cout << 0 << endl;
            continue;
        }

        int x = st.query(r[i]);

        cout << x + 1 << endl;
        h[x] -= r[i];
        st.set(x, h[x]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}