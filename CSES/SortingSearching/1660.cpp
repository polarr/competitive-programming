/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-10
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1660 - Subarray Sums I
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

    vector<ll> arr;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        arr.pb(a);
    }

    int left = 0;
    int right = 0;

    ll sum = 0;
    ll ans = 0;

    while (left < n && right <= n){
        if (left == right){
            if (right < n){
                sum += arr[right];
            }
            right++;
            continue;
        }

        if (sum >= x){
            if (sum == x){
                ans++;
            }
            sum -= arr[left];
            left++;          
            continue;
        }

        if (sum < x){
            if (right < n){
                sum += arr[right];
            }
            right++;
            continue;
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