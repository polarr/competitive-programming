/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-11
 * Contest: 2008
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
    int a, b; cin >> a >> b;

    if (a % 2 == 1){
        cout << "No" << endl;
        return;
    }

    if (b % 2 == 0 || b % 2 == 1 && a >= 2){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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