/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-16
 * Contest: Codeforces 508
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
const int B = 26 * 2 + 10;

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
    map<char, int> mp;
    rep(i, 0, 26) {
        mp['a' + i] = i;
        mp['A' + i] = 26 + i;
    }

    rep(i, 0, 10) {
        mp['0' + i] = 52 + i;
    }

    int n = B * B;
    int m; cin >> m;

    vector<vector<pii>> adj(n);
    vi deg(n, 0);
    vector<string> edges(m);
    int src = 0;
    rep(i, 0, m) {
        string s; cin >> s;
        char a = s[0], b = s[1], c = s[2];
        int x = mp[a], y = mp[b], z = mp[c];

        edges[i] = s;
        int from = x * B + y;
        int to = y * B + z;

        src = from;

        adj[from].pb({to, i});
        deg[from]++;
        deg[to]--;
    }

    rep(i, 0, n) {
        if (deg[i] == 1) {
            src = i;
            break;
        }
    }

    vector<pii> walk = hierholzer(adj, m, src);
    if (walk.empty()) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    
    int e = walk[1].second;
    string ans = edges[e];

    rep(i, 2, sz(walk)) {
        int e = walk[i].second;
        ans += edges[e].back();
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}