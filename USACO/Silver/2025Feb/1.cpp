/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-21
 * Contest: USACO 2025 Feb Silver
 * Problem: 1
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
    vi arr(n);
    multiset<int> rem;
    rep(i, 0, n){
        cin >> arr[i];
        rem.insert(arr[i]);
    }

    bool used = false;
    vi store;
    vi ans;

    auto solverem = [&](int x = 0){
        multiset<int> temp;
        rep(j, 0, store.size()){
            temp.insert(store[j]);
        }

        rep(j, 0, store.size()){
            if (*prev(temp.end()) < x){
                break;
            }
            
            if (store[j] == *prev(temp.end())){
                ans.pb(store[j]);
                used = true;
            }

            temp.erase(temp.find(store[j]));
        }
    };

    rep(i, 0, n){
        if (arr[i] == *prev(rem.end())){
            rem.erase(rem.find(arr[i]));
            ans.pb(arr[i]);
            if (!used){
                if (rem.empty()){
                    solverem();
                } else {
                    solverem(*prev(rem.end()));
                }
            }
            store = {};
        } else {
            rem.erase(rem.find(arr[i]));
            store.pb(arr[i]);
        }
    }

    cout << ans[0];

    rep(i, 1, ans.size()){
        cout << " " << ans[i];
    }

    cout << endl;
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