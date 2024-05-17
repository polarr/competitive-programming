/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-27
 * Contest: Codeforces Round 1966
 * Problem: D.
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

ll max_two(ll x){
    ll ans = 1;
    while(2 * ans <= x){
        ans *= 2;
    }

    return ans;
}

void solve(){
    ll n, k; cin >> n >> k;
    
    vector<ll> sequence;
    ll t = max_two(k);
    sequence.pb(k + 1);
    sequence.pb(k - t);
    ll p = 1;
    if (p != t){
        sequence.pb(p);
    } else {
        sequence.pb(3 * p);
    }

    while (p < n){
        p *= 2;
        if (p != t){
            sequence.pb(p);
        } else {
            sequence.pb(3 * p);
        }
    }

    cout << sequence.size() << endl;
    cout << sequence[0];
    for (int i = 1; i < sequence.size(); i++){
        cout << " " << sequence[i];
    }
    cout << endl;
    /**
    ll p = 1;
    ll sum = 0;
    if (k != 1){
        sequence.pb(p);
        sum += p;
        while (sum + 2 * p < k){
            p *= 2;
            sum += p;
            sequence.pb(p);
        }

        sequence.pb(k - sum - 1);
    }

    sequence.pb(k + 1);
    sum = 2 * k;

    while(sum < n){
        sequence.pb(sum + 1);
        sequence.pb(sum + 1 + k);
        sum += sum + 2 * k - 1;

    }

    cout << sequence.size() << endl;
    cout << sequence[0];
    for (int i = 1; i < sequence.size(); i++){
        cout << " " << sequence[i];
    }
    cout << endl;
    **/
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