/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-10
 * Contest: Codeforces 2049
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
 * DATASTRUCTURE: Recursive Segment Tree
 * PURPOSE: Segment Tree with more extensibility
 * TIME: O(log n) to update and query, but worse constant factor than the iterative version
*/
template <class T> class SegmentTree {
  private:
	const T UNIT = 1e16;

	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) { return min(a, b); }

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
	SegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, UNIT); };

	SegmentTree(const vector<T> &arr) : len(arr.size()) {
		segtree = vector<T>(len * 4, UNIT);
		build(arr, 1, 0, len - 1);
	}

	void set(int ind, T val) { set(ind, val, 1, 0, len - 1); }

    // [start, end]
	T range_sum(int start, int end) { 
        if (end < start) return UNIT;
        return range_sum(start, end, 1, 0, len - 1); }
};

void solve(){
    int n, m; ll k; cin >> n >> m >> k;

    vector<vl> grid(n, vl(m));
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> grid[i][j];
        }
    }

    vector<vector<SegmentTree<ll>>> query(n);

    rep(i, 0, n){
        rep(j, 0, m){
            int l = j + 1;
            vl sum(m);
            ll curr = 0;
            rep(ii, 0, l){
                curr += grid[i][(m - ii) % m];
            }
            sum[0] = curr;
            rep(ii, 1, m){
                curr += grid[i][ii];
                curr -= grid[i][(ii + m - l) % m];
                sum[ii] = curr + k * ii;
            }

            query[i].pb(SegmentTree<ll>(sum));
        }
    }

    vector<vl> dp(n, vl(m, 0));
    rep(j, 0, m){
        ll nx = 0;
        int r = m - 1;
        int l = r - j;
        ll add1 = query[n - 1][l].range_sum(0, r - 1);
        ll add2 = query[n - 1][l].range_sum(r, m - 1);

        add1 += k * (m - r);
        add2 -= k * r;

        ll ans = min(add1, add2) + nx;

        dp[n - 1][j] = ans;
    }

    for (int i = n - 2; i >= 0; i--){
        rep(j, 0, m){
            ll ans = LLONG_MAX;
            rep(r, j, m){
                ll nx = dp[i + 1][r];
                int l = r - j;
                ll add1 = query[i][l].range_sum(0, r - 1);
                ll add2 = query[i][l].range_sum(r, m - 1);

                add1 += k * (m - r);
                add2 -= k * r;

                ans = min(ans, min(add1, add2) + nx);
            }

            dp[i][j] = ans;
        }
    }

    cout << dp[0][0] << endl;
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