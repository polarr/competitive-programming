/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-25
 * Contest: Codeforces 2180
 * Problem: E
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
    ll l, r; cin >> l >> r;

    if (l == r) {
        cout << 0 << endl;
        return;
    }

    bool flag = false;
    ll ans1 = 1;
    int lg = (int)log2(r) + 1;
    vi L(lg), R(lg);
    int cnt = 0;
    int f = 0;
    for (int i = lg - 1; i >= 0; i--) {
        ll bit = (1LL << i);
        bool a = l & bit, b = r & bit;
        L[i] = a;
        R[i] = b;

        // cout << a << " " << b << endl;

        if (a == b) {
            if (flag) {
                ans1 = 0;
            }
        } else if (!flag) {
            flag = true;
            f = i + 1;
        }
    }

    rep(i, 0, lg) {
        if (L[i] != 0 || R[i] != 1) break;

        cnt++;
    }

    if (cnt == f) {
        cnt--;
    }

    rep(i, 0, cnt) {
        ans1 *= 2LL;
    }

    ll ans2 = 1;
    rep(i, 0, cnt) {
        ans2 *= 2LL;
    }

    cout << ans2 + ans1 - 1 << endl;
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