/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-19
 * Contest: USACO 2024 February Contest
 * Problem: P1. Target Practice II
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, x;
    cin >> n >> x;

    ll upper = LLONG_MIN;
    ll lower = LLONG_MAX;

    vector<ll> left;
    vector<pair<ll, ll>> top;
    vector<pair<ll, ll>> bottom;

    for (int i = 0; i < n; i++){
        ll y, yy, xx;
        cin >> y >> yy >> xx;
        left.pb(y);
        left.pb(yy);
        top.pb(make_pair(xx, yy));
        bottom.pb(make_pair(xx, y));
    }

    vector<ll> pos;
    vector<ll> neg;

    for (int i = 0; i < 4 * n; i++){
        ll s;
        cin >> s;
        if (s > 0){
            pos.pb(s);
        } else {
            neg.pb(s);
        }
    }

    if (pos.size() < n || neg.size() < n){
        cout << -1 << endl;
        return;
    }

    // flattest slopes first
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater{});

    // assign n flattest slopes to maximize y-intercept of bottom right
    // maximize highest slopes first
    for (int i = n - 1; i >= 0; i--){
        ll s = pos[i];

        ll maxY = bottom[0].second - s * bottom[0].first;
        int t = 0;
        for (int j = 1; j < bottom.size(); j++){
            pair<ll, ll> coord = bottom[j];
            ll y = coord.second - s * coord.first;
            if (y > maxY || (y == maxY && coord.first < bottom[t].first)){
                maxY = y;
                t = j;
            }
        }

        lower = min(lower, maxY);
        bottom.erase(bottom.begin() + t);
    }

    // assign n flattest slopes to minimize y-intercept of top right
    // minimize highest slopes first
    for (int i = n - 1; i >= 0; i--){
        ll s = neg[i];

        ll minY = top[0].second - s * top[0].first;
        int t = 0;
        for (int j = 1; j < top.size(); j++){
            pair<ll, ll> coord = top[j];
            ll y = coord.second - s * coord.first;
            if (y < minY || (y == minY && coord.first < top[t].first)){
                minY = y;
                t = j;
            }
        }

        upper = max(upper, minY);
        top.erase(top.begin() + t);
    }

    pos.erase(pos.begin(), pos.begin() + n);
    neg.erase(neg.begin(), neg.begin() + n);

    reverse(pos.begin(), pos.end());
    // pos in descending order
    // neg is ascending order

    // left in descending
    sort(left.begin(), left.end(), greater{});
    for (int i = 0; i < 2 * n; i++){
        ll y;
        if (i < pos.size()){
            // assign highest left with highest sloped pos
            y = left[i] - pos[i] * x;
        } else {
            int ii = i - pos.size();
            // assign highest left with flattest sloped neg
            y = left[i] - neg[ii] * x;
        }

        upper = max(upper, y);
        lower = min(lower, y);
    }

    cout << upper - lower << endl;
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