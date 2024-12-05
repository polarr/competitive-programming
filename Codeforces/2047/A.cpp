/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-02
 * Contest: Codeforces 2047
 * Problem: A
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

set<int> sq;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n; i++){
        curr += arr[i];
        if (sq.contains(curr)){
            ans++;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;

    for (int i = 1; i < 101; i+= 2){
        sq.insert(i * i);
    }
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}