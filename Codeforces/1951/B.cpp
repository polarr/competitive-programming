/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-06
 * Contest: Codeforces 1951 - Global Round 25
 * Problem: B. Battle Cows
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    k--;

    vector<int> rating;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        rating.pb(a);
    }

    vector<int> better;
    for (int i = 0; i <= k; i++){
        if (rating[i] >= rating[k]){
            better.pb(i);
        }
    }

    if (better.size() >= 2 && better[0] > 0 && better[0] - 1 < better[1] - better[0]){
        swap(rating[better[0]], rating[k]);
        k = better[0];
    } else {
        swap(rating[0], rating[k]);
        k = 0;
    }

    int wins = (k == 0 ? 0 : 1);
    for (int i = k + 1; i < n; i++){
        if (rating[k] > rating[i]){
            wins++;
        } else {
            break;
        }
    } 

    cout << wins << endl;
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