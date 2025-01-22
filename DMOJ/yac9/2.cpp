/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-20
 * Contest: DMOJ yac9
 * Problem: 2
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
    bool has = false;
    int ones = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        if (a > 1){
            has = true;
        } else {
            ones++;
        }
    }

    if (!has){
        cout << ((n % 2 == 0) ? "Mike":"Josh") << endl;
        return;
    }

    cout << ((ones % 2 == 0) ? "Mike":"Josh") << endl;
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