/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<ll> pos(3e5 + 1, 0);

void solve(){
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++){
        int r, c; cin >> r >> c;

        if (r == c){
            n--;
            continue;
        }

        n -= 2;
    }

    cout << pos[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pos[0] = 1;
    pos[1] = 1;
    pos[2] = 3;
    for (int i = 3; i < 3e5 + 1; i++){
        pos[i] = (pos[i - 1] + (ll)(i - 1) * 2 * pos[i - 2]) % MOD;
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}