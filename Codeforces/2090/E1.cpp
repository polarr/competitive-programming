/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-22
 * Contest: Codeforces 2090
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
 * DATASTRUCTURE: Segment Tree
 * PURPOSE: Range Updates and Queries
 * TIME: O(log n) to update and query
*/
template <class T> class SegmentTree {
  private:
	const T UNIT = std::numeric_limits<T>().max();

    T combine(T a, T b){
        return min(a, b);
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

    vl a(n), b(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    rep(i, 0, n){
        cin >> b[i];
    }

    SegmentTree<ll> st(2 * n + 1);

    vl d(2 * n + 1, 0);
    ll sum = 0;
    rep(i, 0, 2 * n){
        sum += a[i % n] - b[i % n];
        d[i + 1] = sum;
    }

    rep(i, 0, 2 * n + 1){
        st.set(i, d[i]);
    }

    int ans = 0;

    rep(i, 0, n){
        ll sub = d[i];

        // smallest j must be sub
        int lo = i + 1;
        int hi = n + lo - 1;

        while(lo < hi){
            int mid = (lo + hi)/2;

            if (st.query(i + 1, mid + 1) <= sub){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        ans = max(ans, lo - i);
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