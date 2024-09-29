/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-28
 * Contest: Codeforces 2019
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll n, k; cin >> n >> k;

    ll total = 0;
    ll a = 0;
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        total += x;
        a = max(a, x);
    }

    //bruh...

    if (k >= a - 1){
        cout << min(n, (total + k)/a) << endl;
        return;
    }

    for (ll ans = n + 1; ans >= 1; ans--){
        ll aa = floor((total + k) * 1.0 /ans);
        if (aa >= a && aa >= ceil(total * 1.0/ans)){
            cout << ans << endl;
            return;
        }
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