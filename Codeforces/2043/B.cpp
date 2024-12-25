/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-24
 * Contest: Codeforces 2043
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, d; cin >> n >> d;

    cout << 1 << " ";

    if (d % 3 == 0 || n >= 3){
        cout << 3 << " ";
    }
    
    if (d == 5){
        cout << 5 << " ";
    }

    if (n >= 3 || d == 7){
        cout << 7 << " ";
    }

    if ((d % 3 == 0 && n >= 3) || d == 9 || n >= 6){
        cout << 9 << " ";
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