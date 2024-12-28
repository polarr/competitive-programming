/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-27
 * Contest: 
 * Problem: 2419
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

    vector<int> pow2(n + 1, 0);
    for (int i = 2; i < n + 1; i++){
        int curr = 0;
        int k = i;
        while (k % 2 == 0){
            curr++;
            k /= 2;
        }

        pow2[i] = curr + pow2[i - 1];
    }

    int total = pow2[n - 1];
    int ans = 0;

    for (int i = 0; i < n; i++){
        int now = total - pow2[i] - pow2[n - 1 - i];
        int a; cin >> a;
        if (now == 0){
            ans ^= a;
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