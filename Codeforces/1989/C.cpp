/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-27
 * Contest: 1989 - Educational Codeforces Round 167 (Rated for Div. 2)
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
    int n; cin >> n;

    vector<pair<int, int>> people(n, make_pair(0, 0));

    int mov1 = 0;
    int mov2 = 0;

    int add = 0;
    int sub = 0;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        people[i].first = x;
    }

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        people[i].second = x;
    }

    for (int i = 0; i < n; i++){
        int x = people[i].first;
        int y = people[i].second;

        if (x > y){
            mov1 += x;
            continue;
        }

        if (y > x){
            mov2 += y;
            continue;
        }

        if (x == 0 && y == 0){
            continue;
        }

        if (x == 1 && y == 1){
            add++;
            continue;
        }

        sub++;
    }

    if (mov2 > mov1){
        swap(mov1, mov2);
    }

    while (add > 0 || sub > 0){
        if (mov1 > mov2){
            if (sub > 0){
                mov1--;
                sub--;
                continue;
            }

            mov2++;
            add--;
            continue;
        }

        if (sub > 0){
            mov2--;
            sub--;
            continue;
        }

        mov1++;
        add--;
    }

    cout << min(mov1, mov2) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}