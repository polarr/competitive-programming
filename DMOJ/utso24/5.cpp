/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-03
 * Contest: DMOJ utso24
 * Problem: 5
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    vector<pair<int, int>> pre(n + 1);
    vector<bool> op(n);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = a % 2;
    }

    op[0] = 0;

    for (int i = 1; i < n; i++){
        char c; cin >> c;
        if (c == '+'){
            op[i] = 0;
        } else {
            op[i] = 1;
        }
    }

    pre[0] = {0, -1};

    int curr = 1;

    for (int i = 1; i <= n; i++){
        int o = op[i];
        int po = op[i - 1];

        if (po == 0){
            int mult = -1;
            int add = arr[i - 1];
            if (o == 1){
                add = 0;
                mult = arr[i - 1];
            }

            pre[i] = {(pre[i - 1].first + add) % 2, mult};
        } else {
            if (o == 0){
                pre[i] = {pre[i - 1].first + pre[i - 1].second * arr[i - 1], -1};
            } else {
                pre[i] = {pre[i - 1].first, pre[i - 1].second * arr[i - 1]};
            }
        }
    }

    for (int i = 0; i < q; i++){
        char t; int l, r; cin >> t >> l >> r;
        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}