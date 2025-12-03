/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-02
 * Contest: 
 * Problem: 3405
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
    int n, k; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;

    int lg = (int)log2(1e9) + 1;
    vl pow2(lg, 1);
    rep(i, 1, lg) {
        pow2[i] = pow2[i - 1] * 2;
    }

    vl arr(n, x);
    rep(i, 1, n) {
        arr[i] = (arr[i - 1] * a + b) % c;
    }
    
    ll ans = 0;
    rep(j, 0, lg) {
        int t = pow2[j];
        ll bit = 0, last = -1;
        rep(i, 0, k - 1) {
            bool has = arr[i] & t;
            if (has) {
                last = i;
            }
        }

        rep(i, k - 1, n) {
            bool has = arr[i] & t;
            if (has) {
                last = i;
            }

            bit ^= (last > i - k);
        }

        if (bit) {
            ans |= pow2[j];
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}