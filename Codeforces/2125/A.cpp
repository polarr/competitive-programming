/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-22
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
    string s; cin >> s;
    string ans = "";
    int cnt = 0;
    rep(i, 0, s.size()){
        if (s[i] == 'T'){
            cnt++;
            continue;
        }

        ans += s[i];
    }

    rep(i, 0, cnt){
        ans += 'T';
    }

    reverse(all(ans));

    cout << ans << endl;
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