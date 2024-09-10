/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-08
 * Contest: DMOJ bts24 - Back to School '24
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
    int n; cin >> n;
    
    int nn = n;
    int k = 0;
    while (nn > 1){
        nn /= 2;
        k++;
    }

    vector<pair<ll, ll>> skill(n - 1);
    vector<bool> findskill(n, false);

    ll s = 1;

    for (int i = 0; i < n - 1; i++){
        ll x; cin >> x;
        skill[i] = make_pair(x, 0LL);
        findskill[x - 1] = true;
    }

    for (int i = 0; i < n; i++){
        if (!findskill[i]){
            s = i + 1;
            break;
        }
    }

    vector<vector<pair<ll, ll>>> start(k + 1);
    vector<vector<pair<ll, ll>>> end(k + 1);

    auto compute_insert = [&] (vector<vector<pair<ll, ll>>> &arr, vector<pair<ll, ll>> &ss){
        int i = 0;
        while (ss.size() > 1){
            arr[i] = ss;

            vector<pair<ll, ll>> ns;
            for (int j = 0; j < ss.size()/2; j++){
                pair<ll, ll> a = ss[2 * j], b = ss[2 * j + 1];
                ll larger = max(a.first, b.first);
                ll c = a.second + b.second + (a.first - b.first) * (a.first - b.first);

                ns.pb(make_pair(larger, c));
            }

            ss = ns;
            i++;
        }

        arr[i] = ss;

        return arr;
    };

    vector<pair<ll, ll>> dup = skill;
    dup.insert(dup.begin(), make_pair(s, 0LL));
    compute_insert(start, dup);
    dup = skill;
    dup.pb(make_pair(s, 0LL));
    compute_insert(end, dup);

    cout << start[k][0].second << " " << start[k][0].second << " ";

    auto simulate = [&] (int index) {
        int round = 0;
        pair<ll, ll> curr = make_pair(s, 0);

        while (round < k){
            int group = index/2;
            int opp = index + 1;
            bool first = false;
            if (index % 2){
                opp = index - 1;
                first = true;
            }

            pair<ll, ll> opponent = start[round][opp];
            if (first){
                opponent = end[round][opp];
            }

            ll larger = max(curr.first, opponent.first);
            ll c = curr.second + opponent.second + (curr.first - opponent.first) * (curr.first - opponent.first);

            curr = make_pair(larger, c);
            round++;
            index = group;

            // cout << curr.second << endl;
        }

        return curr.second;
    };

    for (int i = 1; i < n/2 - 1; i++){
        // dup = skill;
        // dup.insert(dup.begin() + 2 * i, make_pair(s, 0LL));

        ll ans = simulate(2 * i);

        cout << ans << " " << ans << " ";
    }

    cout << end[k][0].second << " " << end[k][0].second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}