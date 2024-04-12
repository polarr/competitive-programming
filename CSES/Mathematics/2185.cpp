/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-10
 * Contest: CSES Problemset
 * Problem: 2185: Mathematics - Prime Multiples
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    vector<ll> primes(k);
    for (ll i = 0; i < k; i++){
        ll a; cin >> a;
        primes[i] = a;
    }

    ll sum = 0;

    for (ll i = 1; i < pow(2, k); i++){
        ll add = n;
        bool pos = false;
        for (ll j = 0; j < k; j++){
            if (i & (1<<j)){
                pos = !pos;
                add /= primes[j];
            }
        }

        sum += add * (pos ? 1:-1);
    }

    cout << sum << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}