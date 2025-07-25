/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-05
 * Contest: 
 * Problem: A
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
    ll a, b; ll x, y; cin >> a >> b >> x >> y;

    if (a <= b){
        ll ans = 0;
        while (b > a){
            if (a % 2 == 0){
                ans += min(x, y);
            } else {
                ans += x;
            }

            a++;
        }

        cout << ans << endl;
    } else {
        if ((a ^ 1) == b){
            cout << y << endl;
        } else {
            cout << -1 << endl;
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