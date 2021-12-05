/**
 * Solution by 1egend
 * Date: 9/18/2021
 * Contest: Codeforces Round 743
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
    vector <vector<int>> book(n);
    vector <int> l;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        l.pb(x);
        for (int ii = 0; ii < x; ++ii){
            int p; cin >> p;
            book[i].pb(p);
        }
    }

    int r = 0;
    int a = 0;
    set <int> understood;
    while(a != n){
        int b = 0;
        for (int i = 0; i < n; ++i){
            if (understood.count(i + 1) != 0){
                continue;
            }
            set <int> temp = understood;
            for (int ii = 0; ii < l[i]; ++ii){
                temp.insert(book[i][ii]);
            }

            if (temp.size() == understood.size()){
                ++b;
                understood.insert(i + 1);
            }
        }
        if (b == 0){
            cout << -1 << endl;
            return;
        }
        a += b;
        ++r;
    }

    cout << r << endl;
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