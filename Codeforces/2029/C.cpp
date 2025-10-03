/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-02
 * Contest: Codeforces 2029
 * Problem: C
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
    vi arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    int ans = 0;
    vi num(n + 1, 0);
    rep(i, 1, n + 1){
        num[i] = num[i - 1];
        if (num[i] > arr[i - 1]){
            num[i]--;
        } else if (num[i] < arr[i - 1]){
            num[i]++;
        }

        if (i != n){
            ans = max(ans, num[i]);
        }
    }

    int curr = num[1], mx = 0;
    rep(i, 2, n + 1){
        curr = max(curr, mx);
        if (curr > arr[i - 1]){
            curr--;
        } else if (curr < arr[i - 1]){
            curr++;
        }
        mx = max(mx, num[i - 1]);
    }

    ans = max(ans, curr);
    if (ans == n){
        ans--;
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