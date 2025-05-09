/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-09
 * Contest: Baltic OI 2017
 * Problem: toll
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
    int k, n, m, o; cin >> k >> n >> m >> o;

    int nn = n/k + 1;
    int lg = log2(nn) + 1;

    ll jump[nn][k][lg][k];

    fill(&jump[0][0][0][0], &jump[0][0][0][0] + nn * k * lg * k, 1e18);

    rep(i, 0, m){
        int a, b; cin >> a >> b;
        ll t; cin >> t;
        int a1 = a/k, a2 = a % k, b1 = b/k, b2 = b % k;
        jump[a1][a2][0][b2] = t;
    }

    rep(i, 1, lg){
        rep(x, 0, nn){
            if ((x + (1 << i)) >= nn) break;
            int xx = x + (1 << (i - 1));
            rep(a, 0, k){
                rep(b, 0, k){
                    ll ans = 1e18;
                    rep(c, 0, k){
                        ans = min(ans, jump[x][a][i - 1][c] + jump[xx][c][i - 1][b]);
                    }
                    jump[x][a][i][b] = ans;
                }
            }
        }
    }

    rep(i, 0, o){
        int a, b; cin >> a >> b;
        int a1 = a/k, a2 = a % k, b1 = b/k, b2 = b % k;

        if (b1 <= a1){
            cout << -1 << endl;
            continue;
        }

        vector<vl> dp(k, vl(k, 1e18));
        rep(i, 0, k){
            dp[i][i] = 0;
        }

        int d = b1 - a1;
        int layer = b1;
        for (int j = lg - 1; j >= 0; j--){
            if (d & (1 << j)) {
                int x = layer - (1 << j);
                vector<vl> pp(k, vl(k));
                rep(a, 0, k){
                    rep(b, 0, k){
                        ll ans = 1e18;
                        rep(c, 0, k){
                            ans = min(ans, jump[x][a][j][c] + dp[c][b]);
                        }

                        pp[a][b] = ans;
                    }
                }

                dp = pp;

                layer = x;
            }
        }

        if (dp[a2][b2] == 1e18){
            cout << -1 << endl;
            continue;
        }

        cout << dp[a2][b2] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}