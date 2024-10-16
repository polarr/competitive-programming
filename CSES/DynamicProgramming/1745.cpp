/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-15
 * Contest: CSES Problemset - Dynamic Programming
 * Problem: 1745
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

    vector<int> coins(n);
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<vector<bool>> can(n + 1, vector<bool>(1e5 + 1, false));

    for (int i = 0; i < n + 1; i++){
        can[i][0] = true;
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < 1e5 + 1; j++){
            can[i][j] = can[i - 1][j] || (coins[i - 1] <= j && can[i - 1][j - coins[i - 1]]);
        }
    }

    int count = 0;
    for (int i = 1; i < 1e5 + 1; i++){
        if (can[n][i]){
            count++;
        }
    }

    cout << count << endl;

    for (int i = 1; i < 1e5 + 1; i++){
        if (can[n][i]){
            cout << i << " ";
        }
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}