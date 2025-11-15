/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-14
 * Contest: 
 * Problem: D2
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

const ll MAX_N = 1e12;
const ll MOD = 1e9 + 7;

void solve(){
    ll x, y, k; cin >> x >> y >> k;

    if (y == 1) {
        cout << -1 << endl;
        return;
    }

    if (k < y){
        cout << k << endl;
        return;
    }

    while (k <= MAX_N && x > 0) {
        ll a = k/(y - 1);
        ll b = k % (y - 1);

        if (b == 0) {
            k += a - 1;
            x--;
        } else {
            ll mn = (y - 1 - b + a - 1)/a;

            if (x < mn) {
                k += x * a;
                x = 0;
            } else {
                k += mn * a;
                x -= mn;
            }
        }
    }

    if (k > MAX_N) {
        cout << -1 << endl;
    } else {
        cout << k << endl;
    }
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