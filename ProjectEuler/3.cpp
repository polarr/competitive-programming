/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-14
 * Contest: Project Euler
 * Problem: 3
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
    ll n; cin >> n;
    ll rt = sqrt(n);
    ll ans = 0;
    rep(i, 2, rt + 1){
        if (n % i == 0){
            ans = max(ans, (ll)i);
            while (n % i == 0){
                n /= i;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}