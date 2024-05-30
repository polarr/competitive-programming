/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-30
 * Contest: Codeforces 1976 - Educational Codeforces Round 166 (Rated for Div. 2)
 * Problem: B
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
    vector<ll> arr1;
    vector<ll> arr2;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        arr1.pb(a);
    }

    for (int i = 0; i < n + 1; i++){
        ll b; cin >> b;
        arr2.pb(b);
    }

    ll target = arr2[n];
    ll ans = 0;
    ll best = LLONG_MAX;

    for (int i = 0; i < n; i++){
        ll first = arr1[i];
        ll second = arr2[i];
        ans += (ll)abs(first - second);
        if ((target >= first && target <= second) || (target >= second && target <= first)){
            best = 0;
            continue;
        }

        best = min(best, min((ll)abs(target - first), (ll)abs(target - second)));
    }

    cout << (ans + best + 1) << endl;
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