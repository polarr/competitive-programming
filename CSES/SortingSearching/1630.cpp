/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-11
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1630 - Tasks and Deadlines
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> tasks;
    ll total = 0;
    for (int i = 0; i < n; i++){
        int a, d;
        cin >> a >> d;
        total += d;
        tasks.pb(make_pair(a, d));
    }
    sort(tasks.begin(), tasks.end());
    ll sub = 0;
    for (ll i = 0; i < n; i++){
        sub += (n - i) * tasks[i].first;
    }

    cout << total - sub << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}