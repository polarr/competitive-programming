/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-22
 * Contest: Codeforces 2090
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
const ll MOD = 1e9 + 7;

/** 
 * DATASTRUCTURE: Segment Tree
 * PURPOSE: Range Updates and Queries
 * TIME: O(log n) to update and query
*/
template <class T> class SegmentTree {
  private:
	const T UNIT = pair<ll, ll>{LLONG_MAX, LLONG_MAX};

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

struct Node {
	Node *l = 0, *r = 0;
    ll inf = 0;
	ll lo, hi, mset = inf, madd = 0, val = -inf;
	Node(ll lo,ll hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, ll lo, ll hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
    // NOTE: [L, R)
	ll query(ll L, ll R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

void solve(){
    int n; ll k; cin >> n >> k;

    vl a(n), b(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    rep(i, 0, n){
        cin >> b[i];
    }

    SegmentTree<pair<ll, ll>> st(2 * n + 1);

    vl d(2 * n + 1, 0);
    ll sum = 0;
    rep(i, 0, 2 * n){
        sum += a[i % n] - b[i % n];
        d[i + 1] = sum;
    }

    rep(i, 0, 2 * n + 1){
        st.set(i, {d[i], -i});
    }

    auto check = [&](int r){
        ll need = 0;

        vector<array<ll, 3>> reqs;

        rep(i, 0, n){
            ll sub = d[i];

            pii target = st.query(i + 1, i + r);

            if (target.first <= sub){
                continue;
            }

            reqs.pb(target.first - sub, i + 1, -target.second);
        }

        Node mst(0, 2 * n + 2);

        sort(all(reqs));
        rep(i, 0, reqs.size()){
            array<ll, 3> req = reqs[i];
            mst.add(req[1], req[2] + 1, 1);
        }

        rep(i, 0, reqs.size()){
            array<ll, 3> req = reqs[i];
            mst.add(req[1], req[2] + 1, 1);
        }

        return need <= k;
    }

    

    int lo = 1;
    int hi = n;

    while(lo < hi){
        int mid = (lo + hi)/2;

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