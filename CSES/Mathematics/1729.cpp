/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-28
 * Contest: CSES Problemset
 * Problem: 1729
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
    vi arr(k);
    rep(i, 0, k) cin >> arr[i];

    sort(all(arr));

    vector<bool> dp(n + 1);
    dp[0] = false;
    rep(i, 1, n + 1) {
        bool good = false;
        rep(j, 0, k) {
            if (i - arr[j] < 0) {
                break;
            }

            if (!dp[i - arr[j]]) {
                good = true;
                break;
            }
        }

        dp[i] = good;
    }

    rep(i, 1, n + 1) {
        cout << (dp[i] ? "W":"L");
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}