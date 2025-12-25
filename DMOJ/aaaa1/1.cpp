/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-24
 * Contest: aaaa1
 * Problem: 1
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
    int even = 0, odd = 0;
    int n; cin >> n;
    rep(i, 0, n) {
        int x; cin >> x;
        if (x % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    if (n % 2 == 1) {
        cout << "Steven" << endl;
        return;
    }

    if (odd > n/2) {
        cout << "Todd" << endl;
        return;
    }
    
    cout << "Steven" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}