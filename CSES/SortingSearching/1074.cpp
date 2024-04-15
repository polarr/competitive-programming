/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-13
 * Contest: CSES Problemset
 * Problem: 1074. Sorting and Searching - Stick Lengths
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

    vector<int> sticks;
    for (int i = 0; i < n; i++){
        int p; cin >> p;
        sticks.pb(p);
    }

    sort(sticks.begin(), sticks.end());

    int ma = sticks[floor((n - 1)/2.0)];
    int mb = sticks[ceil((n - 1)/2.0)];

    ll costa = 0, costb = 0;

    for (int i = 0; i < n; i++){
        costa += (ll)abs(sticks[i] - ma);
        costb += (ll)abs(sticks[i] - mb);
    }

    cout << min(costa, costb) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}