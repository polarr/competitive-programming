/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-17
 * Contest: 1973 - Codeforces Round 945 (Div 2)
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
    int n; cin >> n;
    vector<int> arr(n);

    bool s = true;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = a;

        if (i > 0 && a != arr[i - 1]){
            s = false;
        }
    }

    if (s){
        cout << 1 << endl;
        return;
    }

    vector<vector<int>> same(n);
    same[0] = arr;

    for (int i = 2; i <= n; i++){
        s = true;
        for (int j = 0; j <= n - i; j++){
            same[i - 1].pb(same[i - 2][j] | arr[j + i - 1]);


            if (s && j > 0 && same[i - 1][j] != same[i - 1][j - 1]){
                s = false;
            }
        }

        if (s){
            cout << i << endl;
            return;
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