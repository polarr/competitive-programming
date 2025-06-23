/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-23
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
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    sort(all(a));

    ll ans = 0;
    rep(i, 0, n - 2){
        rep(j, i + 1, n - 1){
            int mn = upper_bound(a.begin() + j + 1, a.end(), a[n - 1] - a[i] - a[j]) - a.begin();
            int mx = --lower_bound(a.begin() + j + 1, a.end(), a[i] + a[j]) - a.begin();
            
            if (mn <= mx){
                ans += (ll)(mx - mn + 1);
            }
        }
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