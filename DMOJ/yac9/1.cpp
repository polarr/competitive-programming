/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-20
 * Contest: DMOJ yac9
 * Problem: 1
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> pos(n);
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++){
        int s; cin >> s;
        --s;
        a[i] = s;
        pos[s] = i;
    }

    for (int i = 0; i < n; i++){
        int s; cin >> s;
        --s;
        b[i] = s;
    }

    int curr = -10;
    int ans = 0;

    for (int i = 0; i < n; i++){
        if (pos[b[i]] != curr + 1){
            ans++;
        }
        
        curr = pos[b[i]];
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}