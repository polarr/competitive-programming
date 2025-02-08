/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-06
 * Contest: Baltic OI 2010
 * Problem: pcb
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
    vector<pii> c;
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        c.pb({a, b});
    }

    sort(c.begin(), c.end());

    set<int> s;
    int ans = 1;
    s.insert(c[0].second);
    rep(i, 1, n){
        int x = c[i].second;
        if (x < *s.begin()){
            ans++;
            s.insert(x);
        } else {
            auto idx = prev(s.upper_bound(x));
            s.erase(idx);
            s.insert(x);
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