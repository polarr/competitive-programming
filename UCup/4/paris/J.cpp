/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-25
 * Contest: 
 * Problem: J
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
const int INF = 1e8;

void solve(){
    int n; cin >> n;

    vi arr(n);
    rep(i, 0, n){
        cin >> arr[i];
        --arr[i];
    }

    if (n == 1){
        cout << 1 << endl;
        return;
    }

    vi crit(n, -1);

    rep(i, 0, n){
        if (i == 0){
            crit[i] = 1;
            continue;
        }

        if (i == n - 1){
            if (arr[i] < arr[i - 1]) crit[i] = 1;
            continue;
        }

        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
            crit[i] = 0;
        }

        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]){
            crit[i] = 1;
        }
    }

    vi ans(n + 1);

    int curr = n;
    int nums = n;

    vector<vi> cost(n, 1);
    vector<vi> partitions(n);
    vector<vi> lis(n);
    vector<vi> lds(n);

    vi difference(n - 1);
    set<int> remain;
    set<pii> merges;

    rep(i, 0, n){
        partitions[i] = {arr[i]};
        remain.pb(i);
        lis[i] = {arr[i], INF};
        lds[i] = {arr[i], -INF};
    }


    auto calc_lis = [&](vi x, vi& y){
        // x = lis, y = actual numbers
        int m = sz(y);
        rep(i, 0, m){
            auto j = lower_bound(all(x), y[i]);

            if (*j == INF){
                x.pb(INF);
            }

            *j = y[i];
        }

        return x;
    };

    auto calc_lds = [&](vi x, vi& y){
        // x = lds, y = actual numbers in normal order
        int m = sz(y);
        for (int i = m - 1; i >= 0; i--){
            auto j = prev(upper_bound(x.rbegin(), x.rend(), y[i]));

            if (*j == -INF){
                x.pb(-INF);
            }

            *j = y[i];
        }

        return x;
    };

    auto merge = [&](int i, int j){
        if (sz(partitions[i]) > sz(partitions[j])){
            lis
        } else {

        }
    }

    rep(i, 0, n - 1){
        vi x = calc_lis(lis[i], partitions[i]);
        int ncost = sz(x) - 1;
        int diff = ncost - cost[i] - cost[i + 1];
        difference[i] = diff;
        merges.pb({diff, i});
    }

    ans[nums] = n;

    while (nums > 1){
        auto minLoss = merges.begin();
        auto [diff, i] = *minLoss;

        auto ii = remain.find(i);
        auto jj = next(ii);
        int j = *jj;

        // merge i and j

        curr += diff;

        rep(k, 0, partitions[j]){
            partitions[i].pb(partitions[j][k]);
        }

        cost[i] = cost[i] + cost[j] + diff;

        if (ii != remain.begin()){
            auto kk = prev(ii);
            int k = *kk;
            merges.erase({difference[k], k});
            
        }
        


        remain.erase(jj);

        nums--;
        ans[nums] = curr;
    }

    rep(i, 1, n + 1){
        cout << ans[i] << " ";
    }

    cout << endl;

    // int inc = 0;
    // int nums = 0;
    // rep(i, 0, n){
    //     if (i != 0 && crit[i] > crit[i - 1]){
    //         inc++;
    //     }

    //     if (crit[i] == 1){
    //         nums++;
    //     }
    // }

    // for (int i = n; i >= n - inc; i--){
    //     ans[i] = curr;
    // }

    // for (int i = n - inc - 1; i >= nums; i--){
    //     curr--;
    //     ans[i] = curr;
    // }
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