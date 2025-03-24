/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-22
 * Contest: Codeforces 2090
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    vector<set<pii>> cells(4 * n + 100);
    vector<set<pii>> tables(4 * n + 100);
    int done = 0;
    rep(sum, 2, 4 * n + 100){
        for (int i = 1; i < sum; i++){
            int j = sum - i;
            if ((i % 3) == 0 || (j % 3) == 0){
                continue;
            }

            if (i % 3 == 2 && j % 3 == 2){
                cells[sum + 2].insert({i, j});
                continue;
            }

            cells[sum].insert({i, j});
            done++;

            if (done > n){
                break;
            }
        }

        if (done > n){
            break;
        }
    }

    done = 0;
    rep(sum, 0, 4 * n + 100){
        for (int i = 0; i <= sum; i++){
            int j = sum - i;

            tables[sum].insert({i, j});
            done++;

            if (done > n){
                break;
            }
        }

        if (done > n){
            break;
        }
    }

    int s = 2;
    int t = 0;

    rep(i, 0, n){
        int a; cin >> a;

        if (a == 1){
            while(cells[s].size() == 0){
                s++;
            }

            pii x = *(cells[s].begin());
            cout << x.first << " " << x.second << endl;
            pii table = {x.first/3, x.second/3};
            int sum = table.first + table.second;
            cells[s].erase(cells[s].begin());
            tables[sum].erase(table);
            continue;
        }

        while(tables[t].size() == 0){
            t++;
        }

        pii x = *(tables[t].begin());
        pii cell = {x.first * 3 + 1, x.second * 3 + 1};
        cout << cell.first << " " << cell.second << endl;
        int sum = cell.first + cell.second;
        cells[sum].erase(cell);
        tables[t].erase(tables[t].begin());
        continue;
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