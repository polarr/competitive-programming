/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-07
 * Contest: CSES Problemset
 * Problem: 2413
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;

    vl a(MAX_N), b(MAX_N);

    a[1] = 1;
    b[1] = 1;

    ll sum = 2;

    rep(i, 2, MAX_N){
        a[i] += sum;
        a[i] ++;
        a[i] %= MOD;
        
        b[i] += 4 * b[i - 1] + a[i - 1];
        b[i] %= MOD;

        sum += a[i];
        sum %= MOD;
        sum += b[i];
        sum %= MOD;
    }
    
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        int n; cin >> n;
        cout << (a[n] + b[n]) % MOD << endl;
    }
    return 0;
}