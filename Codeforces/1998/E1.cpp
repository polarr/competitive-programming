/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-11
 * Contest: Codeforces 1998
 * Problem: E1
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
	const T UNIT = {LLONG_MIN, 0};

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
    
    // int walk(int dir, T val, int at, int at_left, int at_right) {
	// 	if (at_left == at_right) {
	// 		return segtree[at].second;
	// 	}
	// 	int mid = (at_left + at_right) / 2;
    //     if (dir == 0){
    //         if (val <= mid) {
    //             set(ind, val, 2 * at, at_left, mid);
    //         } else {
    //             set(ind, val, 2 * at + 1, mid + 1, at_right);
    //         }
    //         segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
    //     } else {

    //     }
	// }

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
    int n, x; cin >> n >> x;

    vl a(n);
    vl pf(n + 1, 0), sf(n + 1, 0);
    rep(i, 0, n){
        cin >> a[i];
    }

    rep(i, 0, n){
        pf[i + 1] = pf[i] + a[i];
        sf[n - 1 - i] = sf[n - i] + a[n - 1 - i]; 
    }

    SegmentTree<ll> lq(n + 1), rq(n + 1);
    rep(i, 0, n){
        lq.set(i, a[i] - pf[i]);
        rq.set(i, a[i] - sf[i + 1]);
    }

    int ans = 0;

    rep(i, 0, n){
        int l = i, r = i;
        ll tot = a[i];
        int dir = 0;
        int cnt = 0;
        bool good = true;
        while (l > 0 || r < n - 1){
            // cerr << l << " " << r << endl;
            if (cnt == 2){
                good = false;
                break;
            }

            if (dir == 0){
                if (l != 0){
                    int lo = 0, hi = l;
                    while (lo < hi){
                        int mid = (lo + hi)/2;
                        ll query = rq.query(mid, l);
                        // cerr << tot << " " << query + sf[l] << " " << lo << " " << hi << endl;
                        if (mid == l || query <= tot - sf[l]){
                            hi = mid;
                        } else {
                            lo = mid + 1;
                        }
                    }

                    tot += pf[l] - pf[lo];

                    if (l == lo){
                        cnt++;
                    }
                    l = lo;
                } else {
                    cnt++;
                }

                dir = 1;
            } else {
                // dir == 1
                if (r != n - 1){
                    int lo = r, hi = n - 1;
                    while (lo < hi){
                        int mid = (lo + hi + 1)/2;
                        ll query = lq.query(r + 1, mid + 1);
                        if (mid == r || query <= tot - pf[r + 1]){
                            lo = mid;
                        } else {
                            hi = mid - 1;
                        }
                    }

                    tot += pf[lo + 1] - pf[r + 1];

                    if (r == lo){
                        cnt++;
                    }
                    r = lo;
                } else {
                    cnt++;
                }

                dir = 0;
            }
        }

        if (good){
            ans++;
        }
    }

    cout << ans << endl;
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