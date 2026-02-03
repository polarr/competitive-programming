/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-29
 * Contest: CSES Problemset
 * Problem: 1673
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
 * ALGORITHM: Bellman-Ford
 * PURPOSE: Finds SSSP with negative weights.
 * CONSTRAINT: V^2 max w < 2^63
 * TIME: O(VE)
 * SOURCE: KACTL
*/
const ll inf = LLONG_MAX;
struct Ed { int a, b, w; int s() { return a < b ? a : -a; } };
struct Node { ll dist = inf; int prev = -1; };

void bellmanFord(vector<Node>& nodes, vector<Ed>& eds, int s) {
	nodes[s].dist = 0;
	sort(all(eds), [](Ed a, Ed b) { return a.s() < b.s(); });

	int lim = sz(nodes) / 2 + 2; // /3+100 with shuffled vertices
	rep(i,0,lim) for (Ed ed : eds) {
		Node cur = nodes[ed.a], &dest = nodes[ed.b];
		if (abs(cur.dist) == inf) continue;
		ll d = cur.dist + ed.w;
		if (d < dest.dist) {
			dest.prev = ed.a;
			dest.dist = (i < lim-1 ? d : -inf);
		}
	}
	rep(i,0,lim) for (Ed e : eds) {
		if (nodes[e.a].dist == -inf)
			nodes[e.b].dist = -inf;
	}
}

void solve(){
    int n, m; cin >> n >> m;
    vector<Node> dist(n);
    vector<Ed> edges(m);

    rep(i, 0, m) {
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        edges[i] = {a, b, -w};
    }

    bellmanFord(dist, edges, 0);

    ll ans = dist[n - 1].dist;
    if (ans == -inf) {
        cout << -1 << endl;
    } else {
        cout << -ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}