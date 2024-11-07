/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-13
 * Contest: AtCoder abc365
 * Problem: E
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
    vector<ull> arr(n);
    ull total = 0;
    for (int i = 0; i < n; i++){
        ull x; cin >> x;
        total ^= x;
        arr[i] = x;
    }

    vector<ull> prefix(n + 1, 0);
    vector<ull> suffix(n + 1, 0);
    ull sums = 0;
    ull currs = 0;
    for (int i = 1; i < n + 1; i++){
        sums ^= arr[i - 1];
        currs ^= arr[n - i];
        prefix[i] = sums;
        suffix[n - i] = currs + suffix[n + 1 - i];
    }

    ull ans = 0;

    for (int i = 0; i < n - 1; i++){
        ans += (total ^ prefix[i]) ^ suffix[i + 2];
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}