/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-02
 * Contest: CSES Problemset
 * Problem: 3420
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

    map<int, int> lst;

    ll ans = 0;
    int l = -1;
    rep(i, 0, n){
        int x; cin >> x;
        if (lst.contains(x)){
            l = max(l, lst[x]);
        }
        
        lst[x] = i;

        ans += i - l;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}