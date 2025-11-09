#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
#define rep(i, a, b) for(int i = (a); i < (b); ++i)

void solve(){
    int n; cin >> n;

    bool div5 = true, div2 = true;
    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
        int x = arr[i];
        if (x % 5 != 0){
            div5 = false;
        }

        if (x % 2 != 0){
            div2 = false;
        }
    }

    if (div5 || div2){
        cout << n << endl;
        return;
    }

    cout << 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}