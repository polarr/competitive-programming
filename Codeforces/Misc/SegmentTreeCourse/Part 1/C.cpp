/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-22
 * Contest: Codeforces SegmentTreeCourse
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

template <class T> class SegmentTree {
  private:
	const T UNIT = {INT_MAX, 0};

    T update(T a, T b){
        if (a.first == b.first){
            return {a.first, a.second + b.second};
        }

        if (a.first < b.first){
            return a;
        }

        return b;
    }

    T extract(T a, T b){
        if (a.first == b.first){
            return {a.first, a.second + b.second};
        }

        if (a.first < b.first){
            return a;
        }

        return b;
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
    int n, m; cin >> n >> m;

    SegmentTree<pair<int, int>> st(n);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        st.set(i, {a, 1});
    }

    for (int i = 0; i < m; i++){
        int c, x, y; cin >> c >> x >> y;
        if (c == 1){
            st.set(x, {y, 1});
            continue;
        }

        pair<int, int> q = st.query(x, y);

        cout << q.first << " " << q.second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}