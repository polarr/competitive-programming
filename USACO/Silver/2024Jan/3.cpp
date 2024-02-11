/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-29
 * Contest: USACO 2024 Jan Contest
 * Problem: Silver P3. Cowlendar
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

    ll mn = LLONG_MAX;
    
    vector<ll> days;
    for (int i = 0; i < n; i++){
        ll a;
        cin >> a;

        mn = min(mn, a);
        days.pb(a);
    }

    ll ans = 0;
    for (ll l = 1; l <= (mn/4); l++){
        unordered_set<ll> residues;
        int success = true;
        for (int i = 0; i < n; i++){
            int day = days[i];
            residues.insert(day % l);
            if (residues.size() > 3){
                success = false;
                break;
            }
        }

        if (success){
            ans += l;
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}