/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-21
 * Contest: Project Euler
 * Problem: 110
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 4e6 + 1;
const ll MOD = 1e9 + 7;

ll mx = 55954047656707200;
ll target = 8e6;
ll ans = mx;
vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

void recurse(int index, ll contrib, ll curr){
    if (index == -1){
        if (contrib >= target){
            ans = min(ans, curr);
        }
        return;
    }
    ll m = log(mx/curr)/log(primes[index]);
    ll p = 1;
    for (int i = 0; i <= m; i++){
        if (curr * p > mx){
            break;
        }
        recurse(index - 1, contrib * (2 * i + 1), curr * p);
        p *= primes[index];
    }
}

void solve(){

    // ll prod = target;

    // for (int i = 0; i < primes.size(); i++){
    //     prod *= log((long double)primes[i]);

    //     cout << i + 1 << endl;

    //     for (int j = 0; j <= i; j++){
    //         cout << primes[j] << "^" << (pow<long double>((long double)prod, (long double)(1.0)/(i + 1))/(long double)log((long double)primes[j]) - 1)/2<< "*";
    //     }
    //     cout << endl;
    // }

    recurse(primes.size() - 1, 1, 1);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}