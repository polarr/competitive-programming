/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-13
 * Contest: CSES Problemset
 * Problem: 1619. Sorting and Searching - Restaurant Customers
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

    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        times.pb(make_pair(a, 1));
        times.pb(make_pair(b, 2));
    }

    int people = 0;
    int ans = 0;

    sort(times.begin(), times.end());

    for (int i = 0; i < 2 * n; i++){
        pair<int, int> time = times[i];

        if (time.second == 1){
            people++;
        } else {
            people--;
        }

        ans = max(ans, people);
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}