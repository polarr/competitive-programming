/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-02
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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

const int D = 42;

void solve(){
    int n; cin >> n;

    vector<vi> arr(n, vi(7, 0));
    rep(i, 0, n) {
        int x; cin >> x;
        rep(j, 0, 6) {
            arr[i][j] = x % D;
            x /= D;
        }
    }

    function<ll(vi, int, int)> rec;
    rec = [&](vi idx, int layer, int carry) {
        if (sz(idx) == 0) {
            return 0LL;
        }

        int md = (arr[idx[0]][layer] + carry) % 6;
        bool good = true;
        rep(i, 1, sz(idx)) {
            int j = idx[i];
            if ((arr[j][layer] + carry) % 6 != md) {
                good = false;
                break;
            }
        }

        if (!good) {
            return -1LL;
        }

        ll ans = LLONG_MAX;
        ll pad = md == 0 ? 0 : 6 - md;

        if (layer == 6) {
            return pad;            
        }

        for (ll add = 0; add < D; add += 6) {
            vi nx;
            int c = 0;
            for (int i : idx) {
                int x = arr[i][layer] + carry + add + pad;
                if (x >= D) {
                    c = 1;
                }

                if (x % D == 0) {
                    nx.pb(i);
                }
            }

            ll nans = rec(nx, layer + 1, c);
            if (nans != -1) {
                ans = min(ans, nans * D + add + pad);
            }
        }

        return ans == LLONG_MAX ? -1 : ans;
    };

    vi every(n);
    rep(i, 0, n) {
        every[i] = i;
    }

    cout << rec(every, 0, 0) << '\n';
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