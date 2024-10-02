/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-29
 * Contest: Codeforces 2020
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
    int n, k; cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return;
    }
    int ans = 0;
    while(n > 0){
        ans += (n % k);
        n /= k;
        //cout << n << endl;
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