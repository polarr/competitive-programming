/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-23
 * Contest: 
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
    int n; cin >> n;
    ll mn = 0;
    vl a(n + 1, 0);
    rep(i, 1, n + 1){
        cin >> a[i];
        mn = max(mn, a[i]);
    }

    auto check = [&](ll x){
        vl dp(n + 1);
        SegmentTree<ll> st(n + 2);

        dp[0] = 0;
        st.set(0, 0);
        ll curr = 0;
        int j = 1;

        rep(i, 1, n + 1){
            st.set(i, a[i] + dp[i - 1]);
            curr += a[i];
            while (curr > x){
                curr -= a[j];
                j++;
            }

            dp[i] = st.query(j - 1, i + 1);
        }

        return dp[n] <= x;
    };

    ll lo = mn, hi =1e14;
    while (lo < hi){
        ll mid = (lo + hi)/2;
        if (check(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << endl;
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