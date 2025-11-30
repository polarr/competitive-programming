/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-29
 * Contest: 
 * Problem: B
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
const ll INF = 2e9;

void solve(){
    ll l, w, h; cin >> l >> w >> h;
    ll p, q, r; cin >> p >> q >> r;

    ll n; cin >> n;
    using T = array<ll, 3>;
    vector<T> almonds(n);
    rep(i, 0, n) {
        ll x, y, z; cin >> x >> y >> z;
        almonds[i] = {x, y, z};
    }

    ll tot = (p + 1) * (q + 1) * (r + 1);
    if (n % tot != 0) {
        cout << 0 << endl;
        return;
    }

    ll k = n/tot;

    sort(all(almonds));

    auto range = [&](ll l, ll r) -> ll {
        return r - l + 1;
    };

    ll ans = 1;
    using R = array<ll, 2>;
    vector<vector<R>> xs(p + 1);
    rep(i, 0, n) {
        ll split = (k * (q + 1) * (r + 1));
        ll idx = i/split;
        xs[idx].pb({almonds[i][1], almonds[i][2]});

        if (i != 0 && i % split == 0) {
            if (almonds[i - 1][0] == almonds[i][0]) {
                cout << 0 << endl;
                return;
            }

            ans *= range(almonds[i - 1][0], almonds[i][0] - 1);
            ans %= MOD;
        }
    }

    vector<vl> xys((p + 1) * (q + 1));
    vector<vector<R>> ys(q);
    rep(j, 0, p + 1) {
        vector<R> a = xs[j];
        sort(all(a));
        rep(i, 0, sz(a)) {
            ll split = (k * (r + 1));
            ll idx = i/split;
            xys[idx + j * (q + 1)].pb(a[i][1]);

            if (i != 0 && i % split == 0) {
                if (a[i - 1][0] == a[i][0]) {
                    cout << 0 << endl;
                    return;
                }

                ys[idx - 1].pb({a[i - 1][0], a[i][0] - 1});
            }
        }
    }

    rep(i, 0, q) {
        R rr = {0, INF};
        for (R rc : ys[i]) {
            rr[0] = max(rr[0], rc[0]);
            rr[1] = min(rr[1], rc[1]);
        }

        if (rr[0] > rr[1]) {
            cout << 0 << endl;
            return;
        }

        ans *= range(rr[0], rr[1]);
        ans %= MOD;
    }

    vector<vector<R>> zs(r);
    rep(j, 0, (p + 1) * (q + 1)) {
        vl a = xys[j];
        sort(all(a));
        rep(i, 0, sz(a)) {
            ll split = k;
            ll idx = i/split;
            if (i != 0 && i % split == 0) {
                if (a[i - 1] == a[i]) {
                    cout << 0 << endl;
                    return;
                }

                zs[idx - 1].pb({a[i - 1], a[i] - 1});
            }
        }
    }

    rep(i, 0, r) {
        R rr = {0, INF};
        for (R rc : zs[i]) {
            rr[0] = max(rr[0], rc[0]);
            rr[1] = min(rr[1], rc[1]);
        }

        if (rr[0] > rr[1]) {
            cout << 0 << endl;
            return;
        }

        ans *= range(rr[0], rr[1]);
        ans %= MOD;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}