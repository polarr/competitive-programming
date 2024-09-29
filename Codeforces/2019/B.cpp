/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-28
 * Contest: Codeforces 2019
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
    ll n, q; cin >> n >> q;
    vector<ll> contains(n);
    unordered_map<ll, ll> ans;
    vector<ll> points(n);

    for (ll i = 0; i < n; i++){
        ll x; cin >> x;
        points[i] = x;
    }

    ans[n - 1]++; // last point

    for (ll i = 0; i < n - 1; i++){
        ll p = points[i];
        // point itself
        ans[n - 1 + i * (n - i - 1)]++;
        // points until next point
        ans[(i + 1) * (n - i - 1)] += (points[i + 1] - p - 1);
    }

    for (ll i = 0; i < q; i++){
        ll q; cin >> q;
        cout << ans[q] << " ";
    }

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