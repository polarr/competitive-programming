/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-21
 * Contest: DMOJ ahscc2
 * Problem: 4
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
    int n, m; cin >> n >> m;

    if (n < m - 1){
        cout << -1 << endl;
        return;
    }

    rep(i, 1, m - 1){
        cout << n + i << " " << i + 1 << endl;
    }

    int rem = n - (m - 2);

    rep(i, 1, rem){
        // m - 2 + i
        cout << n + 1 << " " << m - 2 + i + 1 << endl;
    }

    cout << n + m - 1 << " " << n + m << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}