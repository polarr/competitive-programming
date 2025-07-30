/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-30
 * Contest: 
 * Problem: A
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
    rep(i, 0, n) {
        cin >> a[i];
    }

    vector<bool> visited(n, false);
    int j = n - 1;
    rep(i, 0, k){
        if (visited[j]) break;
        visited[j] = true;
        if (a[j] > n) {
            cout << "No" << endl;
            return;
        }

        j += n - a[j];
        j %= n;
    }

    cout << "Yes" << endl;
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