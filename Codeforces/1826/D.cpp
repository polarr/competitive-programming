/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-08
 * Contest: Codeforces 1826
 * Problem: D. Running Miles
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

    vector <int> sights;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        sights.pb(x);
    }

    vector <int> maxl(n, 0);
    vector <int> maxr(n, 0);
    maxl[0] = sights[0] + 1;
    maxr[n - 1] = sights[n - 1] - n;
    for (int l = 1; l < n - 2; l++){
        maxl[l] = max(maxl[l - 1], sights[l] + l + 1);
    }
    for (int r = n - 2; r > 1; r--){
        maxr[r] = max(maxr[r + 1], sights[r] - r - 1);
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++){
        ans = max(ans, sights[i] + maxl[i - 1] + maxr[i + 1]);
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