/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-12
 * Contest: ICPC Practice Codeforces 1912
 * Problem: L
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
    int loaf = 0, bread = 0;
    string s; cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'L'){
            loaf++;
        } else {
            bread++;
        }
    }

    int l = 0, b = 0;
    for (int i = 0; i < s.length() - 1; i++){
        if (s[i] == 'L'){
            l++;
        } else {
            b++;
        }

        if (l != loaf - l && b != bread - b){
            cout << i + 1 << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}