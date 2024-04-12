/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-11
 * Contest: CSES Problemset
 * Problem: Introductory - Tower of Hanoi
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<pair<int, int>> ans;

void hanoi(int n, int a, int b, int c){
    if (n == 1){
        ans.pb(make_pair(a, c));
        return;
    }

    hanoi(n - 1, a, c, b);
    ans.pb(make_pair(a, c));
    hanoi(n - 1, b, a, c);
}

void solve(){
    int n; cin >> n;

    ans = {};
    hanoi(n, 1, 2, 3);

    cout << ans.size() << endl;
    for (pair<int, int> move : ans){
        cout << move.first << " " << move.second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}