/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-06
 * Contest: Baltic OI 2009
 * Problem: candy
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    vector<pii> ranges(n);
    rep(i, 0, n){
        int s, t; cin >> s >> t;
        ranges[i] = {s - t, -s - t};
    }

    sort(all(ranges));

    set<pii> candidates;
    vector<array<int, 3>> ans;
    int cnt = 0;
    rep(i, 0, n){
        auto j = candidates.lower_bound({-ranges[i].second, 0});
        int s = (ranges[i].first - ranges[i].second)/2, t = (-ranges[i].first - ranges[i].second)/2;

        if (j != candidates.end()){
            int c = (*j).second;
            candidates.erase(j);
            candidates.insert({-ranges[i].second, c});
            ans.pb({s, t, c});
        } else {
            cnt++;
            ans.pb({s, t, cnt});
            candidates.insert({-ranges[i].second, cnt});
        }
    }

    cout << cnt << endl;

    rep(i, 0, n){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl; 
    }

    
    
    // vector<array<int, 3>> ranges(n);
    // vector<array<int, 3>> r(n);
    // rep(i, 0, n){
    //     int s, t; cin >> s >> t;
    //     ranges[i] = {s - t, -s - t, i};
    //     r[i] = {s + t, s - t, i};
    // }

    // sort(all(ranges));
    // sort(all(r));

    // vector<bool> resolved(n, false);
    // vector<array<int, 3>> ans;

    // int cnt = 0;

    // int j = 0;
    // rep(i, 0, n){
    //     array<int, 3> range = ranges[i];
    //     if (resolved[range[2]]){
    //         continue;
    //     }

    //     cnt++;
        
    //     while(j < r.size() && r[j][0] <= -range[1]){
    //         resolved[r[j][2]] = true;
    //         int s = (r[j][0] + r[j][1])/2, t = (r[j][0] - r[j][1])/2;
    //         ans.pb({s, t, cnt});
    //         j++;
    //     }
    // }

    // cout << cnt << endl;

    // rep(i, 0, n){
    //     cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl; 
    // }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}