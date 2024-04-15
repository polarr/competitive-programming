/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-13
 * Contest: CSES Problemset
 * Problem: 2216. Sorting and Searching - Collecting Numbers
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

    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr[x] = i;
    }
    
    int ans = 1;
    for (int i = 1; i < n; i++){
        if (arr[i + 1] < arr[i]){
            ans++;
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