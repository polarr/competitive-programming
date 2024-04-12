/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-06
 * Contest: Codeforces 1951 - Global Round 25
 * Problem: C. Ticket Hoarding
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> tickets;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        tickets.pb(a);
    }

    sort(tickets.begin(), tickets.end());
    ll money = 0;
    for (int i = 0; i < n; i++){
        ll buy = min(m, k);
        money += tickets[i] * buy + (k - buy) * buy;
        k -= buy;
        if (k == 0){
            break;
        }
    }

    cout << money << endl;
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