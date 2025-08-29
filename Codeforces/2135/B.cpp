/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-28
 * Contest: Codeforces 2135
 * Problem: B
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

const ll mx = 1e9;

ll query(char s, int d){
    cout << "? " << s << " " << d << endl;
    ll ans; cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;
    ll a = LLONG_MAX, b = LLONG_MAX;
    rep(i, 0, n){
        ll x, y; cin >> x >> y;
        a = min(a, -x - y);
        b = min(b, -x + y);
    }

    query('R', mx);
    query('R', mx);
    query('U', mx);
    ll d1 = query('U', mx);
    query('D', mx);
    query('D', mx);
    query('D', mx);
    ll d2 = query('D', mx);

    d1 -= a + mx * 4; d2 -= b + mx * 4;
    cout << "! " << (d1 + d2)/2 << " " << (d1 - d2)/2 << endl;
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