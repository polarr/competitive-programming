/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-12
 * Contest: Codeforces 2055
 * Problem: B
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
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    int need = 0;
    int give = INT_MAX;

    for (int i = 0; i < n; i++){
        if (b[i] > a[i]){
            if (need != 0){
                cout << "NO" << endl;
                return;
            }

            need = b[i] - a[i];
            continue;
        }
        give = min(give, a[i] - b[i]);
    }

    if (need == 0){
        cout << "YES" << endl; 
        return;
    }

    if (give != INT_MAX && give >= need){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
    return;

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