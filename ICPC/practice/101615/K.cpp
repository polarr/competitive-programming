/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-09
 * Contest: ICPC Practice Codeforces 101615
 * Problem: K
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

string add_string(string k, int m, int n){
    int kk = k[n] - '0';
    k[n] = to_string((kk + m) % 10);
    if (kk + m > 9){
        return add_string(k, 1, n - 1);
    }

    return k;
}

void solve(){
    /** NOTE: incomplete */
    string s; cin >> s;
    int k = s.size();
    s = "0" + s;
    vector<pair<string, string>> possible(h);

    for (int i = 1; k - i >= i; i++){
        int a = stoi(s[i]), b = stoi(s[k - i]);
        if (a > b){
            ll t = possible.size();
            for (ll j = 0; j < t; j++){
                possible.push(add_string(add_string(possible[j], a, i), a, k - i));
                possible[j] = add_string(add_string(possible[j], a, i), a, k - i);
            }
        } else if (b > a){

        }
        else {
            ll t = possible.size();
            for (ll j = 0; j < t; j++){
                possible[j] = add_string(add_string(possible[j], a, i), a, k - i);
            }
        }
        
    }


    int ans = INT_MAX;

    auto digit_sum = [&](string x){
        int ans = 0;
        for (int i = 0; i < x.size(); i++){
            ans += (x[i] - '0');
        }

        return ans;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}