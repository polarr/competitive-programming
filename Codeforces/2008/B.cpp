/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-11
 * Contest: 2008
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
    int n; string s; cin >> n >> s;

    if (sqrt(n) != floor(sqrt(n))){
        cout << "No" << endl;
        return;
    }

    int x = sqrt(n);

    for (int i = 0; i < x; i++){
        for (int j = 0; j < x; j++){
            char t = s[i * x + j];
            if (i == 0 || i == x - 1 || j == 0 || j == x - 1){
                if (t == '0'){
                    cout << "No" << endl;
                    return;
                }
            } else if (t == '1'){
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
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