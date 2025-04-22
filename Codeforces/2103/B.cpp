/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-21
 * Contest: Codeforces 2103
 * Problem: B
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
    string s; cin >> s;
    vi arr(n + 1, 0);
    rep(i, 0, n){
        arr[i + 1] = s[i] - '0';
    }

    int a = 0, b = 0;
    int ans = n;
    rep(i, 1, n + 1){
        if (arr[i] != arr[i - 1]){
            ans++;

            if (arr[i] == 1){
                a++;
            } else {
                b++;
            }
        }
    }

    if (a > 1 || b > 1){
        ans -= 2;
    } else {
        if ((a > 0 && arr[n] == 0) || (b > 0 && arr[n] == 1)){
            ans--;
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