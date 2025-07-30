/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-22
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
    ll lo, hi; cin >> lo >> hi;

    auto divide = [&](ll prime){
        return hi/prime - (lo - 1)/prime;
    };

    vl primes = {2, 3, 5, 7};

    ll ans = 0;
    rep(i, 1, 1 << 4){
        ll div = 1;
        ll cnt = -1;
        rep(j, 0, 4){
            if (i & (1 << j)){
                div *= primes[j];
                cnt *= -1;
            }
        }

        ans += cnt * divide(div);
    }

    cout << hi - lo + 1 - ans << endl;
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