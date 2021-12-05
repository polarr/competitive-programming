/**
 * Solution by 1egend
 * Date: 7/12/2021
 * Contest: Codeforces Round 576 (Div 3)
 * Problem: E. Boxers
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

    vector <int> boxers;
    for (int i = 0; i < n; ++i){
        static int t;
        cin >> t;

        boxers.pb(t);
    }

    sort(boxers.begin(), boxers.end());
    set <int> weights{0};
    int current = 0;
    for (int i = 0; i < n; ++i){
        int boxer = boxers[i];
        if (current > boxer){
            continue;
        }

        if (weights.count(boxer - 1) == 0){
            weights.insert(boxer - 1);
            current = boxer - 1;
            continue;
        }

        if (weights.count(boxer) == 0){
            weights.insert(boxer);
            current = boxer;
            continue;
        }

        if (weights.count(boxer + 1) == 0){
            weights.insert(boxer + 1);
            current = boxer + 1;
            continue;
        }
    }

    cout << weights.size() - 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}