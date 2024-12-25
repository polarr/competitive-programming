/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-13
 * Contest: USACO 2024 December Silver
 * Problem: 1
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

    ll ans = 0, sum = 0;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    vector<ll> pref(n + 1, 0);
    vector<ll> suff(n + 1, 0);

    for (int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + arr[i];
        suff[i + 1] = suff[i] + arr[n - 1 - i];
    }

    for (int i = 0; i < n/2; i++){
        ans = max(ans, pref[i] + suff[n/2 - 1 - i]);
    }

    cout << sum - ans << " " << ans << endl;
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