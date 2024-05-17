/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-10
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 2428 - Subarray Distinct Values
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll n, k; cin >> n >> k;

    vector<ll> arr;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        arr.pb(a);
    }

    int left = 0;
    int right = 0;

    ll ans = 0;
    int curr = 0;
    int flag = 0;

    while (left < n && right <= n){
        if (flag){
            flag = false;
            continue;
        }

        if (left == right){
            if (right < n){
                if (count[arr[right]] == 0){
                    curr++;
                }

                count[arr[right]]++;
                if (curr > k)[
                    flag = true;
                ]
            }
            right++;
            continue;
        }

        if (right < n){
            if (count[arr[right]] == 0){
                curr++;
            }

            count[arr[right]]++;
            if (curr > k){
                flag = true;
            }
        }
        right++;

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