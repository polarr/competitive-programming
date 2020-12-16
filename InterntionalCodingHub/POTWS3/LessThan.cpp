/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int x;
    cin >> x;
    vector <int> a;
    for (int i = 0; i < x; ++i){
        int k;
        cin >> k;
        a.push_back(k);
    }
    int ans = 0;
    for (int i = 1; i < x; ++i){
        int n = a[i];
        for (int z = 0; z < i; ++z){
            if (a[z] < n){
                ans ++;
            }
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}