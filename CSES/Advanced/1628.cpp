/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-09
 * Contest: CSES Problemset
 * Problem: 1628
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
    ll n, x; cin >> n >> x;
    vl a;

    vl arr((n + 1)/2), brr(n/2);
    rep(i, 0, (n + 1)/2){
        cin >> arr[i];
    }
    rep(i, 0, n/2){
        cin >> brr[i];
    }

    ll ans = 0;

    rep(i, 0, 1 << arr.size()){
        ll sum = 0;
        rep(j, 0, arr.size()){
            if (i & (1 << j)){
                sum += arr[j];
            }
        }

        a.pb(sum);
    }

    sort(all(a));

    rep(i, 0, 1 << brr.size()){
        ll sum = 0;
        rep(j, 0, brr.size()){
            if (i & (1 << j)){
                sum += brr[j];
            }
        }

        ans += upper_bound(all(a), x - sum) - lower_bound(all(a), x - sum);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}