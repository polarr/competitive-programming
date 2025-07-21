/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-20
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

void solve(){
    int n, k; cin >> n >> k;

    ll ans = 1;

    int cols[n - 1][2];
    rep(i, 0, n){
        int x; cin >> x;
        if (i != 0) cols[i - 1][0] = x;
        else if (x == -1) ans *= k;
    }

    rep(i, 0, n){
        int x; cin >> x;
        if (i != n - 1) cols[i][1] = x;
        else if (x == -1) ans *= k;
    }

    ans %= MOD;

    ll dp[n][k + 1];
    rep(i, 0, k + 1){
        dp[n - 1][i] = 1;
    }

    for (int i = n - 2; i >= 0; i--){
        int a = cols[i][0], b = cols[i][1];
        rep(j, 0, k){
            dp[i][j] = 0;
            if (a == -1 && b == -1){
                rep(jj, 0, j + 1){
                    dp[i][j] += (ll)(k - jj) * dp[i + 1][j - jj] % MOD;
                    dp[i][j] %= MOD;
                }

                rep(jj, 1, k){
                    dp[i][j] += (ll)(k - jj) * dp[i + 1][jj];
                    dp[i][j] %= MOD;
                }
            } else if (a != -1 && b != -1){
                if (a - b > j){
                    dp[i][j] = 0;
                    continue;
                }

                int req = j;
                if (b > a){
                    req = b - a;
                } else {
                    req -= a - b;
                }

                dp[i][j] = dp[i + 1][req];
            } else if (b == -1){
                rep(bb, 1, k + 1){
                    if (a - bb > j) continue;
                    if (bb > a){
                        dp[i][j] += dp[i + 1][bb - a];
                    } else {
                        dp[i][j] += dp[i + 1][j - (a - bb)];
                    }
                    
                    dp[i][j] %= MOD;
                }
            } else { // a == -1
                rep(aa, 1, k + 1){
                    if (aa - b > j) break;
                    if (b > aa){
                        dp[i][j] += dp[i + 1][b - aa];
                    } else {
                        dp[i][j] += dp[i + 1][j - (aa - b)];
                    }
                    
                    dp[i][j] %= MOD;
                }
            }
        }

        int j = k;
        dp[i][j] = 0;
        if (a == -1 && b == -1){
            rep(jj, 0, k){
                dp[i][j] += (ll)(k - jj) * dp[i + 1][k] % MOD;
                dp[i][j] %= MOD;
            }

            rep(jj, 1, k){
                dp[i][j] += (ll)(k - jj) * dp[i + 1][jj];
                dp[i][j] %= MOD;
            }
        } else if (a != -1 && b != -1){
            int req = k;
            if (b > a){
                req = b - a;
            }

            dp[i][j] = dp[i + 1][req];
        } else if (b == -1){
            rep(bb, 1, k + 1){
                if (bb > a){
                    dp[i][j] += dp[i + 1][bb - a];
                } else {
                    dp[i][j] += dp[i + 1][k];
                }
                
                dp[i][j] %= MOD;
            }
        } else { // a == -1
            rep(aa, 1, k + 1){
                if (b > aa){
                    dp[i][j] += dp[i + 1][b - aa];
                } else {
                    dp[i][j] += dp[i + 1][k];
                }
                
                dp[i][j] %= MOD;
            }
        }
    }

    ans *= dp[0][k];
    ans %= MOD;

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