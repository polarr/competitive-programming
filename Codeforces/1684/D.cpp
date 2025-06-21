/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-19
 * Contest: 
 * Problem: D
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
    ll n, k; cin >> n >> k;
    vl a(n);
    ll ans = (n - 1) * k - (k * (k - 1))/2;
    rep(i, 0, n) {
        cin >> a[i];
        ans += a[i];
        a[i] += (ll)i;
    }

    sort(a.rbegin(), a.rend());
    rep(i, 0, k){
        ans -= a[i];
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