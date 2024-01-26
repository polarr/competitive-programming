/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-13
 * Contest: 1920
 * Problem: A
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
    int lower = 0;
    int upper = MOD;
    vector<int> invalid;
    for (int i = 0; i < n; i++){
        int a, x;
        cin >> a >> x;
        if (a == 1){
            lower = max(lower, x);
        } else if (a == 2){
            upper = min(upper, x);
        } else {
            invalid.pb(x);
        }
    }
    if (upper < lower){
        cout << 0 << endl;
        return;
    }
    int invalids = 0;
    for (int i = 0; i < invalid.size(); i++){
        if (invalid[i] >= lower && invalid[i] <= upper){
            invalids++;
        }
    }
    cout << upper - lower - invalids + 1 << endl;
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