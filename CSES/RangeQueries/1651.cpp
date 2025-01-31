/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-29
 * Contest: CSES Problemset
 * Problem: 1651
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
    int n, q; cin >> n >> q;

    SegmentTree<ll> st(n + 1);

    vector<ll> str(n + 1, 0);

    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        st.set(i, str[i] += x);
        st.set(i + 1, str[i + 1] -= x);
    }

    for (int i = 0; i < q; i++){
        int c; cin >> c;
        if (c == 1){
            ll a, b, u;
            cin >> a >> b >> u;
            --a; --b;
            st.set(a, str[a] += u);
            st.set(b + 1, str[b + 1] -= u);
            continue;
        }

        int k; cin >> k;
        --k;
        cout << st.query(0, k + 1) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}