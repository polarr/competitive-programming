/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-17
 * Contest: 1973 - Codeforces Round 945 (Div 2)
 * Problem: C
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

    vector<int> ans(n, 0);
    vector<int> optimal(n + 1);
    vector<int> pos(n + 1);
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = a;
    }

    optimal[0] = 0;
    optimal[1] = arr[0];
    for (int i = 2; i < n + 1; i++){
        optimal[i] = max(arr[i - 1] + optimal[i - 2], optimal[i - 1]);
    }

    int t = n;
    vector<int> indices;
    while(t > 1){
        if (arr[t - 1] + optimal[t - 2] > optimal[t - 1]){
            indices.pb(t - 1);
            t -= 2;
        } else if (optimal[t - 1] > arr[t - 1] + optimal[t - 2]){
            t--;
            continue;
        } else {
            if (arr[t - 1] > arr[t - 2]){
                indices.pb(t - 1);
                t -= 2;
            } else {
                t--;
            }
        }
    }

    if (t == 1){
        indices.pb(t);
    }

    vector<pair<int, int>> vals;

    for (int i : indices){
        vals.pb(make_pair(arr[i], indices[i]));
    }

    sort(vals.begin(), vals.end());

    for (int i = 0; i < vals.size(); i++){
        ans[vals[i].second] = n - i;
    }

    int temp = n - vals.size();

    vals = {};
    
    for (int i = 0; i < n; i++){
        if (ans[i] > 0){
            continue;
        }

        vals.pb(make_pair(arr[i], indices[i]));
    }

    sort(vals.begin(), vals.end());

    for (int i = 0; i < vals.size(); i++){
        ans[vals[i].second] = temp - i;
    }

    cout << ans[0];
    for (int i = 1; i < n; i++){
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