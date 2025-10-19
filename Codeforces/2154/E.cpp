/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-19
 * Contest: 
 * Problem: E
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
    int n, k; cin >> n >> k;

    vl arr(n);
    rep(i, 0, n) cin >> arr[i];

    sort(all(arr));

    vl pre(n + 1, 0);
    rep(i, 0, n){
        pre[i + 1] = pre[i] + arr[i];
    }

    auto sum = [&](int i, int j) -> ll {
        return pre[j + 1] - pre[i];
    };

    ll mx = 0;

    rep(i, 1, n){
        // choose i as median

        int lo = 0, hi = min((i + k - 1)/k, n - 1 - i);
        while (lo < hi){
            int mid = (lo + hi + 1)/2;

            int l = (mid - 1) * k;
            int r = min(mid * k - 1, i - 1);

            ll diff = (ll)(r - l + 1) * arr[i] - sum(l, r) + arr[i] - arr[i + mid];

            if (diff > 0){
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        if (lo == 0) continue;

        ll r = min(lo * k - 1, i - 1);
        ll diff = (r + 1) * arr[i] - sum(0, r) + (ll)(lo) * arr[i] - sum(i + 1, i + lo);

        mx = max(mx, diff);
    }

    ll ans = mx;
    rep(i, 0, n){
        ans += arr[i];
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