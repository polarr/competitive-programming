/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-06
 * Contest: 1979 - Codeforces Round 951 (Div. 2)
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

    vector<int> arr;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr.pb(a);
    }

    int smallest = INT_MAX;
    for (int i = 0; i < n - 1; i++){
        smallest = min(smallest, max(arr[i], arr[i + 1]));
    }

    cout << smallest - 1 << endl;
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