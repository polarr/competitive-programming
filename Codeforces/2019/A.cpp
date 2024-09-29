/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-28
 * Contest: Codeforces 2019
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
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = a;
    }

    int ans = 0;
    int mx = 0;
    int k = 0;
    for (int i = 0; i < n; i+= 2){
        mx = max(mx, arr[i]);
        k++;
    }

    ans = mx + k;
    mx = 0, k = 0;
    for (int i = 1; i < n; i+= 2){
        mx = max(mx, arr[i]);
        k++;
    }

    ans = max(ans, mx + k);

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