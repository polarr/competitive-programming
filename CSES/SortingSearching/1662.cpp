/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-10
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1662 - Subarray Divisibility
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

int real_mod(int x, int m){
    x %= m;

    if (x < 0){
        x += m;
    }

    return x;
}

void solve(){
    int n; cin >> n;

    vector<int> arr = {0};
    // multiset<ll> prefix;

    unordered_map<int, int> prefix;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        int pre = real_mod(arr[i] + a, n);
        arr.pb(pre);
        // prefix.insert(arr[i] + a);
        prefix[pre]++;
    }

    for (int i = 0; i < n; i++){
        ll target = real_mod(n + arr[i], n);
        ans += prefix[target];
        prefix[arr[i + 1]]--;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}