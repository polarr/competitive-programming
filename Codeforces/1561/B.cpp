/**
 * Solution by 1egend
 * Date: 8/24/2021
 * Contest: Codeforces Round 740 (Div 2)
 * Problem: B - 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int a, b; cin >> a >> b;
    int total = a + b;
    set <int> ans;
    if (total % 2 == 0){
        int n = total/2;
        for (int i = max<int>(0, a - n); i <= min<int>(n, a); ++i){
            ans.insert(2 * i + n - a);
        }
        cout << ans.size() << endl;
        for (int i : ans){
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    int n = (total - 1)/2;
    int m = (total + 1)/2;
    for (int i = max<int>(0, a - m); i <= min<int>(n, a); ++i){
        ans.insert(2 * i + m - a);
    }

    n = (total + 1)/2;
    m = (total - 1)/2;
    for (int i = max<int>(0, a - m); i <= min<int>(n, a); ++i){
        ans.insert(2 * i + m - a);
    }
    cout << ans.size() << endl;
    for (int i : ans){
        cout << i << " ";
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