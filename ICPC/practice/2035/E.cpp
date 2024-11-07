/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-06
 * Contest: ICPC Practice Codeforces 2035
 * Problem: E
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll x, y, z, k; cin >> x >> y >> z >> k;

    /** IDEA: If you do increase damage n times with no k restriction, ceil(z/n) can take on log(z) values, so you can binary search those values in O((log n)^2), then each value you can easily compute minimum n and thus min answer. k makes it complicated, if k large then you can add a factor iterating by how many k's used, perhaps if k small do something else. */

    auto cost = [&](ll n){
        return max(0LL, (ll)ceil(z * 1.0/n) * y);
    };

    ll ans = LLONG_MAX;
    ll c = x;
    ll n = 1;
    int curr = 1;
    while (z > 0 && n < ceil(z * 1.0/2) + 1){
        if (curr == k){
            z -= n;
            c += y;
            ans = min(ans, c + cost(n));
            curr = 0;
            continue;
        }

        //cout << n << " " << z << " " << c << " " << cost(n) << endl;
        ans = min(ans, c + cost(n));

        n++;
        c += x;
        curr++;
    }

    cout << ans << endl;
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