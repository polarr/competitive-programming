/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-06
 * Contest: USACO 2016 Feb Platinum
 * Problem: 1
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

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;

const string iofilename = "balancing";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

/** 
 * DATASTRUCTURE: Recursive Segment Tree
 * PURPOSE: Segment Tree with more extensibility
 * TIME: O(log n) to update and query, but worse constant factor than the iterative version
*/
template <class T> class RecSegmentTree {
  private:
	const pii UNIT = {0, 0};

	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) { return {a.first + b.first, a.second + b.second}; }

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

    int walk(int at, int at_left, int at_right, pii lc, pii rc) {
		if (at_left == at_right) {
			return min(max({segtree[at].first + lc.first, segtree[at].second + lc.second, rc.first, rc.second}), max({segtree[at].first + rc.first, segtree[at].second + rc.second, lc.first, lc.second})); 
		}
		int mid = (at_left + at_right) / 2;
        int tryl = max(segtree[2 * at].first + lc.first, segtree[2 * at].second + lc.second);
        int tryr = max(segtree[2 * at + 1].first + rc.first, segtree[2 * at + 1].second + rc.second);

		if (tryl > tryr) {
			return walk(2 * at, at_left, mid, lc, {segtree[2 * at + 1].first + rc.first, segtree[2 * at + 1].second + rc.second});
		}
		
        return walk(2 * at + 1, mid + 1, at_right, {segtree[2 * at].first + lc.first, segtree[2 * at].second + lc.second}, rc);
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

    int walk_query(int start, int end){
        return walk(1, start, end, UNIT, UNIT);
    }

    // [start, end]
	T range_sum(int start, int end) { return range_sum(start, end, 1, 0, len - 1); }
};

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n; fin >> n;

    vector<vi> cows(MAX_N);
    vector<pii> cowCount(MAX_N, {0, 0});

    rep(i, 0, n){
        int x, y; fin >> x >> y;
        cows[y].pb(x);
        cowCount[x].first++;
    }

    RecSegmentTree<pii> st(cowCount);

    int ans = INT_MAX;

    for (int i = 0; i < MAX_N; i += 2){
        if (i != 0){
            int y = i - 1;
            for (int x : cows[y]){
                cowCount[x].first--;
                cowCount[x].second++;
                st.set(x, cowCount[x]);
            }
        }

        ans = min(ans, st.walk_query(0, MAX_N - 1));
    }

    fout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}