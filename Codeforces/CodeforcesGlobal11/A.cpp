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
    int sum = 0;
    for (int i = 0; i < x; ++i){
        int k;
        cin >> k;
        sum += k;
        a.push_back(k);
    }
    if (sum == 0){
        cout << "NO" << endl;
    }
    else if (sum > 0){
        cout << "YES" << endl;
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for (int i = 0; i < x; ++i){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "YES" << endl;
        sort(a.begin(), a.end());
        for (int i = 0; i < x; ++i){
            cout << a[i] << " ";
        }
        cout << endl;
    }
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