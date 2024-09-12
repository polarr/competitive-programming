/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-11
 * Contest: 2008
 * Problem: E
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
    string s; cin >> s;

    vector<vector<int>> even(n, vector<int>(26, 0));
    vector<vector<int>> odd(n, vector<int>(26, 0));

    for (int i = 0; i < n; i++){
        int tt = s[i] - 'a';

        for (int t = 0; t < 26; t++){
            int ee = 0, oo = 0;
            if (t == tt && i % 2 == 1){
                ee++;
            } else if (t == tt){
                oo++;
            }

            if (i > 0){
                even[i][t] = even[i - 1][t] + ee;
                odd[i][t] = odd[i - 1][t] + oo;
            } else if (t == tt){
                odd[i][t] = 1;
            }
        }
    }

    if (n % 2 == 0){
        int evenMax = 0;
        int oddMax = 0;
        for (int i = 0; i < 26; i++){
            evenMax = max(evenMax, even[n - 1][i]);
            oddMax = max(oddMax, odd[n - 2][i]);
        }

        cout << n - evenMax - oddMax << endl;
        return;
    }

    auto findans = [&](int index){
        int evenMax = 0;
        int oddMax = 0;

        for (int i = 0; i < 26; i++){
            int ee = 0, oo = 0;
            if (index > 0){
                ee = even[index - 1][i];
                oo = odd[index - 1][i];
            }
            evenMax = max(evenMax, ee + odd[n - 1][i] - odd[index][i]);
            oddMax = max(oddMax, oo + even[n - 1][i] - even[index][i]);
        }

        return evenMax + oddMax;
    };

    int ans = 0;

    for (int i = 0; i < n; i++){
        ans = max(ans, findans(i));
    }

    cout << n - ans << endl;
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