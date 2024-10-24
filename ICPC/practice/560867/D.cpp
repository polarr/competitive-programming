/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-23
 * Contest: ICPC Practice Codeforces 560867
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
    int n; cin >> n;

    vector<pair<int, int>> problems(n);
    for (int i = 0; i < n; i++){
        cin >> problems[i].first;
    }

    for (int i = 0; i < n; i++){
        cin >> problems[i].second;
    }

    // Weighted dijkstra, prefix sums, then just linear scan
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