/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-12
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

const int MAX_N = 60;
const ll MOD = 1e9 + 7;

void solve(){
    int n; ll k; cin >> n >> k;

    ll ans = 0;
    vl can;
    rep(j, 0, n){
        ll a; cin >> a;
        for (ll i = 0; i < MAX_N; i++){
            if (a & (1LL << i)){
                ans++;
                continue;
            }

            can.pb(1LL << i);
        }
    }

    sort(all(can));
    rep(i, 0, can.size()){
        if (k >= can[i]){
            ans++;
            k -= can[i];
        } else {
            break;
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