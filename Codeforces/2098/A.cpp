/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-03
 * Contest: Codeforces 2098
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
    vi arr(10, 0);
    rep(i, 0, 10){
        int x = s[i] - '0';
        arr[x]++;
    }

    string ans = "";
    rep(i, 0, 10){
        int least = 9 - i;
        rep(j, least, 10){
            if (arr[j] > 0){
                ans += to_string(j);
                arr[j]--;
                break;
            }
        }
    }

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