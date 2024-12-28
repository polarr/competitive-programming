/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-28
 * Contest: Codeforces 2053
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> ranges(n);
    vector<int> singletons(2 * n + 1, 0);
    vector<int> doubletons(2 * n + 1, 0);
    for (int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        ranges[i] = {l, r};
        if (l == r){
            singletons[l]++;
        }
    }

    for (int i = 0; i < 2 * n + 1; i++){
        if (singletons[i] > 1){
            doubletons[i] = 1;
        }

        if (singletons[i] > 0){
            singletons[i] = 1;
        }
    }

    vector<int> prefix(2 * n + 2, 0);
    for (int i = 1; i < 2 * n + 1; i++){
        prefix[i] = prefix[i - 1] + singletons[i];
    }

    string ans = "";

    for (int i = 0; i < n; i++){
        int l = ranges[i].first, r = ranges[i].second;
        if ((r == l && doubletons[l] == 1) || (r != l && prefix[r] - prefix[l - 1] == r - l + 1)){
            ans += "0";
        } else {
            ans += "1";
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