/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-17
 * Contest: CSES Problemset
 * Problem: 2078
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

void solve(){
    int n, m; cin >> n >> m;

    vector<vi> adj(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll cycles = 0;

    vector<bool> visited(n, false), done = visited;

    function<void(int, int)> dfs;
    dfs = [&](int node, int par){
        visited[node] = true;
        for (int x : adj[node]){
            if (x == par || done[x]) continue;
            if (visited[x]){
                cycles++;
                continue;
            }
            dfs(x, node);
        }
        done[node] = true;
    };

    rep(i, 0, n){
        if (done[i]) continue;
        dfs(i, -1);
    }

    cout << mod_exp(2, cycles, MOD) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}