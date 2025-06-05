/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-04
 * Contest: DMOJ bts17
 * Problem: 7
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

template <typename T>
pair<T, T> operator+(const pair<T, T>& a, const pair<T, T>& b) {
    return {a.first + b.first, a.second + b.second};
}
template <typename T>
pair<T, T> operator-(const pair<T, T>& a, const pair<T, T>& b) {
    return {a.first - b.first, a.second - b.second};
}
template <typename T>
pair<T, T>& operator+=(pair<T, T>& a, const pair<T, T>& b) {
    a.first += b.first;
    a.second += b.second;
    return a;
}
template <typename T>
pair<T, T>& operator-=(pair<T, T>& a, const pair<T, T>& b) {
    a.first -= b.first;
    a.second -= b.second;
    return a;
}

/** 
 * DATASTRUCTURE: Fenwick Tree
 * PURPOSE: Point update and prefix sums
 * TIME: O(log n) to update and query
*/
template <class T> class FT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	FT(int size) : size(size), bit(size + 1), arr(size) {}

	/** Sets the value at index ind to val. */
	void set(int ind, T val) { add(ind, val - arr[ind]); }

	/** Adds val to the element at index ind. */
	void add(int ind, T val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	/** @return The sum of all values in [0, ind]. */
	T pref_sum(int ind) {
		ind++;
		T total = T();
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};

/** 
 * ALGORITHM: Euler Tour
 * PURPOSE: Flattens a tree so that each range contains any subtree range
 * CONSTRAINT: Graph must be a tree
 * TIME: O(V)
*/
vector<pii> eulerTour(int n, vector<vector<int>> &adj){
    vector<pii> ans(n);
    int i = -1;
    function<void(int, int)> tour;
    tour = [&](int node, int parent){
        ans[node].first = ++i;
        for (int x : adj[node]){
            if (x != parent){
                tour(x, node);
            }
        }
        ans[node].second = ++i;
    };

    // root at 0
    tour(0, 0);

    return ans;
}

void solve(){
    int n, s; cin >> n >> s;

    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int x, y; cin >> x >> y;
        --x; --y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int lg = log2(n) + 1;
    vector<vi> jump(n, vi(lg, -1));
    vl d(n, 0);

    function<void(int, int)> dfs;
    dfs = [&](int x, int par){
        for (int node : adj[x]){
            if (node == par) continue;
            jump[node][0] = x;
            d[node] = d[x] + 1;
            dfs(node, x);
        }
    };

    dfs(0, -1);

    vi pow2(lg, 1);
    rep(j, 1, lg){
        pow2[j] = pow2[j - 1] * 2;
    }

    rep(j, 1, lg){
        rep(i, 0, n){
            int k = jump[i][j - 1];
            if (k == -1) continue;
            jump[i][j] = jump[k][j - 1];
        }
    }

    auto lca = [&](int a, int b){
        if (d[a] > d[b]) swap(a, b);
        
        int diff = d[b] - d[a];
        rep(i, 0, lg){
            if (diff & pow2[i]){
                b = jump[b][i];
            }
        }

        if (b == a){
            return a;
        }

        for (int i = lg - 1; i >= 0; i--){
            if (jump[a][i] == jump[b][i]) continue;

            a = jump[a][i];
            b = jump[b][i];
        }

        return jump[a][0];
    };

    auto dist = [&](int a, int b){
        return d[a] + d[b] - 2 * d[lca(a, b)];
    };

    FT<pair<ll, ll>> ft(2 * n + 1);
    vector<pii> tour = eulerTour(n, adj);

    auto update2 = [&](int crit, int x, ll val){
        ll move = 1;
        if (d[crit] > d[x]){
            val += (ll) (d[crit] - d[x]);
            move = -1;
            swap(x, crit);
        }

        ft.add(tour[crit].first, {move, val - move * d[crit]});
        ft.add(tour[x].first + 1, {-move, -val + move * d[crit]});
    };

    auto update = [&](int crit, int x, ll val){
        int l = lca(crit, x);

        update2(crit, l, val);
        val += d[crit] - d[l];
        update2(l, x, val);
        update2(l, l, -val);
    };

    rep(i, 0, s){
        int a, b, t; cin >> a >> b >> t;
        --a; --b; --t;

        if (d[a] > d[b]) swap(a, b);

        int ab = dist(a, b);
        int l = lca(a, b);
        int at = dist(a, t);
        int bt = dist(b, t);

        int up = (bt - at + ab)/2;
        int val = bt - up;

        int crit = b;
        if (up > d[b] - d[l]){
            crit = a; 
            up = ab - up;
        }
        rep(j, 0, lg) {
            if (up & pow2[j]){
                crit = jump[crit][j];
            }
        }

        update(crit, a, val);
        update(crit, b, val);
        update(crit, crit, -val);
    }

    rep(i, 0, n){
        pair<ll, ll> x = ft.pref_sum(tour[i].first) - ft.pref_sum(tour[i].second);

        cout << x.first * d[i] + x.second << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}