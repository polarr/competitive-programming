/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-24
 * Contest: 
 * Problem: 1146
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
    ll n; cin >> n;

    int lg = log2(1e18);
    ll ans = 0;
    rep(pw, 0, lg) {
        ll bit = (1LL << pw);
        if (n & bit) {
            ll rem = ((n >> (pw + 1)) << pw) + (n % bit);
            ans += rem + 1;
        } else {
            ll trunc = (n >> (pw + 1));
            ans += trunc * bit;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}