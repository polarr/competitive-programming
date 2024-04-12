/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-10
 * Contest: CSES Problemset
 * Problem: 2205: Introductory - Gray Code
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<string> gray_code(int n){
    if (n == 1){
        return vector<string>{"0", "1"};
    }

    vector<string> prev = gray_code(n - 1);
    vector<string> ans;

    for (int i = 0; i < prev.size(); i++){
        if (i % 2){
            ans.pb("0" + prev[i]);
            ans.pb("1" + prev[i]);
            continue;
        }
        
        ans.pb("1" + prev[i]);
        ans.pb("0" + prev[i]);
    }

    return ans;
}

void solve(){
    int n; cin >> n;

    vector<string> ans = gray_code(n);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}