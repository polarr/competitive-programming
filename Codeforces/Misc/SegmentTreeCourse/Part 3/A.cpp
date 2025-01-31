/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-30
 * Contest: Codeforces SegmentTreeCourse
 * Problem: A
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

    T update(T a, T b){
        return a + b;
    }

    T extract(T a, T b){
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
			segtree[ind / 2] = update(segtree[ind], segtree[ind ^ 1]);
		}
	}

	T query(int start, int end) {
		T ans = UNIT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { ans = extract(ans, segtree[start++]); }
			if (end % 2 == 1) { ans = extract(ans, segtree[--end]); }
		}
		return ans;
	}
};

void solve(){
    int n; cin >> n;

    SegmentTree<int> st(n);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        --x;

        cout << st.query(x, n) << " ";

        st.set(x, 1);
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}