/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-22
 * Contest: DMOJ othscc4
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
    string s; cin >> s;
    int n = s.size();
    bool good = true;
    int k;
    for (int i = n - 1; i > 0; i--){
        if (s[i] != '0'){
            k = i;
            good = false;
            break;
        }
    }

    if (good){
        cout << 0 << endl;
        return;
    }

    string ans = "";
    bool leading = true;

    rep(i, 1, k){
        if (s[i] != '9') leading = false;
        if (!leading){
            ans += to_string('9' - s[i]);
        }
    }

    ans += to_string('9' - s[k] + 1);
    rep(i, k + 1, n){
        ans += "0";
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}