/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-01
 * Contest: Codeforces Round 1117
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int x, y; cin >> x >> y;
    int a, b; cin >> a >> b;
    a -= x; b -= y;
    int n; string s; cin >> n >> s;

    vector<pair<int, int>> wind(n + 1);

    pair<int, int> curr = {0, 0};
    wind[0] = curr;

    for (int i = 0; i < n; i++){
        char w = s[i];

        if (w == 'R'){
            curr.first++;
        } else if (w == 'L'){
            curr.first--;
        } else if (w == 'U'){
            curr.second++;
        } else if (w == 'D'){
            curr.second--;
        }

        wind[i + 1] = curr;
    }

    ll l = 0, h = 2e15 + 1;

    while(l < h){
        ll mid = (l + h)/2;

        ll k = mid / n;
        ll r = mid % n;

        pair<ll, ll> d = {curr.first * k + wind[r].first, curr.second * k + wind[r].second};

        if (abs(d.first - a) + abs(d.second - b) <= mid){
            h = mid;
        } else {
            l = mid + 1;
        }

        //cout << l << " " << h << endl;
    }

    if (l == 2e15 + 1){
        cout << -1 << endl;
        return;
    }

    cout << l << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}