#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> hats;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        hats.pb(h);
    }

    int ans = 0;

    for (int i = 0; i < n/2; i++){
        if (hats[i] == hats[i + n/2]){
            ans += 2;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}