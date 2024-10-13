/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-12
 * Contest: ICPC Practice Codeforces 1912
 * Problem: A
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll x, k; cin >> x >> k;
    vector<vector<ll>> draw(k);

    for (int i = 0; i < k; i++){
        int l; cin >> l;
        ll last = 0;
        for (int j = 0; j < l; j++){
            ll a; cin >> a;
            if (j > 0 && a * draw[i][draw[i].size() - 1] >= 0){
                draw[i][draw[i].size() - 1] += a;
                continue;
            }
            draw[i].pb(a);
        }
    }

    vector<vector<tuple<ll, ll, int>>> possible(k);
    vector<int> at(k, 0);

    priority_queue<tuple<ll, ll, int>> curr;

    for (int i = 0; i < k; i++){
        ll cost = 0;
        ll total = 0;
        for (int j = 0; j < draw[i].size(); j++){
            total += draw[i][j];
            cost = min(cost, total);
            if (total > 0){
                possible[i].pb({cost, total, i});
                cost = 0;
                total = 0;
            }
        }
    }

    for (int i = 0; i < k; i++){
        if (possible[i].size() == 0){
            continue;
        }
        curr.push(possible[i][0]);
    }

    while(!curr.empty()){
        tuple<ll, ll, int> c = curr.top();
        curr.pop();

        //cout << x << " " << get<0>(c) << endl;

        if (x + get<0>(c) >= 0){
            x += get<1>(c);
            int i = get<2>(c);
            at[i]++;
            if (possible[i].size() > at[i]){
                curr.push(possible[i][at[i]]);
            }
        } else {
            break;
        }
    }

    cout << x << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}