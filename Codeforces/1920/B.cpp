/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-13
 * Contest: 1920
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr;
    int sum = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.pb(a);
        sum += a;
    }
    sort(arr.begin(), arr.end(), std::greater<>());
    vector<int> prefix(n + 1, 0);
    prefix[0] = 0;
    for (int i = 0; i < n; i++){
        prefix[i + 1] = arr[i] + prefix[i];
    }
    int subtract = INT_MAX;
    for (int i = 0; i <= k; i++){
        subtract = min(subtract, 2 * prefix[min(n, i + x)] - prefix[i]);
    }

    cout << sum - subtract << endl;
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