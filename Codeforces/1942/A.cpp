/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-03-30
 * Contest: Codeforces Round 1942
 * Problem: A. Farmer John's Challenge
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;

    if (n == k){
        cout << "1";
        for (int i = 1; i < n; i++){
            cout << " 1";
        }
    } else if (k == 1){
        cout << "1";
        for (int i = 2; i < n + 1; i++){
            cout << " " << i; 
        }
    } else {
        cout << -1;
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