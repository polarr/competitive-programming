/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-03
 * Contest: 
 * Problem: F2
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

const int MAX_N = 5e6 + 1;
const ll MOD = 1e9 + 7;

/**
 * PRECOMPUTE: Prime Linear Sieve
 * PURPOSE: Classifies numbers up to MAX_N as primes or not
 * TIME: O(n)
 */
vector<ll> prime;
vector<bool> is_composite(MAX_N + 1, false);
vector<ll> min_div(MAX_N + 1, 1);
void prime_sieve (ll n) {
	for (ll i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.pb(i);
            min_div[i] = i;
		}
		for (ll j = 0; j < prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
            min_div[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
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

const int MX = 100;
vl cand(MX);

void solve(){
    int n; cin >> n;

    int k;

    rep(kk, 1, n) {
        int can = (kk * (kk + 1))/2;

        if (can >= n - 1) {
            k = kk;
            break;
        }
    }

    if (k % 2 == 0) {
        // even k no eulerian path
        int can = k + (k - 1) + ((k - 2) * (k - 2))/2;
        if (can < n - 1) {
            k++;
        }
    }

    // cout << k << endl;

    vector<pii> edges;
    vector<vector<pii>> adj(k);
    rep(i, 0, k) {
        rep(j, 0, k) {
            if (j > i) break;
            if (k % 2 == 0 && j % 2 == 0 && j > 1 && (i == j + 1)) {
                continue;
            }
            int c = sz(edges);
            adj[i].pb({j, c});
            adj[j].pb({i, c});
            edges.pb({i, j});
        }
    }

    vi walk = eulerWalk(adj, sz(edges));

    rep(i, 0, n) {
        cout << cand[walk[i]] << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // prime_sieve(MAX_N);

    vl ps = {3, 5, 7, 11, 2};
    vector<vl> pws(5, vl(20, 1));
    rep(i, 1, 20) {
        rep(j, 0, 5){
            pws[j][i] = pws[j][i - 1] * ps[j];
        }
    }
    rep(x, 0, MX) {
        int i = x/10;
        int j = x % 10;

        cand[x] = pws[4][i + j] * pws[0][i] * pws[1][9 - i] * pws[2][j] * pws[3][9 - j];
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}