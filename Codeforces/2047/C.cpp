/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-02
 * Contest: Codeforces 2047
 * Problem: C
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
    vector<pair<int, int>> cols(n, {0, 0});
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        cols[i].first = a;
    }
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        cols[i].second = a;
    }

    int sum = 0;
    int largestOther = -INT_MAX;
    for (int i = 0; i < n; i++){
        sum += max(cols[i].first, cols[i].second);
        largestOther = max(largestOther, min(cols[i].first, cols[i].second));
    }

    cout << sum + largestOther << endl;
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