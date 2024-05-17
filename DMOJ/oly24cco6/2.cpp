/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-10
 * Contest: Olympiads School CCO Training Contest 6
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, l, m; cin >> n >> l >> m;
    vector<bitset<5000>> arr = {bitset<5000>(0)};
    // vector<bitset<5000>> target;

    for (int i = 0; i < n; i++){
        bitset<5000> a; cin >> a;
        arr.pb(a);
    }

    for (int i = 0; i < m; i++){
        bitset<5000> b; cin >> b;
        for (int j = n - 1; j >= 0; --j){
            bitset<5000> a = arr[j];

            if (a != b){
                
            }
        }
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}