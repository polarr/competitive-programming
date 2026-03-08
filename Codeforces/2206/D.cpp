/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-07
 * Contest: 
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

struct Node {
	Node *l = 0, *r = 0;
    ll inf = 0;
	ll lo, hi, mset = inf, madd = 0, val = -inf;
    ll combine(ll a, ll b) {
        return a + b;
    }
	Node(ll lo,ll hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, ll lo, ll hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = combine(l->val, r->val);
		}
		else val = v[lo];
	}
    // NOTE: [L, R)
	ll query(ll L, ll R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return combine(l->query(L, R), r->query(L, R));
	}
	void set(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = combine(l->val, r->val);
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
			val = combine(l->val, r->val);
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

template <bool VALS_EDGES> struct HLD {
    int N, tim = 0;
    vector<vi> adj;
    vi par, siz, depth, rt, pos;
    Node *tree;
    HLD (vector<vi> adj_) : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N), rt(N), pos(N), tree(new Node(0, N)) { dfsSz(0); dfsHld(0); }
    void dfsSz(int v) {
        if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
        for (int& u : adj[v]) {
            par[u] = v, depth[u] = depth[v] + 1;
            dfsSz(u);
            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
        }
    }

    void dfsHld(int v) {
        pos[v] = tim++;
        for (int u : adj[v]) {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
    }
    template <class B> void process(int u, int v, B op) {
        for (; rt[u] != rt[v]; v = par[rt[v]]) {
            if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
            op(pos[rt[v]], pos[v] + 1);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(pos[u] + VALS_EDGES, pos[v] + 1);
    }

    void modifyPath(int u, int v, int val) {
        process(u, v, [&](int l, int r) { tree->add(l, r, val); });
    }
    
    int queryPath(int u, int v) {
        int res = -1e9;
        process(u, v, [&](int l, int r) {
            res = max(res, tree->query(l, r));
        });
        return res;
    }
    
    int querySubtree(int v) {
        return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<vi> children(n);
    rep(i, 1, n) {
        int p; cin >> p;
        --p;
        children[p].pb(i);
    }

    vl vals(n);
    rep(i, 0, n) {
        cin >> vals[i];
    }

    function<ll(int)> dfs;
    dfs = [&](int node) {
        for (int x : children[node]) {
            
        }
    };

    dfs(0);
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