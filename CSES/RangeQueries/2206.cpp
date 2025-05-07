/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-06
 * Contest: CSES Problemset
 * Problem: 2206
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
	const T UNIT = {0, 0, 0};

	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) { 
        return {min(a[0], b[0] + a[2]), min(b[1], a[1] + b[2]), a[2] + b[2]};
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

    ll walk(ll ind, int at, int at_left, int at_right){
        if (at_left == at_right) {
			return segtree[at][0];
		}
		ll mid = (at_left + at_right) / 2;
		if (ind <= mid) {
			return min(walk(ind, 2 * at, at_left, mid), segtree[2 * at + 1][0] + mid + 1 - ind);
		} else {
			return min(walk(ind, 2 * at + 1, mid + 1, at_right), segtree[2 * at][1] + ind - mid);
		}
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

    ll walk_query(ll ind){
        return walk(ind, 1, 0, len - 1);
    }

    // [start, end]
	T range_sum(int start, int end) { return range_sum(start, end, 1, 0, len - 1); }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<array<ll, 3>> pizza(n);
    rep(i, 0, n){
        ll p; cin >> p;
        pizza[i] = {p, p, 1};
    }

    RecSegmentTree<array<ll, 3>> st(pizza);

    rep(i, 0, q){
        int c, k; cin >> c >> k;
        --k;
        if (c == 2){
            cout << st.walk_query(k) << endl;
            continue;
        }

        ll x; cin >> x;

        pizza[k] = {x, x, 1};
        st.set(k, pizza[k]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}