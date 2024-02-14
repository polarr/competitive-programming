/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-10
 * Contest: AtCoder Beginner Contest 214
 * Problem: E - Packing Under Range Regulations
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
    vector<pair<int, int>> ranges;
    set<int> starts;
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        starts.insert(l);
        ranges.pb(make_pair(l, r));
    }

    sort(ranges.begin(), ranges.end());

    int left = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++){
        if ()
        if (left > ranges[i].second){
            cout << "No" << endl;
            return;
        }

        int newLeft = max(left, ranges[i].first);
        left = newLeft + 1;
    }

    cout << "Yes" << endl;
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