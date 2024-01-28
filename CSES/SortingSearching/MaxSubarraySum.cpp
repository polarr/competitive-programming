/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-15
 * Contest: CSES Problem Set
 * Problem: Sorting and Searching - Maximum Subarray Sum
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<ll> minPrefix(n + 1, 0);
    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i < n + 1; i++){
        ll x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
        minPrefix[i] = min(minPrefix[i - 1], prefix[i]);
    }

    ll ans = LLONG_MIN;
    for (int i = 1; i < n + 1; i++){
        ans = max(ans, prefix[i] - minPrefix[i - 1]);
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}