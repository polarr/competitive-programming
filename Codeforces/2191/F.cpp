/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-21
 * Contest: 
 * Problem: F
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
 * ALGORITHM: Modular Exponentiation 
 * PURPOSE: Computes x^n (mod m)
 * CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 * TIME: O(log n)
*/
ll mod_exp(ll x, ll n, ll m) {
	x %= m;

	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}

	return res;
}

ll numTree(vi &s) {
    if (sz(s) == 1) {
        return 1;
    }

    ll n = 0;
    for (int si : s) {
        n += si;
    }

    ll ans = mod_exp(n, sz(s) - 2, MOD);
    for (int si : s) {
        ans *= si;
        ans %= MOD;
    }
    
    return ans;
};

void solve(){
    int n, m; cin >> n >> m;

    vector<vi> adj(n);
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int root = n - 1;
    int second = n - 2;

    vl ans(n - 1, -1);

    vector<bool> visited(n, false);
    vl subSize(n, -1);
    vi hasSecond(n, 0);
    vi inRoot;
    function<void(int, int)> dfsRoot;
    dfsRoot = [&](int node, int par) {
        inRoot.pb(node);
        subSize[node] = 1;
        hasSecond[node] = (node == second);
        visited[node] = true;
        for (int x : adj[node]) {
            if (x == par) continue;
            dfsRoot(x, node);
            hasSecond[node] |= hasSecond[x];
            subSize[node] += subSize[x];
        }
    };

    dfsRoot(root, -1);

    function<int(int, int)> dfs;
    dfs = [&](int node, int par) {
        int a = 1;
        visited[node] = true;
        for (int x : adj[node]) {
            if (x == par) continue;
            a += dfs(x, node);
        }

        return a;
    };

    vi sizes;
    rep(i, 0, root) {
        if (visited[i]) continue;
        int cnt = dfs(i, -1);
        sizes.pb(cnt);
    }

    vector<bool> isAdj(n, false);
    for (int x : adj[root]) {
        isAdj[x] = true;
    }

    if (hasSecond[root]) {
        vi s = sizes;
        s.pb(subSize[root]);
        
        ll allAns = numTree(s);

        rep(i, 0, root) {
            if (!hasSecond[i] || !isAdj[i]) {
                ans[i] = 0;
                continue;
            }

            ans[i] = allAns;
        }

        for (ll a : ans) {
            cout << a << " ";
        }

        cout << '\n';
        return;
    }

    vi s = sizes;
    s.pb(subSize[root]);
    
    ll allAns = numTree(s);

    for (int i : inRoot){
        if (i == root) continue;
        if (!visited[i]) continue;
        if (!isAdj[i]) {
            ans[i] = 0;
            continue;
        }

        ll a = allAns;
        a *= mod_exp(subSize[root], MOD - 2, MOD);
        a %= MOD;
        a *= subSize[i];
        a %= MOD;
        ans[i] = a;
    }

    vi inSecond;
    function<int(int, int)> dfsSecond;
    dfsSecond = [&](int node, int par) {
        int a = 1;
        inSecond.pb(node);
        for (int x : adj[node]) {
            if (x == par) continue;
            a += dfsSecond(x, node);
        }

        return a;
    };

    int secondSize = dfsSecond(second, -1);
    ll secondAns = allAns;
    secondAns *= mod_exp(n, MOD - 2, MOD);
    secondAns %= MOD;
    secondAns *= mod_exp(subSize[root], MOD - 2, MOD);
    secondAns %= MOD;
    secondAns *= mod_exp(secondSize, MOD - 2, MOD);
    secondAns %= MOD;
    secondAns *= subSize[root] + secondSize;
    secondAns %= MOD;
    for (int x : inSecond) {
        ans[x] = secondAns;
    }

    function<int(int, int, vi&)> dfsAns;
    dfsAns = [&](int node, int par, vi& stuff) {
        int a = 1;
        stuff.pb(node);
        for (int x : adj[node]) {
            if (x == par) continue;
            a += dfsAns(x, node, stuff);
        }

        return a;
    };
    rep(i, 0, second) {
        if (ans[i] != -1) continue;
        vi stuff;
        int genSize = dfsAns(i, -1, stuff);
        ll genAns = allAns;
        genAns *= mod_exp(n, MOD - 2, MOD);
        genAns %= MOD;
        genAns *= mod_exp(subSize[root], MOD - 2, MOD);
        genAns %= MOD;
        for (int x : stuff) {
            ans[x] = genAns;
        }
    }

    for (ll a : ans) {
        cout << a << " ";
    }

    cout << '\n';
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