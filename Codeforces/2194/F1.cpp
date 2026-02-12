/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-11
 * Contest: 
 * Problem: F1
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using sll = __int128;
using vi = vector<int>;
using vl = vector<ll>;
using vsl = vector<sll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

/**
 * Author: Lucian Bicsi
 * Date: 2015-06-25
 * License: GNU Free Documentation License 1.2
 * Source: csacademy
 * Description: Transform to a basis with fast convolutions of the form
 * $\displaystyle c[z] = \sum\nolimits_{z = x \oplus y} a[x] \cdot b[y]$,
 * where $\oplus$ is one of AND, OR, XOR. The size of $a$ must be a power of two.
 * Time: O(N \log N)
 * Status: stress-tested
 */
void FST(vsl& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			sll &u = a[j], &v = a[j + step]; tie(u, v) =
				// inv ? pii(v - u, u) : pii(v, u + v); // AND
				// inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line
				pair<sll, sll>(u + v, u - v);                   // XOR /// include-line
		}
	}
	if (inv) for (sll& x : a) x /= (sll)sz(a); // XOR only /// include-line
}
vsl conv(vsl a, vsl b) {
	FST(a, 0); FST(b, 0);
	rep(i,0,sz(a)) a[i] *= b[i];
	FST(a, 1); return a;
}

void solve(){
    int n, k; cin >> n >> k;

    vector<vi> adj(n);
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi vals(n);
    rep(i, 0, n) cin >> vals[i];

    vi b(k);
    rep(i, 0, k) cin >> b[i];

    ll tot = 1 << k;

    vector<vsl> cnt(n, vsl(tot, 0));
    vi sxor(n, 0);
    vi cxor(tot, 0);
    rep(i, 0, tot) {
        rep(j, 0, k) {
            if (i & (1 << j)) {
                cxor[i] ^= b[j];
            }
        }
    }

    auto isB = [&](int x) {
        rep(i, 0, k) {
            if (x == b[i]) return i;
        }

        return -1;
    };

    auto merge = [&](int x, int node) {
        sxor[node] ^= sxor[x];
        vsl good(tot, 0);
        rep(i, 0, tot) {
            int curr = sxor[x] ^ cxor[i];
            int j = isB(curr);
            if (j != -1) {
                good[i ^ (1 << j)] += cnt[x][i];
                good[i ^ (1 << j)] %= MOD;
            }
        }

        vsl ans = conv(good, cnt[node]);

        // if (node == 0) {
        //     rep(i, 0, tot) {
        //         cout << (ll)cnt[node][i] << " ";
        //     }
        //     cout << endl;
        //     rep(i, 0, tot) {
        //         cout << (ll)cnt[x][i] << " ";
        //     }
        //     cout << x << endl;
        // }

        vsl c = conv(cnt[x], cnt[node]);
        rep(i, 0, tot) {
            ans[i] += c[i] % MOD;
            ans[i] %= MOD;
        }

        cnt[node] = ans;
    };

    function<void(int, int)> dfs;
    dfs = [&](int node, int par) {
        sxor[node] = vals[node];
        cnt[node][0] = 1;
        for (int x : adj[node]) {
            if (x == par) continue;
            dfs(x, node);
            merge(x, node);
        }
    };

    dfs(0, -1);

    // cout << isB(1) << endl;
    // cout << (ll)cnt[1][0] << endl;

    ll ans = 0;
    rep(i, 0, tot) {
        int curr = sxor[0] ^ cxor[i];
        if (isB(curr) != -1) {
            ans += cnt[0][i] % MOD;
            ans %= MOD;
        }
    }

    cout << ans << '\n';
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