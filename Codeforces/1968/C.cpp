/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-02
 * Contest: 1968 - Codeforces Round 943
 * Problem: C
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
    ll curr = pow(10, 9);
    vector<ll> a;
    a.pb(curr);

    vector<int> arr;
    for (int i = 0; i < n - 1; i++){
        ll x; cin >> x;
        arr.pb(x);
    }
    for (int i = n - 2; i >= 0; i--){
        curr -= arr[i];
        a.pb(curr);
    }

    reverse(a.begin(), a.end());

    cout << a[0];
    for (int j = 1; j < n; j++){
        cout << " " << a[j];
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