/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-29
 * Contest: 
 * Problem: 3215
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
    ll n, m; cin >> n >> m;
    ll k; cin >> k;
    n--; m--;
    if (k == 0) {
        cout << "1 1 0\n";
        return;
    }

    auto md = [&](ll x, ll m) -> ll {
        if (x % m == 0) {
            return m;
        }

        return (x % m);
    };

    ll x = k % m, y = k % n;
    ll tx = k/m, ty = k/n;
    ll l = lcm(m, n);
    if (tx % 2 == 1) {
        x = m - x;
    }
    if (ty % 2 == 1) {
        y = n - y;
    }

    cout << y + 1 << " " << x + 1 << " " << tx + ty - k/l << '\n';
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