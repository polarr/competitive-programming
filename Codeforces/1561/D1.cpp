/**
 * Solution by 1egend
 * Date: 8/24/2021
 * Contest: Codeforces Round 740 (Div 2)
 * Problem: D1 - Up the Strip Simplfied
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vector <int> strip(n + 1, 1);
    int s = 1;
    for (int x = 2; x <= n; ++x){
        int cell = s;
        /**
         * strip[x] += s;
        strip[x] %= m;
         *  for (int y = 1; y <= x - 1; ++y){
                cell += strip[x - y];
                cell %= m;
            } 
            for (int z = 2 * x; z <= n; ++z){
            strip[z] += cell;
            strip[z] %= m;
        }
        **/
        for (int z = 2; z <= sqrt(x); ++z){
            cell += strip[floor((double)(x)/z)];
            cell %= m;
        }
        for (int n = 1; n < sqrt(x); ++n){
            ull zl = floor(double(x)/n) - max<int>(floor((double)(x)/(n + 1)), floor(sqrt(x)));
            cell += (zl * strip[n]) % m;
            cell %= m;
        }
        strip[x] = cell;
        s += cell;
        s %= m;
    }
    cout << strip[n] % m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}