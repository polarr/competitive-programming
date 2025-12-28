/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-27
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

    vl arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }

    vl suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + arr[i];
    }

    ll ans = 0;

    rep(i, 1, n) {
        ans -= arr[i];
    }

    ll curr = arr[0];
    rep(i, 1, n) {
        ans = max(ans, curr - suf[i + 1]);
        curr += abs(arr[i]);
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