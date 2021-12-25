/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
    string s;
    string p;
    cin >> s >> p;
    int countP = 1;
    int next = 0;
    for (int i = 1; i < p.length(); ++i){
        if (p[i] != p[i - 1]){
            int countS = 1;
            for (int n = next + 1; n < s.length(); ++n){
                if (s[n] != s[n - 1]){
                    next = n;
                    if (s[n - 1] == p[i - 1] && countS >= countP && (countS == countP || countS >= 3)){
                        //cout << s[n - 1] << " " << next << " " << endl;
                        break;
                    }
                    else{
                        //cout << s[n - 1] << " " << p[i - 1] << " " << countS << " "  << countP << endl;
                        cout << "false";
                        return;
                    }
                }
                countS ++;
            }
            countP = 0;
        }
        countP ++;
    }
    int countS = 0;
    for (int i = next; i < s.length(); ++i){
        if (s[i] != p[p.length() - 1]){
            cout << "false";
            return;
        }
        countS ++;
    }
    if (countS >= countP && (countS == countP || countS >= 3)){
        cout << "true";
    }
    else{
        cout << "false";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // cout << "Case #" << t  << ": " << endl;
    solve();
    return 0;
}