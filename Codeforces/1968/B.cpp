/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-02
 * Contest: 1968 - Codeforces Round 943
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
    int n, m;
    cin >> n >> m;
    string a, b; cin >> a >> b;
    
    int j = 0;
    for (int i = 0; i < m; i++){
        if (b[i] == a[j]){
            j++;
            if (j == n){
                break;
            }
        }
    }

    cout << j << endl;
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