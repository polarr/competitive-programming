/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-13
 * Contest: 1920
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

int check(vector<int> arr, int k){
    int g = abs(arr[k] - arr[0]);
    for (int i = 0; i < k; i++){
        int t = k + i;
        while (t < arr.size()){
            g = __gcd(g, abs(arr[t] - arr[i]));
            t += k;
            if (g == 1){
                return 0;
            }
        }
    }

    return 1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr.pb(a);
    }
    int ans = 0;
    for (int k = 1; k <= floor(sqrt(n)); k++){
        if (n % k == 0){
            ans += check(arr, k);
            if (k * k != n){
                if (k == 1){
                    ans++;
                    continue;
                }
                ans += check(arr, n/k);
            }
        }
    }

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