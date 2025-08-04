/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-16
 * Contest: CSES Problemset
 * Problem: 3314
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
    int n; cin >> n;
    vi h(n);
    rep(i, 0, n){
        cin >> h[i];
    }

    vi dp(n, 0);
    dp[n - 1] = 1;
    
    SegmentTree<int> st(n);
    st.set(n - 1, 1);

    stack<pii> nle;
    nle.push({h[n - 1], n - 1});

    int ans = 1;

    for (int i = n - 2; i >= 0; i--){
        while(!nle.empty() && nle.top().first < h[i]){
            nle.pop();
        }

        int j = n;
        if (!nle.empty()){
            j = nle.top().second;
        }

        dp[i] = 1 + st.query(i + 1, j);
        ans = max(ans, dp[i]);
        st.set(i, dp[i]);
        nle.push({h[i], i});
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}