/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-11
 * Contest: CSES Problemset
 * Problem: Introductory - Digit Queries
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<ull> checkpoints = { 0 };

ull power (ull base, ull exponent){
    ull ans = 1;
    while(exponent--){
        ans *= base;
    }

    return ans;
}

void solve(){
    ull n;
    cin >> n;

    for (ull i = 1; i <= checkpoints.size(); i++){
        if (i == checkpoints.size() || n <= checkpoints[i]){
            // i digits
            ull num = max((ull)0, n - checkpoints[i - 1] - 1)/i;
            ull count = i - (n - checkpoints[i - 1]) % i;
            
            ull k = power((ull)10, i - 1) + num;
            if (count == i){
                cout << k % (ull)10 << endl;
                return;
            }

            cout << (k / (ull)power((ull)10, count)) % (ull)10 << endl;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ull num = 0;
    for (ull i = 1; i < 19; i++){
        num += i * 9 * power((ull)10, i - 1);
        checkpoints.pb(num);
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}