/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-04
 * Contest: 
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
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    vector<int> sizes;
    int curr = 1;

    for (int i = 1; i < n; i++){
        if (arr[i] != arr[i - 1]){
            sizes.pb(curr);
            curr = 1;
        } else {
            curr++;
        }
    }

    sizes.pb(curr);
    sort(sizes.begin(), sizes.end());
    int ans = sizes.size();
    int i = 0;
    while(i < sizes.size() - 1 && k >= sizes[i]){
        k -= sizes[i];
        i++;
        ans --;
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