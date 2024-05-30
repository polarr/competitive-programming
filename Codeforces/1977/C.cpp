/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
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

    vector<int> arr;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr.pb(a);
    }

    sort(arr.begin(), arr.end());

    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    prefix[1] = arr[0];
    for (int i = 1; i < n; i++){
        prefix[i + 1] = lcm(arr[i], prefix[i]);
    }

    int curr = arr[mx];
    for (int mx = n - 1; mx >= 0; mx--){
        if (prefix[mx + 1] == curr){
            continue;
        } else {
            cout << mx + 1 << endl;
            return;
        }
    }
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