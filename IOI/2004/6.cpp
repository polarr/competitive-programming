/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-14
 * Contest: IOI 2004
 * Problem: 6 - Empodia
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

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<pair<int, int>> mn;
    vector<int> s(n, -1);
    stack<pair<int, int>> nse;

    int empodio = -1;

    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++){
        while (!mn.empty() && mn.back().first > arr[i]){
            mn.pop_back();
        }

        while(!nse.empty()){
            if (nse.top().first > arr[i]){
                s[i] = nse.top().second;
                break;
            }

            nse.pop();
        }

        mn.pb({arr[i], i});
        nse.push({arr[i], i});

        for (int j = mn.size() - 2; j >= 0; j--){
            auto &[val, idx] = mn[j];

            if (idx <= empodio || idx <= s[i]){
                break;
            }

            if (val - idx == arr[i] - i){
                ans.pb({idx, i});
                empodio = idx;
                break;
            }
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}