/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-17
 * Contest: Codeforces 2117
 * Problem: H
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

const int MAX_N = 1e9;
const ll MOD = 1e9 + 7;

#include <bits/stdc++.h>
using namespace std;

/** 
 * DATASTRUCTURE: Recursive Segment Tree
 * PURPOSE: Segment Tree with more extensibility
 * TIME: O(log n) to update and query, but worse constant factor than the iterative version
*/
template <class T> class RecSegmentTree {
  private:
	const T UNIT = {MAX_N, 0, 0, 0};

	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) { 
        if (a[0] == MAX_N){
            return b;
        }
        if (b[0] == MAX_N){
            return a;
        }

        return {max(a[0] + b[2], b[0]), max(a[1], b[1] + a[2]), a[2] + b[2], max({a[3], b[3], b[1] + a[0]})};
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
    int n, q; cin >> n >> q;

    vi a(n);
    vector<vi> colorStart(n);
    rep(i, 0, n) {
        cin >> a[i];
        --a[i];
        colorStart[a[i]].pb(i);
    }

    vector<vector<array<int, 3>>> colors(n);
    rep(i, 0, q){
        int j, x; cin >> j >> x;
        --j; --x;
        colors[a[j]].pb({i, j, x});
        a[j] = x;
        colors[a[j]].pb({i, j, x});
    }

    vector<array<int, 4>> start(n, {-1, -1, -1, -1});
    RecSegmentTree<array<int, 4>> st(start);

    vector<vector<pii>> changes(q);

    rep(c, 0, n){
        vi modified;
        for (int i : colorStart[c]){
            st.set(i, {1, 1, 1, 1});
            modified.pb(i);
        }

        int cnt = 0;
        int ans = st.range_sum(0, n - 1)[3];
        changes[0].pb({1, ans});

        for (auto &[i, j, x] : colors[c]){
            modified.pb(j);
            if (x == c){
                st.set(j, {1, 1, 1, 1});
            } else {
                st.set(j, {-1, -1, -1, -1});
            }

            changes[i].pb({0, ans});

            ans = st.range_sum(0, n - 1)[3];
            changes[i].pb({1, ans});

            cnt++;
        }

        for (int i : modified){
            st.set(i, {-1, -1, -1, -1});
        }
    }

    multiset<int> ms;

    rep(i, 0, q){
        for (pii change : changes[i]){
            if (change.first == 0){
                ms.erase(ms.find(change.second));
            } else {
                ms.insert(change.second);
            }
        }

        cout << *prev(ms.end())/2 << " ";
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