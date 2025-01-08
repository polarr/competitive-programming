/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-03
 * Contest: DMOJ utso24
 * Problem: 4
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

    vector<ll> pow2(34, 1);
    for (ll i = 1; i < 33; i++){
        pow2[i] = pow2[i - 1] * 2;
    }

    pow2[33] = (ll)pow(10, 10);

    for (int i = 0; i < n; i++){
        if (i % 34 == 33){
            cout << pow2[33] << " ";
        }
        else if (i <= 32){
            cout << pow2[(32 - i) % 34] << " ";
        } else if (i >= n - (n % 34)){
            cout << pow2[i % 34] << " ";
        } else {
            cout << pow2[i % 34] << " ";
        }
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}