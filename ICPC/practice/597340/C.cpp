/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-10
 * Contest: ICPC Practice Codeforces 597340
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
 * DATASTRUCTURE: Sparse Segment Tree
 * PURPOSE: Lazy Segment Tree on large intervals
 * TIME: O(log n)
 * MEMORY: O(q log n)
 * SOURCE: KACTL
 */
// static char buf[450 << 20];
// void* operator new(size_t s) {
// 	static size_t i = sizeof buf;
// 	assert(s < i);
// 	return (void*)&buf[i -= s];
// }
// void operator delete(void*) {}
// template<class T> struct ptr {
// 	unsigned ind;
// 	ptr(T* p = 0) : ind(p ? unsigned((char*)p - buf) : 0) {
// 		assert(ind < sizeof buf);
// 	}
// 	T& operator*() const { return *(T*)(buf + ind); }
// 	T* operator->() const { return &**this; }
// 	T& operator[](int a) const { return (&**this)[a]; }
// 	explicit operator bool() const { return ind; }
// };
struct MaxNode {
	MaxNode *l = 0, *r = 0;
    ll inf = 0;
	ll lo, hi, mset = inf, madd = 0, val = -inf;
	MaxNode(ll lo,ll hi):lo(lo),hi(hi){} // Large interval of -inf
	MaxNode(vi& v, ll lo, ll hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			ll mid = lo + (hi - lo)/2;
			l = new MaxNode(v, lo, mid); r = new MaxNode(v, mid, hi);
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
			l = new MaxNode(lo, mid); r = new MaxNode(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

/**
 * DATASTRUCTURE: Sparse Segment Tree
 * PURPOSE: Lazy Segment Tree on large intervals
 * TIME: O(log n)
 * MEMORY: O(q log n)
 * SOURCE: KACTL
 */
// static char buf[450 << 20];
// void* operator new(size_t s) {
// 	static size_t i = sizeof buf;
// 	assert(s < i);
// 	return (void*)&buf[i -= s];
// }
// void operator delete(void*) {}
// template<class T> struct ptr {
// 	unsigned ind;
// 	ptr(T* p = 0) : ind(p ? unsigned((char*)p - buf) : 0) {
// 		assert(ind < sizeof buf);
// 	}
// 	T& operator*() const { return *(T*)(buf + ind); }
// 	T* operator->() const { return &**this; }
// 	T& operator[](int a) const { return (&**this)[a]; }
// 	explicit operator bool() const { return ind; }
// };
struct MinNode {
	MinNode *l = 0, *r = 0;
    ll inf = LLONG_MAX;
	ll lo, hi, mset = inf, madd = 0, val = inf;
	MinNode(ll lo,ll hi):lo(lo),hi(hi){} // Large interval of -inf
	MinNode(vi& v, ll lo, ll hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			ll mid = lo + (hi - lo)/2;
			l = new MinNode(v, lo, mid); r = new MinNode(v, mid, hi);
			val = min(l->val, r->val);
		}
		else val = v[lo];
	}
    // NOTE: [L, R)
	ll query(ll L, ll R) {
		if (R <= lo || hi <= L) return inf;
		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	void set(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = min(l->val, r->val);
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
			val = min(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			ll mid = lo + (hi - lo)/2;
			l = new MinNode(lo, mid); r = new MinNode(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

void solve(){
    int n; cin >> n;

    MaxNode mx(0, 1e18 + 1e10);
    MinNode mn(0, 1e18 + 1e10);

    mx.set(0, 1e18 + 1e10, 0);
    mn.set(0, 1e18 + 1e10, 0);

    // mle who knows but should work

    rep(i, 0, n){
        char c; ll l, p;
        cin >> c >> l >> p;

        if (c == '|'){
            cout << 'S';
            mx.add(p, p + 1, l);
            mn.add(p, p + 1, l);
            continue;
        }

        bool safe = mx.query(p, p + l) == mn.query(p, p + l);
        if (safe){
            cout << 'S';
            mx.add(p, p + l, 1);
            mn.add(p, p + l, 1);
        } else {
            cout << 'U';
        }
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}