/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-17
 * Contest: Codeforces 2126
 * Problem: G1
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
    vi a(n);
    vector<bool> has(100, false);
    rep(i, 0, n) {
        cin >> a[i];
        has[a[i]] = true;
    }

    int ans = 0;

    auto check = [&](int sm, int med){
        int sum = 0;
        rep(i, 0, n){
            if (a[i] < med) {
                sum--;
            } else {
                sum++;
            }

            if (a[i] == sm && sum >= 0){
                return true;
            }

            if (sum < 0) sum = 0;
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--){
            if (a[i] < med) {
                sum--;
            } else {
                sum++;
            }

            if (a[i] == sm && sum >= 0){
                return true;
            }

            if (sum < 0) sum = 0;
        }

        return false;
    };

    rep(sm, 1, 101){
        if (!has[sm]) continue;

        int lo = sm, hi = 100;
        while (lo < hi){
            int mid = (lo + hi + 1)/2;

            if (check(sm, mid)){
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        ans = max(ans, lo - sm);
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