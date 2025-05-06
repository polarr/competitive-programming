/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-05
 * Contest: 
 * Problem: B
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
    int n, k; cin >> n >> k;
    vi a(n);
    ll sum = 0;
    rep(i, 0, n){
        cin >> a[i];
        sum += (ll) a[i];
    }

    sort(all(a));

    int eq = 0, ex = 0;
    rep(i, 0, n){
        if (a[i] - a[0] == k + 1){
            eq++;
        }

        if (a[i] - a[0] > k + 1){
            ex++;
        }
    }

    if (ex > 0 || eq > 1){
        cout << "Jerry" << endl;
        return;
    }

    if (sum % 2 == 1){
        cout << "Tom" << endl;
    } else {
        cout << "Jerry" << endl;
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