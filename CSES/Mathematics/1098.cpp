/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-02
 * Contest: 
 * Problem: 1098
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
    int n; cin >> n;
    int curr = 0;
    rep(i, 0, n) {
        int x; cin >> x;
        curr ^= x;
    }

    curr %= 4;

    if (curr == 0) {
        cout << "second\n";
        return;
    }
    cout << "first\n";
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