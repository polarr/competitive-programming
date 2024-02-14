/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-01
 * Contest: Happy Hackers Programming Challenge 1
 * Problem: P1 - Yielding the Longest Substring
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
    string s;
    cin >> s;

    int mx = 0;
    char comp = s[0];
    int curr = 0;
    int tempCurr = 0;
    int endSwap = 0;
    bool canSwap = true;
    for (int i = 1; i < n; i++){
        if (s[i] != comp){
            endSwap = 1;
            if (canSwap){
                if (i < n - 1 && s[i + 1] == s[i - 1]){
                    canSwap = false;
                    tempCurr = i;
                    continue;
                }

                mx = max(mx, i - curr + 1);
                curr = i;
                comp = s[i];
            } else {
                mx = max(mx, i - curr);
                curr = tempCurr;
                comp = s[curr];
                canSwap = true;
                i = curr;
            }
        }
    }

    if (canSwap){
        mx = max(mx, n - curr + endSwap);
    } else {
        mx = max(mx, n - curr);
    }

    cout << mx << endl;
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