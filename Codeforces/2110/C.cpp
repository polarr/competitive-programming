/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-24
 * Contest: Codeforces 2110
 * Problem: C
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

    vi d(n);
    rep(i, 0, n){
        cin >> d[i];
    }

    SegmentTree<int> st(n);

    int has = 0;

    vector<pii> ranges(n);
    rep(i, 0, n){
        if (d[i] == 1){
            has++;
        }

        cin >> ranges[i].first;
        cin >> ranges[i].second;

        st.set(i, ranges[i].second - has);
    }

    int add = 0;
    rep(i, 0, n){
        if (d[i] != -1){
            continue;
        }

        if (st.query(i, n) - add > 0){
            add++;
            d[i] = 1;
        } else {
            d[i] = 0;
        }
    }

    int curr = 0;
    bool can = true;
    rep(i, 0, n){
        curr += d[i];
        if (curr < ranges[i].first || curr > ranges[i].second){
            can = false;
            break;
        }
    }

    if (!can){
        cout << -1 << endl;
        return;
    }

    rep(i, 0, n){
        cout << d[i] << " ";
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