/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-25
 * Contest: Project Euler
 * Problem: 108
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e7;
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
    prime_sieve();
    ll target = 2000;
    for (int j = 1; j < MAX_N + 1; j++){
        int jj = j;
        ll divs = 1;
        while(jj != 1){
            ll p = max_div[jj];
            ll e = 0;
            while (jj % p == 0){
                jj /= p;
                e++;
            }

            divs *= (2 * e + 1);
        }

        if (divs > target){
            cout << j << endl;
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}