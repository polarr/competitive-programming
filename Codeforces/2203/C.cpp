/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-05
 * Contest: 
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
const ll MOD = 1e9 + 7;

void solve(){
    ll s, m; cin >> s >> m;

    ll pw2 = 1;
    while (m % 2 == 0) {
        pw2 *= 2;
        m /= 2;
    }

    if (s % pw2 != 0) {
        cout << -1 << endl;
        return;
    }

    s /= pw2;

    ll ans = 0;
    while (s != 0) {
        if (s < m) {
            for (int i = 60; i >= 0; i--) {
                if ((1LL << i))
            }
            m %= s;
        }

        ans = max(ans, (s + m - 1)/m);
        s %= m;
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