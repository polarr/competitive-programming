/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-28
 * Contest: NAQ 2023
 * Problem: A
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k, c; cin >> n >> k >> c;
    vector<pair<int, int>> teams;
    vector<bool> ans(n, false);
    unordered_map<int, int> schools;

    for (int i = 0; i < n; i++){
        int t, s; cin >> t >> s;
        teams.pb(make_pair(t, s));
    }

    int kk = 0;

    for (int i = 0; i < n; i++){
        if (kk >= k){
            break;
        }

        pair<int, int> team = teams[i];
        if (schools[team.second] >= c){
            continue;
        }

        schools[team.second]++;
        ans[i] = true;
        kk++;
    }

    for (int i = 0; i < n; i++){
        if (kk >= k){
            break;
        }

        pair<int, int> team = teams[i];
        if (ans[i]){
            continue;
        }

        ans[i] = true;
        kk++;
    }

    for (int i = 0; i < n; i++){
        if (ans[i]){
            cout << teams[i].first << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}