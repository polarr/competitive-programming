/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-09
 * Contest: ICPC 2024 PACNW Practice
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
    int n, d; cin >> n >> d;

    set<int> pitch;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        pitch.insert(x);
    }

    int ans = 0;
    auto i = pitch.begin(); 
    while(i != pitch.end()){
        i = pitch.upper_bound(*i + d);
        ans++;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}