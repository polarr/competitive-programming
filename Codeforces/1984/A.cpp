/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-09
 * Contest: 1984 - Codeforces Global Round 26
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

    int same = 0;
    int last;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        if (i > 0 && last == a){
            same++;
        }
        last = a;
    }

    if (same == n - 1){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    cout << "RB";
    for (int i = 2; i < n; i++){
        cout << "R";
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