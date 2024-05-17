/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-27
 * Contest: Codeforces Round 1966
 * Problem: A.
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> cards(101, 0);
    
    int can = false;
    for (int i = 0; i < n; i++){
        int c; cin >> c;
        cards[c]++;
        if (cards[c] >= k){
            can = true;
        }
    }

    if (can){
        cout << k - 1 << endl;
    } else {
        cout << n << endl;
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