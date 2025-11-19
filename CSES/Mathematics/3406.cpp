/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-18
 * Contest: CSES Problemset
 * Problem: 3406
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

const ll MAX_N = 2e12 + 1;
const ll MOD = 1e9 + 7;

vl possible;

// lagrange three square
// 8n + 3 can be sum of 3 square (all are odd)
// = (2a + 1)^2 + (2b + 1)^2 + (2c + 1)^2
// => n = tri(a) + tri(b) + tri(c)
void solve(){
    auto check = [&](ll x) -> bool {
        ll k = sqrt(x);
        return (k * k + k) == x;
    };

    ll n; cin >> n;
    n *= 2;

    if (check(n)) {
        cout << 1 << endl;
        return;
    }

    for (ll c : possible) {
        if (check(n - c)) {
            cout << 2 << endl;
            return;
        }
    }

    cout << 3 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (ll i = 1; i * i + i < MAX_N; i++){
        possible.pb(i * i + i);
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}