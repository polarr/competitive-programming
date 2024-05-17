/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-02
 * Contest: 1968 - Codeforces Round 943
 * Problem: E
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
    if (n == 2){
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 2 << endl;
    } else if (n == 3){
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 3 << " " << 2 << endl;
    } else {
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 4 << " " << 2 << endl;
        cout << 4 << " " << 4 << endl;
        for (int i = 5; i <= n; i++){
            cout << i << " " << i << endl;
        }
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