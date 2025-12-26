/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-23
 * Contest: 
 * Problem: D
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

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    pii range = {0, arr[1] - arr[0]};
    int ans = 0;
    rep(i, 1, n) {
        int d1 = arr[i] - arr[i - 1];
        int d2 = i == n - 1 ? INT_MAX : arr[i + 1] - arr[i];

        int d = min(d1, d2);
        if (range.first >= d) {
            range = {d2 - d, d2};
            continue;
        }
        
        ans++;
        int mn = range.first;
        int mx = min(range.second, d);

        range = {d2 - mx, d2 - mn};
    }

    cout << ans << '\n';
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