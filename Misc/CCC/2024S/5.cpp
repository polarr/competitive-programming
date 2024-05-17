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

// average is same as entire chocolate average, very challenging dp & functional graphs?

void solve(){
    ll n;
    cin >> n;
    if (n > 2){
        cout << 1 << endl;
        return;
    }

    vector<double> top;
    vector<double> bottom;
    vector<double> all;

    double sum = 0;
    for (int i = 0; i < n; i++){
        double x;
        cin >> x;
        top.pb(x);
        all.pb(x);
        sum += x;
    }
    for (int i = 0; i < n; i++){
        if all
    }
    double avg = sum / (2 * n);
    int ans = 0;
    if (top[0] == avg){
        if (bottom[0] == )
    }
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