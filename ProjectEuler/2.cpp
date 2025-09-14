/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-14
 * Contest: Project Euler
 * Problem: 2
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
    int a = 0, b = 1;
    ll ans = 0;
    while (a + b <= 4e6){
        if ((a + b) % 2 == 0){
            ans += a + b;
        }

        int c = a + b;

        a = b;
        b = c;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}