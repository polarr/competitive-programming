/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-07
 * Contest: 
 * Problem: J
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

void solve(){
    int n, d; cin >> n >> d;

    vi arr(n);
    vi pos(n);
    rep(i, 0, n) {
        cin >> arr[i];
        --arr[i];
        pos[arr[i]] = i;
    }

    vi posb(n);
    vi brr(n);
    rep(i, 0, n) {
        cin >> brr[i];
        --brr[i];
        posb[brr[i]] = i;
    }

    ll rev = 0;
    rep(i, 1, n) {
        int x = brr[i];
        int y = brr[i - 1];
        if (pos[x] < pos[y]) {
            rev++;
        }
    }

    auto getAns = [&]() -> ll {
        return rev * n - (n - 1) + pos[brr[n - 1]];
    };

    auto contrib = [&](int j) {
        int ans = 0;
        // j in brr
        if (j != 0 && pos[brr[j]] < pos[brr[j - 1]]) {
            ans++;
        }

        return ans;
    };

    cout << getAns() << '\n';

    rep(qq, 0, d - 1) {
        int c, x, y; cin >> c >> x >> y;
        --x; --y;

        if (c == 2) {
            vi af = {x, y}, affected;
            if (x != n - 1) af.pb(x + 1);
            if (y != n - 1) af.pb(y + 1);

            sort(all(af));
            rep(i, 0, sz(af)) {
                if (i == 0 || af[i] != af[i - 1]) {
                    affected.pb(af[i]);
                }
            }

            for (int j : affected) {
                rev -= contrib(j);
            }

            swap(posb[brr[x]], posb[brr[y]]);
            swap(brr[x], brr[y]);

            for (int j : affected) {
                rev += contrib(j);
            }
        } else {
            vi af = {posb[arr[x]], posb[arr[y]]}, affected;

            if (posb[arr[x]] != n - 1) af.pb(posb[arr[x]] + 1);
            if (posb[arr[y]] != n - 1) af.pb(posb[arr[y]] + 1);

            sort(all(af));
            rep(i, 0, sz(af)) {
                if (i == 0 || af[i] != af[i - 1]) {
                    affected.pb(af[i]);
                }
            }

            for (int j : affected) {
                rev -= contrib(j);
            }

            swap(pos[arr[x]], pos[arr[y]]);
            swap(arr[x], arr[y]);

            for (int j : affected) {
                rev += contrib(j);
            }
        }

        cout << getAns() << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}