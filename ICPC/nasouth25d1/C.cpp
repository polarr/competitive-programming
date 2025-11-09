#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define pb push_back

void solve(){
    int r, c; cin >> r >> c;
    string s; cin >> s;
    vi arr;
    int curr = 0;
    rep(i, 0, r + c - 2){
        if (i == 0 || s[i] == s[i - 1]){
            curr++;
        } else {
            arr.pb(curr);
            curr = 1;
        }
    }

    if (curr > 0){
        arr.pb(curr);
    }

    int n = arr.size();
    vector<array<int, 3>> dp(n + 1, {0, 0, 0});
    dp[n] = {0, 0, 0};
    vi cnt(2, 0);
    for (int i = n - 1; i >= 0; i--){
        int x = arr[i];

        int cs = i % 2;
        int ot = 1 - cs;
        dp[i][cs] = min(cnt[ot], x + dp[i + 1][cs]);
        dp[i][ot] = dp[i + 1][ot];
        dp[i][2] = min(x + dp[i + 1][2], cnt[ot] + dp[i + 1][ot]);

        cnt[cs] += x;
    }

    cout << dp[0][2] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}