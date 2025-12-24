/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-23
 * Contest: 
 * Problem: H
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

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;

const int lgm = log2(MAX_N) + 2;

vl pw2(lgm);

void solve(){
    int n, q; cin >> n >> q;

    int lg = log2(n) + 2;

    vector<vl> res(lg);
    vector<vl> tot(lg);
    rep(i, 0, lg) {
        res[i] = vl(pw2[i], 0);
        tot[i] = vl(pw2[i], 0);
    }

    vector<vi> a(n), b(n);

    rep(qq, 0, q) {
        int l, r; cin >> l >> r;
        --l; --r;
        a[l].pb(l);
        if (r != n - 1) b[r + 1].pb(l);
    }

    rep(i, 0, n) {
        for (int l : a[i]) {
            rep(pw, 1, lg) {
                int f = l + pw2[pw - 1] - 1; 
                res[pw][f % pw2[pw]]++;
                tot[pw][f % pw2[pw]]+= l;
            }
        }

        for (int l : b[i]) {
            rep(pw, 1, lg) {
                int f = l + pw2[pw - 1] - 1; 
                res[pw][f % pw2[pw]]--;
                tot[pw][f % pw2[pw]]-= l;
            }
        }

        ll ans = 0;
        rep(pw, 1, lg) {
            int x = i % pw2[pw];
            ll curr = res[pw][x] * (ll)(i + 1);
            curr -= tot[pw][x];

            curr *= pw2[pw - 1];
            ans += curr;
        }

        cout << ans << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    rep(i, 0, lgm) {
        pw2[i] = (1 << i);
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}