/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-03
 * Contest: DMOJ utso24
 * Problem: 4
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const ll MAX_N = 1e10;
const ll MOD = 1e9 + 7;

vector<ll> ans;

void rec(int l, int r, ll mx, bool s, bool p){
    if (s){
        if (l == r){
            ans[l] = 1;
            return;
        }
        int mid = (l + r)/2;

        ans[mid] = MAX_N;

        ll remain = ans[mid] - 1;

        ll a = remain/2;
        ll b = remain/2;
        if (remain % 2 == 1){
            b++;
        }

        rec(l, mid - 1, a, false, true);
        rec(mid + 1, r, b, false, false);
        return;
    }
    if (r < l){
        return;
    }
    if (l == r){
        ans[l] = 1;
        return;
    }

    int mid = (l + r)/2;
    ll remain;

    if (mx % 2 == 0){
        ans[mid] = mx/2;
        remain = mx/2 - 1;
    } else {
        ans[mid] = mx/2 + 1;
        remain = mx/2;
    }

    if (remain < l - r){
        for (int i = l; i <= r; i++){
            if (i == mid){
                continue;
            }
            ans[i] = 1;
            mx--;
        }
        ans[mid] = mx; 
        return;
    }

    ll a = remain/2;
    ll b = remain/2;
    if (remain % 2 == 1){
        b++;
    }

    rec(l, mid - 1, a, false, true);
    rec(mid + 1, r, b, false, false);
}

void solve(){
    int n; cin >> n;

    ans = vector<ll>(n);

    rec(0, n - 1, LLONG_MAX, true, true);

    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}