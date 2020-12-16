/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ull pw(int base, int exp){
    ull s = 1;
    for (int i = 0; i < exp; ++i){
        s *= base;
        s %= MOD;
    }
    return s;
}

void solve(){
    string x;
    cin >> x;
    ull ans = 0;
    for (int i = 0; i < x.length(); ++i){
        if (x[i] == '0'){
            continue;
        }
        int digit = x[i] - '0';
        int place = x.length() - i - 1;
        for (int n = 0; n < place; ++n){
            ans += (digit * pw(10, n) * (n + 1)) % MOD;
            ans %= MOD;
        }
        ans += (digit * pw(10, place) * (i * (i + 1)/2)) % MOD;
        ans %= MOD;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cout << "Case #" << t  << ": " << endl;
    solve();

    return 0;
}