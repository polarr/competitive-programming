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

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        ll ans = -1e18;

        vl maxPos(n + 1, -1e9), maxNeg(n + 1, 1e9);
        for (int i = n - 1; i >= 0; i--){
            maxPos[i] = max(maxPos[i + 1], (ll)nums[i]);
            maxNeg[i] = min(maxNeg[i + 1], (ll)nums[i]);
        }
        
        rep(i, 0, n - m + 1){
            ll x = nums[i];
            if (x == 0) {
                ans = max(ans, 0LL);
            }
            if (x > 0){
                ans = max(ans, x * maxPos[i + m - 1]);
            } else {
                ans = max(ans, x * maxNeg[i + m - 1]);
            }
        }

        return ans;
    }
};