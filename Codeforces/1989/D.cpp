/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-27
 * Contest: 1989 - Educational Codeforces Round 167 (Rated for Div. 2)
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> a;
    vector<pair<int, int>> greedy;
    vector<pair<int, int>> select;

    //forge
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a.pb(x);
    }

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        greedy.pb(make_pair(a[i] - x, a[i]));
    }

    sort(greedy.begin(), greedy.end());

    int mn = INT_MAX;
    for (int i = 0; i < n; i++){
        if (greedy[i].second >= mn){
            continue;
        }

        mn = greedy[i].second;
        select.pb(make_pair(mn, greedy[i].first));
    }

    reverse(select.begin(), select.end());

    vector<ll> dp(10e6 + 1, 0);

    dp[0] = 0;

    int curr = 0;

    for (int i = select[0].first; i < dp.size(); i++){
        if (curr < select.size() - 1 && i >= select[curr + 1].first){
            curr++;
        }

        dp[i] = dp[i - select[curr].second] + 2;
    }

    ll ans = 0;
    for (int i = 0; i < m; i++){
        int x; cin >> x;

        if (x > 10e6){
            ll calc = (ll)ceil((x - select[select.size() - 1].first) * 1.0 / select[select.size() - 1].second);
            ans += 2 * calc;
            x -= calc * select[select.size() - 1].second;
        }

        ans += dp[x];
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}