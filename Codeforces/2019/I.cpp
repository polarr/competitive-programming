
/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-28
 * Contest: Codeforces 2019
 * Problem: I
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
    vector<pair<int, int>> deadlines(n);
    for (int i = 0; i < n; i++){
        int d; cin >> d;
        deadlines[i] = make_pair(d, i);
    }

    sort(deadlines.begin(), deadlines.end());

    int ans_low = INT_MIN, ans_high = INT_MAX;
    int curr_low = INT_MAX, curr_high = INT_MIN;
    for (int i = 0; i < n; i++){
        pair<int, int> d = deadlines[i];
        ans_low = max(ans_low, d.second - d.first + 1);
        ans_high = min(ans_high, d.second + d.first - 1);

        curr_low = min(curr_low, d.second);
        curr_high = max(curr_high, d.second);

        if (curr_high - curr_low >= d.first){
            cout << 0 << endl;
            return;
        }
    }

    cout << max(0, ans_high - ans_low + 1) << endl;
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