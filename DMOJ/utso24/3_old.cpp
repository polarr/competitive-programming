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

// wow actually nice combinatorics problem whoever made this
void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> pref0(n + 1, 0);
    vector<int> pref1 = pref0, suff0 = pref0, suff1 = pref0;
    vector<int> left0(n, -1);
    vector<int> right0(n, n);

    int ans = INT_MAX;

    for (int i = 0; i < n; i++){
        if (s[i] == '0'){
            pref0[i + 1] = 1 + pref0[i];
            pref1[i + 1] = pref1[i];
            left0[i] = i;
        } else {
            pref0[i + 1] = pref0[i];
            pref1[i + 1] = 1 + pref1[i];
            if (i > 0){
                left0[i] = left0[i - 1];
            }
        }

        if (s[n - 1 - i] == '0'){
            right0[n - 1 - i] = n - 1 - i;
            suff0[i + 1] = 1 + suff0[i];
            suff1[i + 1] = suff1[i];
        } else {
            right0[n - 1 - i] = right0[n - 1];
            suff0[i + 1] = suff0[i];
            suff1[i + 1] = 1 + suff1[i];
        }
    }

    if (pref0[n] <= k){
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++){
        if (s[i] != '1'){
            if (suff1[n - i] <= k){
                ans = min(ans, n - i);
            }
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--){
        if (s[i] != '1'){
            if (pref1[i + 1] <= k){
                ans = min(ans, i + 1);
            }
            break;
        }
    }

    for (int i = 0; i < n; i++){
        if (s[i] != '1'){
            continue;
        }

        int l = left0[i];
        int r = right0[i];

        int score = n - (l - r - 1);

        if (pref1[l + 1] + suff1[n - r] <= k){
            ans = min(ans, score);
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}