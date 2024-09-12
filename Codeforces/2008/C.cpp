/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-11
 * Contest: 2008
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
    ll l, r; cin >> l >> r;
    ll d = r - l;

    if (d == 0){
        cout << 1 << endl;
        return;
    }

    cout << floor((1.0 + 2 * sqrt(0.5 + 2.0 * d))/2.0) << endl;
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