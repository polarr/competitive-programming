/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-13
 * Contest: Codeforces 2140
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
    ll ans = 0;
    rep(i, 0, n) {
        cin >> arr[i];
        if (i % 2 == 0) ans += arr[i];
        else ans -= arr[i];
    }

    if (n == 1) {
        cout << ans << endl;
        return;
    }

    ll add = (n % 2 == 1 ? n - 1 : n - 2);

    ll even = -1e17, odd = -1e17;
    rep(i, 0, n){
        if (i % 2 == 0){
            add = max(add, -arr[i] * 2 + i + odd);
            even = max(even, -arr[i] * 2 - i);
        }
        else {
            add = max(add, 2 * arr[i] + i + even);
            odd = max(odd, 2 * arr[i] - i);
        }
    }

    cout << ans + add << endl;
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