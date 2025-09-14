/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-14
 * Contest: Project Euler
 * Problem: 8
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
    int len = 13;
    string s;
    string c;
    while (cin >> c){
        s += c;
    }

    vi arr;
    rep(i, 0, s.size()){
        arr.pb(s[i] - '0');
    }

    ll ans = 0;

    rep(i, len - 1, arr.size()){
        ll prod = 1;
        rep(j, i - len + 1, i + 1){
            prod *= arr[j];
        }

        ans = max(ans, prod);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}