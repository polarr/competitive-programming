/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-31
 * Contest: CSES Problemset
 * Problem: 1142
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
    stack<pair<int, int>> s;

    vector<int> arr(n);
    vector<int> left(n);

    ll ans = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++){
        int a = arr[i];

        int x = -1;

        while(!s.empty()){
            pair<int, int> t = s.top();

            if (t.first < a){
                x = t.second;
                break;
            }

            s.pop();
        }

        s.push({a, i});
        
        left[i] = x;
    }

    s = {};

    for (int i = n - 1; i >= 0; i--){
        int a = arr[i];

        int x = n;

        while(!s.empty()){
            pair<int, int> t = s.top();

            if (t.first < a){
                x = t.second;
                break;
            }

            s.pop();
        }

        s.push({a, i});

        ans = max(ans, (ll)(x - left[i] - 1) * (ll)a);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}