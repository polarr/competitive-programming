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

const ll MOD = 1e9 + 7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<int, ll> before;
        map<int, ll> after;
        for (int n : nums){
            after[n]++;
        }

        ll ans = 0;

        rep(i, 0, nums.size()){
            int x = nums[i];

            after[x]--;

            ans += before[2 * x] * after[2 * x] % MOD;
            ans %= MOD;

            before[x]++;
        }

        return (int)ans;
    }
};