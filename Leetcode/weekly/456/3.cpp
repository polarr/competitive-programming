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

const int MAX_N = 5e5 + 1;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();

        vi xr(n + 1, 0);
        rep(i, 0, n){
            xr[i + 1] = xr[i] ^ nums[i];
        }
        
        int dp[n][n][k + 1];
        rep(i, 0, n){
            rep(j, 0, n){
                rep(l, 0, k + 1){
                    dp[i][j][l] = -1;
                }
            }
        }

        function<int(int, int, int)> rec;
        rec = [&](int a, int b, int k){
            bool notexist = (dp[a][b][k] == -1);
            if (!notexist){
                return dp[a][b][k];
            }

            if (k == 1){
                dp[a][b][k] = xr[b + 1] ^ xr[a];
                return dp[a][b][k];
            }

            int ans = INT_MAX;

            rep(i, a, b - k + 2){
                ans = min(ans, max(rec(a, i, 1), rec(i + 1, b, k - 1)));
            }

            dp[a][b][k] = ans;
            return ans;
        };

        return rec(0, n - 1, k);
    }
};