/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-12
 * Contest: CSES Problemset
 * Problem: 1692
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
 * ALGORITHM: Hierholzer's Algorithm
 * PURPOSE: Finds eulerian path/cycle, returns empty if not found. Modify s/ret to include .second for edge indices.
 * TIME: O(V + E)
 * SOURCE: KACTL
*/
vector<pii> hierholzer(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges); vector<pii> ret, s = {{src, -1}};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		auto [x, pe] = s.back(); int y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back({x, pe}); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back({y, e});
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

void solve(){
    int p; cin >> p;

    int n = (1 << p);
    int k = (1 << (p - 1));
    vector<vector<pii>> adj(k);
    rep(i, 0, k) {
        int a = 2 * i, b = 2 * i + 1;
        int x = a % k, y = b % k;

        adj[i].pb({x, a});
        adj[i].pb({y, b});
    }

    vector<pii> walk = hierholzer(adj, n);
    string ans;
    int x = walk[1].second;
    for (int i = p - 1; i >= 0; i--) {
        if (x & (1 << i)) {
            ans += "1";
        } else {
            ans += "0";
        }
    }

    reverse(all(ans));

    rep(i, 2, sz(walk)) {
        int a = walk[i].second % 2;
        ans += ('0' + a);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}