/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-20
 * Contest: 
 * Problem: G
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
    int n, q; cin >> n >> q;

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    SegmentTree<int> st(n);
    rep(i, 0, n) {
        st.set(i, arr[i]);
    }

    rep(qq, 0, q) {
        int c; cin >> c;
        if (c == 1) {
            int i, x; cin >> i >> x;
            --i;
            st.set(i, x);
        } else {
            int l, r; cin >> l >> r;
            --l; --r;

            int lo = l, hi = r;
            while (lo < hi) {
                int mid = (lo + hi + 1)/2;

                int mn = st.query(l, mid + 1);
                int len = mid - l;
                if (mn >= len) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }

            int mn = st.query(l, lo + 1);
            int len = lo - l;

            if (mn == len) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
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