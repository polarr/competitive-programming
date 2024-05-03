/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-02
 * Contest: 1968 - Codeforces Round 943
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<ll> p;
vector<ll> a;

ll findmax(ll pos, ll start, bool notinit){
    if (notinit && (pos == start)){
        return 0;
    }
    return max(a[pos - 1], findmax(p[pos - 1], start, true));
}

ll dp (ll pos, ll moves, ll mx){
    if (moves == 0){
        return 0LL;
    }

    if (a[pos - 1] == mx){
        return mx * moves;
    }

    return max(a[pos - 1] * moves, a[pos - 1] + dp(p[pos - 1], moves - 1, mx));
}

void solve(){
    int n; ll k, b, s;
    cin >> n >> k >> b >> s;

    p = vector<ll>(n);
    a = vector<ll>(n);

    for (int i = 0; i < n; i++){
        ll per; cin >> per;
        p[i] = per;
    }

    for (int i = 0; i < n; i++){
        ll arr; cin >> arr;
        a[i] = arr;
    }

    ll bm = findmax(b, b, false);
    ll sm = findmax(s, s, false);

    ll bb = dp(b, k, bm);
    ll ss = dp(s, k, sm);

    if (bb > ss){
        cout << "Bodya" << endl;
    } else if (ss > bb){
        cout << "Sasha" << endl;
    } else {
        cout << "Draw" << endl;
    }
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