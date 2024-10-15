/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-14
 * Contest: USACO 2016 Feb Gold
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

const string iofilename = "cbarn2";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, k; fin >> n >> k;

    vector<ull> barn(n);
    for (int i = 0; i < n; i++){
        fin >> barn[i];
    }

    vector<vector<vector<ull>>> dp(n, vector<vector<ull>>(n, vector<ull>(k, 0)));

    auto calc_steps = [&](int x, int y){
        ull ans = 0;
        if (y >= x){
            for (int i = x; i <= y; i++){
                ans += barn[i] * (i - x);
            }
            return ans;
        }

        for (int i = x; i < n; i++){
            ans += barn[i] * (i - x);
        }

        for (int i = 0; i <= y; i++){
            ans += barn[i] * (i + n - x);
        }

        return ans;
    };

    ull curr = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dp[i][j][0] = calc_steps(i, j);
        }
    }

    for (int doors = 1; doors < k; doors++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                ull mn = dp[i][j][doors - 1];
                ull curr = 0;
                if (j >= i){
                    for (int x = i + 1; x <= j; x++){
                        curr += barn[x - 1] * (x - 1 - i);
                        mn = min(mn, curr + dp[x][j][doors - 1]);
                    }
                } else {
                    for (int x = i + 1; x < n; x++){
                        curr += barn[x - 1] * (x - 1 - i);
                        mn = min(mn, curr + dp[x][j][doors - 1]);
                    }

                    for (int x = 0; x <= j; x++){
                        curr += barn[(n + x - 1) % n] * (x - 1 + n - i);
                        mn = min(mn, curr + dp[x][j][doors - 1]);
                    }
                }

                dp[i][j][doors] = mn;
            }
        }
    }
    
    ull ans = ULLONG_MAX;
    for (int i = 0; i < n; i++){
        ans = min(ans, dp[i][(n + i - 1) % n][k - 1]);
    }

    fout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}