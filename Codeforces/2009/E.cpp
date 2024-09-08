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

void solve(){
    ll n, k; cin >> n >> k;

    double c = sqrt(n * n + (2 * k - 1) * n + (2 * k - 1) * (2 * k - 1)/2) * sqrt(2) - (2 * k - 1);

    ll a = min(n, (ll) ceil(c/2));
    ll b = min(n, (ll) floor(c/2));

    cout << min(abs(n * k + n * (n - 1)/2 + a - 2 * a * k - a * a), abs(n * k + n * (n - 1)/2 + b - 2 * b * k - b * b));
    cout << endl;
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