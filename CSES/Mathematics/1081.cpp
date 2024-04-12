/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-03-28
 * Contest: CSES Problemset / Mathematics
 * Problem: 1081 - Common Divisors
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;

    vector <int> arr(MAX_N, 0);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[x]++;
    }

    for (int gcd = MAX_N - 1; gcd > 0; gcd--){
        int div = 0;
        for (int gcd_mult = gcd; gcd_mult < MAX_N; gcd_mult += gcd){
            div += arr[gcd_mult];
        }

        if (div >= 2){
            cout << gcd << endl;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}