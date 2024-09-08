/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k, q; cin >> n >> k >> q;

    vector<int> root;
    unordered_map<int, int> cnt;
    set<int> cm;
    unordered_map<int, int> cmc;
    vector<int> ans(n + 1, 0);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        root.pb(x - (i + 1) + n);
    }

    for (int i = 0; i < k; i++){
        cnt[root[i]]++;
    }

    for (int i = 0; i < cnt.size(); i++){
        cm.insert(cnt[i]);
        cmc[cnt[i]]++;
    }

    ans[0] = k - *(--cm.end());

    // multiset does not pass...

    auto update_cm = [&] (int i, int x) {
        cmc[cnt[root[i]]]--;
        if (cmc[cnt[root[i]]] == 0){
            cm.erase(cnt[root[i]]);
        }
        cnt[root[i]] += x;
        cmc[cnt[root[i]]]++;
        if (cmc[cnt[root[i]]] == 1){
            cm.insert(cnt[root[i]]);
        }
    };

    for (int i = k; i < n; i++){
        update_cm(i - k, -1);
        update_cm(i, 1);

        ans[i - k + 1] = k - *prev(cm.end());
    }

    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;

        cout << ans[l - 1] << endl;
    }
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