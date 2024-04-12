/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-10
 * Contest: CSES Problemset
 * Problem: 1623: Introductory - Apple Division
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    vector<ll> apples;

    ll sum = 0;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        sum += a;
        apples.pb(a);
    }

    ll ans = LLONG_MAX;

    for (ll i = 1; i < pow(2, n); i++){
        ll s = 0;
        for (ll j = 0; j < n; j++){
            if (i & (1<<j)){
                s += apples[j];
            }
        }

        ans = min(ans, abs(sum - 2 * s));
    }

    cout << ans << endl;

    /**
    sort(apples.begin(), apples.end(), greater<ll>());

    ll firstSum = 0;
    ll secondSum = 0;

    for (int i = 0; i < n; i++){
        if (firstSum < secondSum){
            firstSum += apples[i];
        } else {
            secondSum += apples[i];
        }
    }

    cout << abs(firstSum - secondSum) << endl;
    **/
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}