/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-09
 * Contest: CSES Problemset
 * Problem: 1188
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
	const T UNIT = {0, 0, 0, 0, 0, 0};

	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) {
        int l0 = a[2] + (a[2] == a[0] ? b[2]:0);
        int l1 = a[3] + (a[3] == a[0] ? b[3]:0);
        int r0 = b[4] + (b[4] == b[0] ? a[4]:0);
        int r1 = b[5] + (b[5] == b[0] ? a[5]:0);

        return {
            a[0] + b[0],
            max(max(a[1], b[1]), max(a[4] + b[2], a[5] + b[3])),
            l0,
            l1,
            r0,
            r1
        };
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
    string s; cin >> s;
    int n = s.size();

    vi arr(n);

    RecSegmentTree<array<int, 6>> st(n);

    rep(i, 0, n){
        int x = s[i] - '0';
        arr[i] = x;
        st.set(i, {1, 1, x == 0, x == 1, x == 0, x == 1});
    }

    int m; cin >> m;
    rep(i, 0, m){
        int j; cin >> j;
        --j;
        arr[j] = !arr[j];
        int x = arr[j];
        st.set(j, {1, 1, x == 0, x == 1, x == 0, x == 1});
        cout << st.range_sum(0, n - 1)[1] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}