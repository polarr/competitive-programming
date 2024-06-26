/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    string x, y;
    cin >> x >> y;

    int k = 0;
    for (int i = 0; i < x.size(); i++){
        int xx = x[i] - '0';
        int yy = y[i] - '0';
        if (k == 0 && xx != yy){
            k = 1;
            if (yy > xx){
                swap(x[i], y[i]);
            }
            continue;
        }

        if (k == 1 && xx > yy){
            swap(x[i], y[i]);
        }
    }

    cout << x << endl << y << endl;
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