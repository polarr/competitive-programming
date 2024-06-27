/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-06
 * Contest: 1979 - Codeforces Round 951 (Div. 2)
 * Problem: C
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
    int l = 1;
    for (int i = 0; i < n; i++){
        int k; cin >> k;

        arr.pb(k);

        l = lcm(l, k);
    }

    int sum = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++){
        ans.pb(l/arr[i]);
        sum += l/arr[i];
        if (sum >= l){
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    cout << endl;
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