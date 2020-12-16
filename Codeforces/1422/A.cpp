/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << max<int>(1, max<int>(max<int>(a, b), c) - (a + b + c - max<int>(max<int>(a, b), c)) + 1) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        // cout << "Case #" << t  << ": " << endl;
        solve();
    }
    return 0;
}