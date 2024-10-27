/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-25
 * Contest: Atcoder abc295
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    string s; cin >> s;
    int n = s.length();

    ull ans = 0;
    bitset<10> curr = 0;
    vector<int> past(1024, 0);

    past[curr.to_ullong()]++;

    for (int i = 0; i < n; i++){
        int c = s[i] - '0';
        curr[c].flip();
        ans += past[curr.to_ullong()];
        past[curr.to_ullong()]++;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}