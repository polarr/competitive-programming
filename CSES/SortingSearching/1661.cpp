/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-10
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1661 - Subarray Sums II
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll n, x; cin >> n >> x;

    vector<ll> arr = {0};
    // multiset<ll> prefix;

    map<ll, int> prefix;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        arr.pb(arr[i] + a);
        // prefix.insert(arr[i] + a);
        prefix[arr[i] + a]++;
    }

    for (int i = 0; i < n; i++){
        ll target = x + arr[i];
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