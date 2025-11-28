/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-27
 * Contest: CSES Problemset
 * Problem: 3356
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
	const T UNIT = -1;

	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) {
        return max(a, b);
    }

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

  public:
	RecSegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, UNIT); };

	RecSegmentTree(const vector<T> &arr) : len(arr.size()) {
		segtree = vector<T>(len * 4, UNIT);
		build(arr, 1, 0, len - 1);
	}

	void set(int ind, T val) { set(ind, val, 1, 0, len - 1); }

    // [start, end]
	T range_sum(int start, int end) { return range_sum(start, end, 1, 0, len - 1); }
};

void solve(){
    int n, q; 
    cin >> n >> q;

    map<int, set<int>> vals;
    vi arr(n);

    RecSegmentTree<int> st(n);
    rep(i, 0, n) {
        int a; cin >> a;
        arr[i] = a;
        auto j = vals[a].upper_bound(i);
        if (j != vals[a].begin()) {
            j = prev(j);
            st.set(i, *j);
        }
        vals[a].insert(i);
    }

    rep(i, 0, q) {
        int c; cin >> c;
        if (c == 1) {
            int k, u; cin >> k >> u;
            --k;
            int v = arr[k];
            auto j = vals[v].find(k);
            auto nx = next(j);
            if (nx != vals[v].end()){
                int pr = -1;
                if (j != vals[v].begin()) {
                    pr = *prev(j);
                }
                st.set(*nx, pr);
            }
            vals[v].erase(k);
            arr[k] = u;
            j = vals[u].upper_bound(k);
            if (j != vals[u].end()) {
                st.set(*j, k);
            }

            if (j != vals[u].begin()) {
                j = prev(j);
                st.set(k, *j);
            } else {
                st.set(k, -1);
            }

            vals[u].insert(k);
        } else {
            int a, b; cin >> a >> b;
            --a; --b;
            int mx = st.range_sum(a, b);
            cout << (mx >= a ? "NO" : "YES") << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}