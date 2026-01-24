/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-23
 * Contest: 
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

vector<pii> hierholzerEdge(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges); vector<pii> ret, s = {{src, -1}};
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
    int n; cin >> n;

    vector<pii> necklaces(n);
    rep(i, 0, n) {
        int a, b; cin >> a >> b;
        necklaces[i] = {a, b};
    }

    for (int k = 20; k >= 0; k--) {
        int pw = (1 << k);
        vector<vector<pii>> adj(pw);
        rep(i, 0, n) {
            auto [a, b] = necklaces[i];
            a %= pw;
            b %= pw;

            adj[a].pb({b, i});
            adj[b].pb({a, i});
        }

        vector<pii> walk = hierholzerEdge(adj, n, necklaces[0].first % pw);

        if (walk.empty()) continue;

        cout << k << endl;
        rep(i, 1, sz(walk)) {
            int j = walk[i].second;
            int b = walk[i].first;
            if (necklaces[j].first % pw == b) {
                cout << 2 * j + 2 << " " << 2 * j + 1 << " ";
                continue;
            }
            cout << 2 * j + 1 << " " << 2 * j + 2 << " ";
        }
        cout << endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}