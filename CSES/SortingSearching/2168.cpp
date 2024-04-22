/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-17
 * Contest: CSES Problemset
 * Problem: 2168. Sorting and Searching - Nested Ranges Check
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

    vector<tuple<int, int, int>> ranges;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        ranges.pb(make_tuple(x, -y, i));
    }

    sort(ranges.begin(), ranges.end());

    vector<int> minRight;

    int mnRight = INT_MAX;
    for (int i = n - 1; i >= 0; i--){
        tuple<int, int, int> range = ranges[i];
        mnRight = min(mnRight, -get<1>(range));
        minRight.pb(mnRight);

        // cout << mnRight << endl;
    }

    int mx = 0;
    vector<pair<int, int>> ans(n, pair<int, int>(0, 0));

    // check if contained
    for (int i = 0; i < n; i++){
        tuple<int, int, int> range = ranges[i];

        if (mx >= -get<1>(range)){
            ans[get<2>(range)].second = 1;
        }

        mx = max(mx, -get<1>(range));
    }

    // check if contains
    for (int i = 0; i < n - 1; i++){
        if (minRight[n - 2 - i] <= -get<1>(ranges[i])){
            ans[get<2>(ranges[i])].first = 1;
        }
    }

    cout << ans[0].first;
    for (int i = 1; i < n; i++){
        cout << " " << ans[i].first;
    }

    cout << endl;

    cout << ans[0].second;
    for (int i = 1; i < n; i++){
        cout << " " << ans[i].second;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}