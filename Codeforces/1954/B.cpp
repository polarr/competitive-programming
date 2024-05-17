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
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr.pb(a);
    }

    int target = arr[0];
    int block = 0;
    int mn = INT_MAX;

    for (int i = 0; i < n; i++){
        if (arr[i] == target){
            block++;
        } else {
            if (block != 0){
                mn = min(mn, block);
            }
            block = 0;
        }
    }

    if (block != 0){
        mn = min(mn, block);
    }

    if (mn == n){
        cout << -1 << endl;
    } else {
        cout << mn << endl;
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