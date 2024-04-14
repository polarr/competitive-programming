/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-13
 * Contest: CSES Problemset
 * Problem: 2183. Sorting and Searching - Missing Coin Sum
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

    vector<int> coins;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        coins.pb(x);
    }

    sort(coins.begin(), coins.end());

    ll sum = 0;
    for (int i = 0; i < n; i++){
        if ((ll)coins[i] > sum + 1){
            cout << sum + 1 << endl;
            return;
        }

        sum += (ll)coins[i];
    }

    cout << sum + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}