/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-17
 * Contest: 1973 - Codeforces Round 945 (Div 2)
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
    int a, b, c; cin >> a >> b >> c;

    if ((a + b + c) % 2 == 1){
        cout << -1 << endl;
        return;
    }

    cout << min((a + b + c)/2, a + b) << endl;
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