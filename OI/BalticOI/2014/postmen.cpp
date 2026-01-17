/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-16
 * Contest: Baltic OI 2014
 * Problem: postmen
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
vi hierholzer(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	// D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<pii>> adj(n);
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb({b, i});
        adj[b].pb({a, i});
    }

    vi tour = hierholzer(adj, m, 0);
    vector<vi> cycles;
    stack<array<int, 3>> want;

    vector<vi> idx(n);
    for (int i = sz(tour) - 1; i >= 0; i--) {
        idx[tour[i]].pb(i);
    }

    int j = 0;
    rep(i, 0, sz(tour)) {
        int x = tour[i];
        if (!want.empty() && x == want.top()[0]) {
            want.pop();
        }

        idx[x].pop_back();
        if (!idx[x].empty() && (want.empty() || idx[x].back() < want.top()[2])) {
            cycles.pb({x});
            want.push({x, j++, idx[x].back()});
            continue;
        }

        if (!want.empty()) cycles[want.top()[1]].pb(x);
    }

    cout << endl;

    rep(i, 0, sz(cycles)) {
        // cout << sz(cycles[i]) << "\n";
        rep(j, 0, sz(cycles[i])) {
            cout << cycles[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}