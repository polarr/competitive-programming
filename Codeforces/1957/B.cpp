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

int max_two(int n){
    int ans = 1;
    while(ans * 2 <= n){
        ans *= 2;
    }

    return ans;
}

void solve(){
    int n, k; cin >> n >> k;

    if (n == 1){
        cout << k << endl;
        return;
    }

    cout << max_two(k) - 1 << " ";
    for (int i = 0; i < n - 2; i++){
        cout << 0 << " ";
    }
    cout << k - max_two(k) + 1 << endl;
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