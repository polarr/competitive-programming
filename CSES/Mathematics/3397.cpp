/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-18
 * Contest: 
 * Problem: 3397
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

vl basis(20);

void solve(){
    int c, n; cin >> c >> n;

    if (c == 1){
        ll k; cin >> k;
        k--;

        vl curr;
        rep(i, 1, n + 1){
            curr.pb(i);
        }

        for (int i = n - 1; i >= 0; i--){
            ll x = k/basis[i];
            k -= x * basis[i];

            cout << curr[x] << " ";
            curr.erase(curr.begin() + x);
        }

        cout << endl;
        return;
    }

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    vl curr;
    rep(i, 1, n + 1){
        curr.pb(i);
    }

    ll ans = 1;

    for (int i = n - 1; i >= 0; i--){
        ll x;
        rep(j, 0, sz(curr)){
            if (curr[j] == arr[n - 1 - i]){
                x = j;
                break;
            }
        }

        curr.erase(curr.begin() + x);

        ans += basis[i] * x;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    basis[0] = 1;
    rep(i, 1, 20){
        basis[i] = basis[i - 1] * i;
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}