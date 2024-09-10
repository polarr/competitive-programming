/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-08
 * Contest: DMOJ bts24 - Back to School '24
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
    int n, m;
    cin >> n >> m;

    vector<int> points(n);
    vector<int> students(n);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        points[i] = x;
    }

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        students[i] = x;
    }

    vector<ll> cs(m);
    int curr = 0;
    for (int i = 0; i < n; i++){
        ll p = points[i];

        cs[curr] += p;
        curr += students[i];
        
        if (curr >= m){
            cs[0] += p;
        }

        curr %= m;

        cs[curr] -= p;
    }

    ll s = 0;

    s += cs[0];
    cout << s;

    for (int i = 1; i < m; i++){
        s += cs[i];
        cout << " " << s;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}