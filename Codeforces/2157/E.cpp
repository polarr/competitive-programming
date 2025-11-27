/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-26
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

    vi cnt(10 * n, 0);
    rep(i, 0, n) {
        int a; cin >> a;
        --a;
        cnt[a]++;
    }

    int ans = 0;
    vi dp(2 * n);
    for (int i = 2 * n - 1; i >= 0; i--) {
        int x = i;
        bool done = false;
        int amt = cnt[x];
        while (amt > 0) {
            if (!done && amt <= k) {
                done = true;
                ans = max(ans, x - i);
            }

            if (cnt[x + 1] == 0) {
                x++;
                amt--;
            } else {
                x = dp[x + 1];
            }
        }

        dp[i] = x - 1;
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