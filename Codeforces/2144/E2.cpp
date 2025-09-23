/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-22
 * Contest: Codeforces 2144
 * Problem: E2
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
const ll MOD = 998244353;

/** 
 * DATASTRUCTURE: Lazy Segment Tree
 * PURPOSE: Segment Tree with lazy updates
 * TIME: O(log n) to update and query
*/
template <class Info, class Tag> class LazySegtree {
  private:
	const int n;
	vector<Info> tree;
	vector<Tag> lazy;

	/** builds the segtree values in O(N) time */
	void build(int v, int l, int r, const vector<Info> &a) {
		if (l == r) {
			tree[v] = a[l];
		} else {
			int m = (l + r) / 2;
			build(2 * v, l, m, a);
			build(2 * v + 1, m + 1, r, a);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}

	/** applies update x to lazy[v] and tree[v] */
	void apply(int v, int l, int r, const Tag &x) {
		tree[v].apply(x, l, r);
		lazy[v].apply(x);
	}

	/** pushes lazy updates down to the children of v */
	void push_down(int v, int l, int r) {
		int m = (l + r) / 2;
		apply(2 * v, l, m, lazy[v]);
		apply(2 * v + 1, m + 1, r, lazy[v]);
		lazy[v] = Tag();
	}

	void range_update(int v, int l, int r, int ql, int qr, const Tag &x) {
		if (qr < l || ql > r) { return; }
		if (ql <= l && r <= qr) {
			apply(v, l, r, x);
		} else {
			push_down(v, l, r);
			int m = (l + r) / 2;
			range_update(2 * v, l, m, ql, qr, x);
			range_update(2 * v + 1, m + 1, r, ql, qr, x);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}

	Info range_query(int v, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) { return Info(); }
		if (l >= ql && r <= qr) { return tree[v]; }
		push_down(v, l, r);
		int m = (l + r) / 2;
		return range_query(2 * v, l, m, ql, qr) +
		       range_query(2 * v + 1, m + 1, r, ql, qr);
	}

  public:
	LazySegtree() {}

	LazySegtree(int n) : n(n) {
		tree.assign(4 << __lg(n), Info());
		lazy.assign(4 << __lg(n), Tag());
	}

	LazySegtree(const vector<Info> &a) : n(a.size()) {
		tree.assign(4 << __lg(n), Info());
		lazy.assign(4 << __lg(n), Tag());
		build(1, 0, n - 1, a);
	}

	/** updates [ql, qr] with the arbitrary update chosen */
	void range_update(int ql, int qr, const Tag &x) {
		range_update(1, 0, n - 1, ql, qr, x);
	}

	/** @return result of range query on [ql, qr] */
	Info range_query(int ql, int qr) { return range_query(1, 0, n - 1, ql, qr); }
};

struct Tag {
    ll mult = 1;
	ll add = 0;
	void apply(const Tag &t) {
		mult *= t.mult;
        mult %= MOD;
        add *= t.mult;
        add %= MOD;
        add += t.add;
        add %= MOD;
	}
};

struct Info {
	ll sum = 0;
	void apply(const Tag &t, int l, int r) {
		sum *= t.mult;
        sum %= MOD;
        sum += t.add * (ll)(r + MOD - l + 1) % MOD;
        sum %= MOD;
	}
};

/** @return result of joining nodes a and b together */
Info operator+(const Info &a, const Info &b) { 
    return { (a.sum + b.sum) % MOD};
}

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi lseq, rseq;
    int mx = 0;
    rep(i, 0, n){
        if (a[i] > mx){
            mx = a[i];
            lseq.pb(a[i]);
        }
    }

    mx = 0;
    for (int i = n - 1; i >= 0; i--){
        if (a[i] > mx){
            mx = a[i];
            rseq.pb(a[i]);
        }
    }

    rseq.pop_back();

    int ml = lseq.size(), mr = rseq.size();

    ll dpl[n + 1], dpr[n + 1];
    
    LazySegtree<Info, Tag> stl(ml + 1), str(mr + 1);
    stl.range_update(0, 0, Tag{0, 1});
    str.range_update(0, 0, Tag{0, 1});

    dpl[0] = stl.range_query(ml, ml).sum;
    dpr[0] = str.range_query(mr, mr).sum;

    rep(i, 1, n + 1){
        auto idx = lower_bound(all(lseq), a[i - 1]);
        if (prev(idx) == lseq.end()) continue;

        ll add = 0;
        int j = idx - lseq.begin();

        if (a[i - 1] == *idx){
            add = stl.range_query(j, j).sum;
        }

        j++;
        stl.range_update(j, ml, Tag{2, 0});
        stl.range_update(j, j, Tag{1, add});

        dpl[i] = stl.range_query(ml, ml).sum;
        
        // rep(j, 1, ml + 1){
        //     dpl[i][j] = dpl[i - 1][j];
        //     if (a[i - 1] == lseq[j - 1]){
        //         dpl[i][j] += dpl[i - 1][j - 1];
        //         dpl[i][j] %= MOD;
        //     }
        //     if (a[i - 1] <= lseq[j - 1]){
        //         dpl[i][j] += dpl[i - 1][j];
        //         dpl[i][j] %= MOD;
        //     }
        // }
    }

    reverse(all(a));

    rep(i, 1, n + 1){
        auto idx = lower_bound(all(rseq), a[i - 1]);
        if (prev(idx) == rseq.end()) continue;

        ll add = 0;
        int j = idx - rseq.begin();

        if (a[i - 1] == *idx){
            add = str.range_query(j, j).sum;
        }

        j++;
        str.range_update(j, mr, Tag{2, 0});
        str.range_update(j, j, Tag{1, add});

        dpr[i] = str.range_query(mr, mr).sum;

        // rep(j, 1, mr + 1){
        //     dpr[i][j] = dpr[i - 1][j];
        //     if (a[i - 1] == rseq[j - 1]){
        //         dpr[i][j] += dpr[i - 1][j - 1];
        //         dpr[i][j] %= MOD;
        //     }

        //     if (a[i - 1] <= rseq[j - 1]){
        //         dpr[i][j] += dpr[i - 1][j];
        //         dpr[i][j] %= MOD;
        //     }
        // }
    }

    reverse(all(a));

    ll ans = 0;
    rep(i, 0, n){
        if (a[i] != lseq[ml - 1]) continue;
        ans += (dpl[i + 1] + MOD - dpl[i]) % MOD * dpr[n - 1 - i] % MOD;
        ans %= MOD;
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