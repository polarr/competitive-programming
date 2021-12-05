/**
 * Solution by 1egend
 * Date: 8/24/2021
 * Contest: Codeforces Round 740 (Div 2)
 * Problem: A - Simply Strange Sort
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
    vector <int> a;
    for (int i = 0; i < n; ++i){
        int b;
        cin >> b;
        a.pb(b);
    }

    int iters = 0;
    while (true){
        int sorted = true;
        for (int i = 0; i < n - 1; ++i){
            if (a[i] > a[i + 1]){
                sorted = false;
                break;
            }
        }

        if (sorted){
            break;
        }

        ++iters;
        int start = 1 - (iters % 2);
        for (int i = start; i < n - 1; i += 2){
            if (a[i] <= a[i + 1]){
                continue;
            }
            int dummy = a[i];
            a[i] = a[i + 1];
            a[i + 1] = dummy;
        }
    }
    cout << iters << endl;
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