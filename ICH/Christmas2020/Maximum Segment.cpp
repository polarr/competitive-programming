/** Code by 1egend**/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// Kadane's Algorithm O(n)
int maxSubarraySum(std::vector <int> k){
    int best = 0;
    int sum = 0;
    int i;
    for (i = 0; i < k.size(); i++){
        sum = max<int>(k[i], sum + k[i]);
        best = max<int>(best, sum);
    }

    return best;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector <int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int t;
        cin >> t;
        arr.push_back(t);
    }
    ll ans = maxSubarraySum(arr);
    for (int i = 1; i < n; ++i){
    	rotate(arr.begin(), arr.begin() + 1, arr.end());
    	ans = max<ll>(ans, maxSubarraySum(arr));
    }
    cout << ans;
    return 0;
}