/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-16
 * Contest: CSES Problemset
 * Problem: 1644. Maximum Subarray Sum II
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
    int a, b; cin >> a >> b;

    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        prefix[i + 1] = prefix[i] + x;
    }

    multiset<ll> curr;
    for (int i = a; i <= b; i++){
        curr.insert(prefix[i]);
    }

    ll ans = LLONG_MIN;
    for (int i = 1; i <= n - a + 1; i++){       
        ans = max(ans, *(--curr.end()) - prefix[i - 1]);
        curr.erase(curr.find(prefix[i + a - 1]));
        if (i <= n - b){
            curr.insert(prefix[i + b]);
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}