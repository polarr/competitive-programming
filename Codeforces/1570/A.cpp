/**
 * Solution by 1egend
 * Date: 9/18/2021
 * Contest: Codeforces Round 743
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
    string s; cin >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i){
        char c = s[i];
        if (c == '0'){
            continue;
        }

        ans += (c - '0') + 1;
        if (i == n - 1){
            --ans;
        }
    }

    cout << ans << endl;
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