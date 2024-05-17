/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-27
 * Contest: Codeforces Round 1966
 * Problem: C.
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
    vector<int> stones;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        stones.pb(a);
    }

    sort(stones.begin(), stones.end());

    vector<int> diff;
    diff.pb(stones[0]);

    for (int i = 1; i < n; i++){
        int d = stones[i] - stones[i - 1];
        if (d > 0){
            diff.pb(d);
        }
    }

    int ans = -1;
    for (int i = 0; i < diff.size(); i++){
        if (diff[i] > 1){
            ans = i % 2;
            break;
        }
    }

    if (ans > -1){
        cout << (ans == 0 ? "Alice":"Bob") << endl;
    } else {
        cout << ((diff.size() % 2 == 1) ? "Alice":"Bob") << endl;
    }
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