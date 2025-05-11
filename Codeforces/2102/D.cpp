/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-11
 * Contest: Codeforces 2102
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
    int n; cin >> n;
    vi a, b;
    rep(i, 0, n){
        int x; cin >> x;
        if (i % 2 == 0){
            a.pb(x);
        } else {
            b.pb(x);
        }
    }

    ll inva = 0;
    ll invb = 0;

    SegmentTree<ll> sta(n + 1), stb(n + 1);

    rep(i, 0, a.size()){
        inva += sta.query(a[i] + 1, n + 1);
        sta.set(a[i], 1);
    }

    rep(i, 0, b.size()){
        invb += stb.query(b[i] + 1, n + 1);
        stb.set(b[i], 1);
    }

    sort(all(a));
    sort(all(b));

    if ((inva % 2) != (invb % 2)){
        if (n % 2 == 1){
            swap(a[a.size() - 1], a[a.size() - 2]);
        } else {
            swap(b[b.size() - 1], b[b.size() - 2]);
        }
    }

    rep(i, 0, n){
        if (i % 2 == 0){
            cout << a[i/2] << " ";
        } else {
            cout << b[i/2] << " ";
        }
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