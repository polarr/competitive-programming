/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-19
 * Contest: 
 * Problem: E
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
    int n, k; cin >> n >> k;
    k = min(n, k);

    vi a(n), cnt(n + 1);
    map<int, int> nums;
    rep(i, 0, n){
        cin >> a[i];
        nums[a[i]]++;
        if (a[i] < n + 1){
            cnt[a[i]]++;
        }
    }

    vi cntnum(n + 1, 0);

    int unique = 0;

    sort(all(a));
    rep(i, 0, n){
        if (i == 0 || a[i] != a[i - 1]){
            unique++;
            cntnum[nums[a[i]]]++;
        }
    }

    SegmentTree<int> st(n + 1), diffs(n + 1);
    rep(i, 0, n + 1){
        if (cntnum[i] != 0) {
            st.set(i, cntnum[i] * (ll)i);
            diffs.set(i, cntnum[i]);
        }
    }

    auto check = [&](int m, int moves){
        return st.query(0, m + 1) <= moves;
    };

    int ans = INT_MAX;
    int prevhas = 0;
    rep(mex, 0, n + 1){
        if (mex > 0 && cnt[mex - 1] > 0){
            prevhas++;
        }

        int need = mex - prevhas;
        int eq = cnt[mex];

        if (eq != 0){
            unique--;
            cntnum[eq]--;
            diffs.set(eq, cntnum[eq]);
            st.set(eq, cntnum[eq] * eq);
        }

        if (need > k || eq > k){
            continue;
        }

        int moves = k - eq;
        int lo = 0, hi = n;
        while (lo < hi){
            int mid = (lo + hi + 1)/2;
            if (check(mid, moves)){
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        int curr = diffs.query(0, lo + 1);
        if (lo != n) curr += (moves - st.query(0, lo + 1))/(lo + 1);

        // cerr << mex << unique - curr << endl;
        ans = min(ans, unique - curr);
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