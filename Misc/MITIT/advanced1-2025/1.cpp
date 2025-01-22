/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-19
 * Contest: MITIT advanced1-2025
 * Problem: 1
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<ll> mult = {2, 3, 4, 5, 6, 7, 8, 9};

void solve(){
    ll n; cin >> n;

    map<ll, bool> valid;
    vector<ll> s = {1};

    valid[1] = true;
    ll l = 1;
    ll i = 0;

    while(i < l){
        for (int j = 0; j < mult.size(); j++){
            ll x = s[i] * mult[j];
            if (x > n || valid[x]){
                continue;
            }
            ll xx = x;
            while (xx > 0){
                ll t = xx % 10;
                if (t != 0 && x % t == 0 && valid[x/t]){
                    s.pb(x);
                    l++;
                    valid[x] = true;
                    break;
                }
                xx /= 10;
            }
        }
        i++;
    }

    cout << s.size() << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}