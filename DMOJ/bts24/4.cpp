/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-14
 * Contest: DMOJ bts24
 * Problem: 4
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
    int n, k; cin >> n >> k;

    vi ranks(n);
    rep(i, 0, n) {
        int x; cin >> x;
        --x;
        ranks[x] = i;
    }

    vector<vi> arr(k, vi(n));
    rep(i, 0, n){
        int r = ranks[i];
        rep(j, 0, k){
            cin >> arr[j][r];
        }
    }

    // rep(i, 0, n){
    //     rep(j, 0, k){
    //         cout << arr[j][i] << " ";
    //     }

    //     cout << endl;
    // }

    vi cnt(k, 0);
    vector<vi> ups(n);
    rep(i, 0, k){
        rep(j, 1, n){
            if (arr[i][j] > arr[i][j - 1]){
                cnt[i]++;
                ups[j].pb(i);
            }
        }
    }

    vi ans;
    vector<bool> taken(n, false);
    taken[0] = true;
    
    set<int> good;
    rep(i, 0, k){
        if (cnt[i] == 0) good.insert(i);
    }

    while (sz(ans) < k) {
        if (good.empty()){
            cout << -1 << endl;
            return;
        }

        int i = *good.begin();
        good.erase(good.begin());
        ans.pb(i);

        rep(j, 1, n){
            if (taken[j]) continue;

            if (arr[i][j] != arr[i][j - 1]) {
                taken[j] = true;
                for (int k : ups[j]){
                    cnt[k]--;
                    if (cnt[k] == 0){
                        good.insert(k);
                    }
                }
            }
        }
    }

    for (int i : ans){
        cout << i + 1 << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}