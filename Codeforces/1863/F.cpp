/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-26
 * Contest: 
 * Problem: F
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

vl pw(63);

void solve(){
    int n; cin >> n;

    vl vals(n);
    rep(i, 0, n) {
        cin >> vals[i];
    }

    vl pre(n + 1, 0);
    rep(i, 0, n) {
        pre[i + 1] = pre[i] ^ vals[i];
    }

    auto rangeXor = [&](int l, int r) {
        return pre[r + 1] ^ pre[l];
    };

    // ll msk = (1LL << 60);

    vector<bool> zeroL(n, false), zeroR(n, false);
    vl L(n, 0), R(n, 0);

    for (int len = n; len >= 1; len--) {
        rep(l, 0, n - len + 1) {
            int r = l + len - 1;
            ll val = rangeXor(l, r);

            bool possible = (len == n || zeroL[l] || zeroR[r]);
            if (L[l] & val) {
                possible = true;
            }

            if (R[r] & val) {
                possible = true;
            }

            if (possible && (val != 0)) {
                int msb = 63 - __builtin_clzll(val);
                L[l] |= pw[msb];
                R[r] |= pw[msb];
            }

            if (possible && val == 0) {
                zeroL[l] = true;
                zeroR[r] = true;
            }

            if (len == 1) {
                cout << (possible ? '1':'0');
            }
        }
    }

    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    rep(i, 0, sz(pw)) {
        pw[i] = (1LL << i);
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}