/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-11
 * Contest: USACO 2022 Open Gold
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    string x, y; cin >> x >> y;

    string a = "", b = "";

    // prune *1 they're useless, use 0 to clear the past

    for (int i = 0; i < n; i++){
        if (x[i] != '1'){
            a += x[i];
        }

        if (x[i] == '0'){
            a = "0";
        }

        if (y[i] != '1'){
            b += y[i];
        }

        if (y[i] == '0'){
            b = "0";
        }
    }

    n = a.length();
    int m = b.length();

    vector<int> al(n + 1, 0);
    vector<int> bl(m + 1, 0);
    vector<int> all(n + 1, 0);
    vector<int> bll(m + 1, 0);
    for (int i = 1; i < n + 1; i++){
        if (a[i - 1] == '+'){
            al[i] = i;
        }
        else if (a[i - 1] == '0'){
            al[i] = 0;
        }
        else {
            al[i] = al[i - 1];
        }

        if (a[i - 1] == '+'){
            all[i] = all[i - 1];
        } else {
            all[i] = i;
        }
    }
    for (int i = 1; i < m + 1; i++){
        if (b[i - 1] == '+'){
            bl[i] = i;
        }
        else if (b[i - 1] == '0'){
            bl[i] = 0;
        }
        else {
            bl[i] = bl[i - 1];
        }

        if (b[i - 1] == '+'){
            bll[i] = bll[i - 1];
        } else {
            bll[i] = i;
        }
    }
    vector<vector<ull>> dp(n + 1, vector<ull>(m + 1, 1));

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            if (b[j - 1] == '+'){
                if (a[i - 1] == '0'){
                    // choose 0 at the end or + at the end
                    dp[i][j] = 1 + dp[i][j - 1];
                    dp[i][j] %= MOD;
                } else if (a[i - 1] == '+'){
                    ull lla = all[i] == 0 ? 0 : dp[all[i] - 1][j];
                    ull llb = bll[j] == 0 ? 0 : dp[i][bll[j] - 1];
                    dp[i][j] = dp[i - 1][j - 1] + llb + lla;
                    dp[i][j] %= MOD;
                }
                else {
                    // + at the end, or before
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                    dp[i][j] %= MOD;
                }
                continue;
            }

            if (b[j - 1] == '0'){
                if (a[i - 1] == '0'){
                    dp[i][j] = 1;
                    dp[i][j] %= MOD;
                }
                else if (a[i - 1] == '+'){
                    // 0 at the end or + at the end
                    dp[i][j] = 1 + dp[i - 1][j]; 
                    dp[i][j] %= MOD;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    dp[i][j] %= MOD;
                }
                continue;
            }

            if (a[i - 1] == '0'){
                dp[i][j] = dp[i][j - 1];
                dp[i][j] %= MOD;
            }
            else if (a[i - 1] == '+'){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= MOD;
            } else {
                ull la = al[i] == 0 ? 0 : dp[al[i] - 1][j];
                ull lb = bl[j] == 0 ? 0 : dp[i][bl[j] - 1];
                dp[i][j] = dp[i - 1][j - 1] + lb + la;
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n][m] << endl;
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