/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-14
 * Contest: CSES Problemset - Additional Problems
 * Problem: 1743
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

    int total = n;
    vector<int> count(26, 0);
    for (int i = 0; i < n; i++){
        int x = s[i] - 'A';
        count[x]++;
    }

    string ans = "";
    int past = -1;

    for (int i = 0; i < n; i++){
        int mx = 0;
        char mxChar;
        for (char j = 'A'; j <= 'Z'; j++){
            int x = j - 'A';

            if (count[x] > mx){
                mx = count[x];
                mxChar = j;
            }
        }
        if (2 * mx - 1 > total){
            break;
        }
        if (2 * mx - 1 == total){
            count[mxChar - 'A']--;
            total--;
            ans += mxChar;
            past = mxChar - 'A';
            continue;
        }
        for (char j = 'A'; j <= 'Z'; j++){
            int x = j - 'A';
            if (past != x && count[x] > 0){
                count[x]--;
                total--;
                ans += j;
                past = x;
                break;
            }
        }
    }

    if (ans.length() != n){
        cout << ans << endl;
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}