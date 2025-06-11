/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-05
 * Contest: AtCoder abc335
 * Problem: F
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

void solve(){
    int n; cin >> n;
    int rt = sqrt(n);

    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vl dp(n, 1);
    dp[n - 1] = 1;

    vector<vl> sum(rt, vl(rt, 0));
    rep(i, 1, rt){
        sum[i][(n - 1) % i] = 1;
    }

    for (int i = n - 2; i >= 0; i--){
        if (a[i] >= rt){
            for (int j = i + a[i]; j < n; j += a[i]){
                dp[i] += dp[j];
                dp[i] %= MOD;
            }
        } else {
            dp[i] += sum[a[i]][i % a[i]];
            dp[i] %= MOD;
        }

        rep(j, 1, rt){
            sum[j][i % j] += dp[i];
            sum[j][i % j] %= MOD;
        }
    }

    cout << dp[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}