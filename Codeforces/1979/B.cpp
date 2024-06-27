/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-06
 * Contest: 1979 - Codeforces Round 951 (Div. 2)
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<bool> base_2(int x){
    vector<bool> ans;

    while (x > 0){
        if (x % 2 == 1){
            ans.pb(true);
        } else {
            ans.pb(false);
        }

        x /= 2;
    }

    return ans;
}

void solve(){
    int x, y; cin >> x >> y;

    vector<bool> xx = base_2(x);
    vector<bool> yy = base_2(y);

    if (xx.size() < yy.size()){
        swap(xx, yy);
    }

    int same = 0;
    for (int i = 0; i < xx.size(); i++){
        if (i < yy.size() && xx[i] == yy[i] || i >= yy.size() && !xx[i]){
            same++;
        } else {
            break;
        }
    }

    cout << (ll)pow(2LL, (ll)same) << endl;
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