/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    float k;
    cin >> n >> k;
    vector <int> arr;
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 1; i < n; ++i){
        ans += floor((k - arr[i])/arr[0]);
    }
    cout << ans << endl;
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