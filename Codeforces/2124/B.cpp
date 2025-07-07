/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-06
 * Contest: 
 * Problem: B
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

    vl arr(n);
    rep(i, 0, n) cin >> arr[i];

    vl pre(n + 1, LLONG_MAX), sumpre(n + 1, 0);
    pre[1] = arr[0];
    sumpre[1] = pre[1];

    ll sum = pre[1];
    rep(i, 2, n + 1){
        pre[i] = min(arr[i - 1], pre[i - 1]);
        sum += pre[i];
        sumpre[i] = sum;
    }

    ll ans = sum;

    rep(i, 1, n){
        ans = min(ans, sumpre[i - 1] + min(pre[i - 1], arr[i - 1] + arr[i]));
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