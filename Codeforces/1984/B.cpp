/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-09
 * Contest: 1984 - Codeforces Global Round 26
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
    ll x; cin >> x;

    vector<ll> base_ten;
    while (x > 0){
        base_ten.pb(x % 10);

        x /= 10;
    }

    if (base_ten[base_ten.size() - 1] != 1){
        cout << "NO" << endl;
        return;
    }

    if (base_ten[0] == 9){
        cout << "NO" << endl;
        return;
    }

    for (int i = 1; i < base_ten.size() - 1; i++){
        if (base_ten[i] == 0){
            cout << "NO" << endl;

            return;
        }
    }

    cout << "YES" << endl;
    return;
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