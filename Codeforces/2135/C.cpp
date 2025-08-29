/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-28
 * Contest: Codeforces 2135
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
const ll MOD = 998244353;

// Bruh oops I should be using 2CC instead of BCC...

/** 
 * ALGORITHM: Biconnected Components
 * TIME: O(V + E)
 * SOURCE: KACTL
*/
vi num, st;
vector<vector<pii>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
	int me = num[at] = ++Time, top = me;
	for (auto [y, e] : ed[at]) if (e != par) {
		if (num[y]) {
			top = min(top, num[y]);
			if (num[y] < me)
				st.push_back(e);
		} else {
			int si = sz(st);
			int up = dfs(y, e, f);
			top = min(top, up);
			if (up == me) {
				st.push_back(e);
				f(vi(st.begin() + si, st.end()));
				st.resize(si);
			}
			else if (up < me) st.push_back(e);
			else { /* e is a bridge */ }
		}
	}
	return top;
}

template<class F>
void bicomps(F f) {
	num.assign(sz(ed), 0);
	rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}

void solve(){
    ll n, m, v; cin >> n >> m >> v;
    v %= MOD;
    vl w(n);
    vi c(n, 0);
    rep(i, 0, n) cin >> w[i];

    num = {}, st = {};
    Time = 0;
    ed = vector<vector<pii>>(n);

    vector<pii> edges(m);
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        --a; --b;
        edges[i] = {a, b};
        ed[a].pb({b, i});
        ed[b].pb({a, i});
    }

    ll ans = 1;
    vi color(n, -1);

    function<void(const vi&)> handle;
    handle = [&](const vi& edgelist){
        assert(!edgelist.empty());
        map<int, bool> has;
        for (int e : edgelist){
            has[e] = true;
        }

        bool bipartite = true;

        function<void(int, int, int)> dfs;
        dfs = [&](int node, int par, int col){
            color[node] = col;

            for (auto &[x, id] : ed[node]){
                if (!has[id] || x == par) continue;
                if (color[x] != -1){
                    if (color[x] == color[node]) bipartite = false;
                    continue;
                }
                dfs(x, node, 1 - col);
            }
        };

        dfs(edges[edgelist[0]].first, -1, 0);

        ll req = bipartite ? -1 : 0;

        for (int e : edgelist){
            int a = edges[e].first, b = edges[e].second;
            c[a] = 1;
            c[b] = 1;

            if (w[a] != -1){
                if (req != -1 && req != w[a]) ans = 0;
                req = w[a];
            }

            if (w[b] != -1){
                if (req != -1 && req != w[b]) ans = 0;
                req = w[b];
            }
        }

        if (req == -1) {
            ans *= v;
            ans %= MOD;
        }
    };

    bicomps(handle);

    rep(i, 0, n){
        if (c[i] == 0 && w[i] == -1){
            ans *= v;
            ans %= MOD;
        }
    }

    cout << ans << endl;
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