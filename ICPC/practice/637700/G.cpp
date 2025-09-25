/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-24
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
 * DATASTRUCTURE: Lazy Segment Tree
 * PURPOSE: Segment Tree with lazy updates
 * TIME: O(log n) to update and query
*/
class LazySegtree {
  private:
	const int n;
	vector<ll> tree;
    vector<ll> mx;

    // MOD
	void range_update(int v, int l, int r, int ql, int qr, ll x) {
		if (qr < l || ql > r || mx[v] < x) { return; }
		if (l == r) {
            mx[v] %= x;
            tree[v] = mx[v];
		} else {
			int m = (l + r) / 2;
			range_update(2 * v, l, m, ql, qr, x);
			range_update(2 * v + 1, m + 1, r, ql, qr, x);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
			mx[v] = max(mx[2 * v], mx[2 * v + 1]);
		}
	}

    // SET
    void range_set(int v, int q, int l, int r, ll x) {
        if (l == r){
            tree[v] = x;
            mx[v] = x;
            return;
        }

		int m = (l + r) / 2;
        if (q <= m) {
            range_set(2 * v, q, l, m, x);
        }
        else {
            range_set(2 * v + 1, q, m + 1, r, x);
        }

        tree[v] = tree[2 * v] + tree[2 * v + 1];
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
	}

	ll range_query(int v, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) { return 0; }
		if (l >= ql && r <= qr) { return tree[v]; }
		int m = (l + r) / 2;
		return range_query(2 * v, l, m, ql, qr) +
		       range_query(2 * v + 1, m + 1, r, ql, qr);
	}

  public:
	LazySegtree(int n) : n(n) {
		tree.assign(4 << __lg(n), 0);
        mx.assign(4 << __lg(n), 0);
	}

	/** updates [ql, qr] with the arbitrary update chosen */
	void range_update(int ql, int qr, ll x) {
		range_update(1, 0, n - 1, ql, qr, x);
	}

    /** updates [ql, qr] with the arbitrary update chosen */
	void range_set(int i, ll x) {
		range_set(1, i, 0, n - 1, x);
	}

	/** @return result of range query on [ql, qr] */
	ll range_query(int ql, int qr) { return range_query(1, 0, n - 1, ql, qr); }
};

void solve(){
    int n, m; cin >> n >> m;
    vl arr(n);
    LazySegtree st(n);
    rep(i, 0, n){
        ll a; cin >> a;
        st.range_set(i, a);
    }
    
    rep(i, 0, m){
        int c; cin >> c;
        if (c == 1){
            int a, b; cin >> a >> b;
            --a; --b;
            cout << st.range_query(a, b) << endl;
        } else if (c == 2){
            int a, b; cin >> a >> b;
            ll md; cin >> md;
            --a; --b;
            st.range_update(a, b, md);
        } else {
            int j; ll a; cin >> j >> a;
            --j;
            st.range_set(j, a);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}