/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-21
 * Contest: 
 * Problem: C
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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll n, m; cin >> n >> m;
    if (m < n || m > (n * (n + 1))/2){
        cout << -1 << endl;
        return;
    }

    if (m == n){
        cout << 1 << endl;
        rep(i, 1, n){
            cout << i << " " << i + 1 << endl;
        }
        return;
    }

    for (ll i = 1; i < n; i++){
        ll mn = (n - i + 1) * i + (i * (i - 1))/2;
        ll diff = m - mn;
        if (diff > n - i) continue;

        cout << i + diff << endl;
        cout << i + diff << " " << i << endl;
        ll last = i;
        for (ll j = n; j >= 1; j--){
            if (j != i + diff && j != i){
                cout << last << " " << j << endl;
                last = j;
            }
        }
        break;
    }
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