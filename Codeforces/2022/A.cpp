/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-13
 * Contest: Codeforces 2022
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
    int n, r; cin >> n >> r;
    int ans = 0;
    int pool = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x % 2 == 0){
            ans += x;
        } else {
            ans += x - 1;
            pool++;
        }
    }

    int remain = r - ans/2;
    if (pool > remain){
        ans += 2 * remain - pool;
    } else {
        ans += pool;
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