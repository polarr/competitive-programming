/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-18
 * Contest: Codeforces 1810
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
    ll n, c, d; cin >> n >> c >> d;

    vl a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vl possible;
    vl unique;

    sort(all(a));
    if (a[0] != 1){
        possible.pb(1);
        unique.pb(0);
    }

    ll u = 0;

    rep(i, 0, n){
        if (i == 0 || a[i] != a[i - 1]){
            u++;
            unique.pb(u);
            possible.pb(a[i]);
        }
    }

    ll ans = LLONG_MAX;

    rep(i, 0, possible.size()){
        ll x = possible[i];
        ll unq = unique[i];

        ans = min(ans, (x - unq) * d + (n - unq) * c);
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