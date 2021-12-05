/**
 * Solution by 1egend
 * Date: 9/18/2021
 * Contest: Codeforces Round 743
 * Problem: D
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
    vector <int> a;

    int c = 0;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        if (x == 1){
            ++c;
        }
        a.pb(x);
    }

    while(c != 0){
        int b;
        for (int i = 0; i < n - 2; ++i){
            if ()
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