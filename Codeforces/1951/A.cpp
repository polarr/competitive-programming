/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-06
 * Contest: Codeforces 1951 - Global Round 25
 * Problem: A. Dual Trigger
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    int count = 0;
    int adj = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            count++;
            if (i >= 1 && s[i - 1] == '1'){
                adj++;
            }
        }
    }

    if (count % 2 == 0 && !(count == 2 && adj == 1)){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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