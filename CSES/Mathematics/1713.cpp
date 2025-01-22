/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-21
 * Contest: CSES Problemset
 * Problem: 1713
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e6;
const ll MOD = 1e9 + 7;

vector<int> max_div(MAX_N + 1);
void prime_sieve() {
    for (int i = 2; i <= MAX_N; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= MAX_N; j += i) { max_div[j] = i; }
        }
    }
}

void solve(){
    int x; cin >> x;
    int ans = 1;
    while(x != 1){
        int p = max_div[x];
        int a = 1;
        while(x % p == 0){
            x /= p;
            a++;
        }
        ans *= a;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    prime_sieve();
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}