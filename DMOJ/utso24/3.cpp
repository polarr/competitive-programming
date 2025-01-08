/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-03
 * Contest: DMOJ utso24
 * Problem: 3
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;

    int curr = 0;
    int last = -1;

    string s; cin >> s;
    s += "0";
    
    vector<pair<int, int>> groups;

    int ones = 0;
    int odd = 0;
    int even = 0;

    bool win = k > 0;

    for (int i = 0; i < n + 1; i++){
        int c = s[i] - '0';

        if (c == 1){
            ones++;
        }

        if (c != curr){
            int l = i - last;
            
            if (curr == 1){
                if (l % 2 == 0){
                    even++;
                } else {
                    odd++;
                    win = true;
                }

                if (l >= 4){
                    win = true;
                }
            } else {
                if (l >= 2){
                    win = true;
                }
            }

            last = i;
            curr = c;
        }
    }

    int l = n + 1 - last;
    if (curr == 1){
        if (l % 2 == 0){
            even++;
        } else {
            odd++;
            win = true;
        }
    } else {
        if (l >= 2){
            win = true;
        }
    }

    if (!win){
        cout << -1 << endl;
        return;
    }



    while (ones + even > 0 && k > 0){
        if (even > 0){
            even--;
            ones--;
            k--;
            continue;
        }

        ones--;
        k--;
    }

    ll ans = ones + 2 * even;

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}