/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-06
 * Contest: Codeforces 2134
 * Problem: E
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

int query(string s, int x){
    cout << s << " " << x << endl;
    if (s == "throw"){
        int ans; cin >> ans;
        return ans;
    }

    return 0;
}

void solve(){
    int n; cin >> n;

    vi boxes(n + 1), dp(n + 1);
    vi ans(n + 1);

    boxes[n] = 3 - query("throw", n - 1);
    ans[n - 1] = boxes[n];
    query("swap", n - 1);
    boxes[n - 1] = 3 - query("throw", n - 1);
    ans[n] = boxes[n - 1];

    int one = n;

    if (boxes[n - 1] == 1){
        one = n - 1;
    }

    dp[n] = 1;
    dp[n - 1] = 1 + (int)(boxes[n - 1] == 1);

    bool skip = false;

    for (int i = n - 2; i >= 1; i--){
        if (skip){
            dp[i] = 1 + dp[i + boxes[i]];
            if (boxes[i] == 1) one = i;
            skip = false;
            continue;
        }

        int rem = one - i;

        if (rem % 2 == 1){
            dp[i] = query("throw", i);
            if (dp[i] == 1 + dp[i + 1]){
                boxes[i] = 1;
                ans[i] = 1;
                one = i;
            } else {
                boxes[i] = 2;
                ans[i] = 2;
            }
        } else {
            if (i > 1){
                skip = true;
                dp[i - 1] = query("throw", i - 1);
                if (dp[i - 1] == 1 + dp[i + 1]){
                    boxes[i - 1] = 2;
                    ans[i - 1] = 2;
                } else {
                    boxes[i - 1] = 1;
                    ans[i - 1] = 1;
                }
            }

            query("swap", i);
            swap(boxes[i], boxes[i + 1]);
            dp[i + 1] = query("throw", i + 1);
            if (dp[i + 1] == 1 + dp[i + 2]){
                boxes[i + 1] = 1;
                ans[i] = 1;
                one = i + 1;
            } else {
                boxes[i + 1] = 2;
                ans[i] = 2;
            }

            dp[i] = 1 + dp[i + boxes[i]];
        }
    }

    cout << "!";

    rep(i, 1, n + 1){
        cout << " " << ans[i];
    }

    cout << endl;
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