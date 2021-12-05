/**
 * Solution by 1egend
 * Date: 7/12/2021
 * Contest: Codeforces Round 633 (Div 2)
 * Problem: B. Sorted Adjacent Differences
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
    vector <int> arr;
    for (int i = 0; i < n; ++i){
        static int t;
        cin >> t;
        arr.pb(t);
    }

    sort(arr.begin(), arr.end());
    vector <int> ans;

    bool right = true;
    int l = ceil(n/2.0) - 1;
    int r = l + 1;
    while(l >= 0 || r < n){
        if (right){
            ans.pb(arr[l]);
            --l;
            right = false;
            continue;
        }

        ans.pb(arr[r]);
        ++r;
        right = true;
    }

    for (int i = 0; i < n; ++i){
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}