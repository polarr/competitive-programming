/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-03
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
const ll MOD = 998244353;

vector<int> z_function(vi& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve(){
    int n; cin >> n;

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    vl dp(n, 0);
    dp[0] = 1;
    rep(i, 1, n) {
        vi trim;
        rep(j, 0, i + 1) {
            trim.pb(arr[j]);
        }

        reverse(all(trim));
        vi z = z_function(trim);
        reverse(all(z));

        int bad = 0;
        for (int j = i; j >= 0; j--) {
            bad = max(bad, z[j]);

            if (bad == 0) {
                dp[i] += j == 0 ? 1 : dp[j - 1];
                dp[i] %= MOD;
            }

            bad = max(bad - 1, 0);
        }
    }

    cout << dp[n - 1] << endl;
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