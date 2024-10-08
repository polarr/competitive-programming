/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-05
 * Contest: ICPC NAQ 2024
 * Problem: E
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
    vector<int> v(51, 0);
    for (int i = 0; i < 50 * n; i++){
        int x; cin >> x;
        v[x]++;
    }

    vector<int> ans;

    for (int i = 1; i < 51; i++){
        if (v[i] > 2 * n){
            ans.pb(i);
        }
    }

    if (ans.size() == 0){
        cout << -1 << endl;
        return;
    }

    cout << ans[0];
    for (int i = 1; i < ans.size(); i++){
        cout << " " << ans[i];
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}