/**
 * Solution by 1egend (polarity.sh)
 * Date: 2023-01-08
 * Contest: DMOJ UACC 1
 * Problem: P5 - A Lab Report
**/

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
    int past;
    cin >> past;
    vector <ll> diff;
    ll sum = 0;
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        diff.pb(x - past);
        sum += x - past;
        past = x;
    }

    n--;
    ll a = (ll)floor(sum * 1.0/n);
    ll b = (ll)ceil(sum * 1.0/n);
    ll a1 = 0;
    ll a2 = 0;
    ll b1 = 0;
    ll b2 = 0;
    for (int i = 0; i < n; i++){
        a1 += max((ll)0, diff[i] - a);
        a2 += max((ll)0, a - diff[i]);
        b1 += max((ll)0, diff[i] - b);
        b2 += max((ll)0, b - diff[i]);
    }
    cout << min(max(a1, a2), max(b1, b2));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}