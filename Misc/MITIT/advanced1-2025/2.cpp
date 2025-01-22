/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-19
 * Contest: MITIT advanced1-2025
 * Problem: 2
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

    set<int> light, dark;
    map<int, int> lightCount, darkCount;
    vector<pair<int, int>> enemies;

    for (int i = 0; i < n; i++){
        int p, s; cin >> p >> s;
        if (s == 0){
            light.insert(p);
            lightCount[p]++;
        }
        else {
            dark.insert(p);
            darkCount[p]++;
        }
    }

    for (int i = 0; i < n; i++){
        int p, s; cin >> p >> s;
        enemies.pb({p, s});
    }

    sort(enemies.begin(), enemies.end());
    reverse(enemies.begin(), enemies.end());

    for (int i = 0; i < n; i++){
        pair<int, int> e = enemies[i];
        int a = e.first, b = (e.first + 1)/2;
        bool can = false;
        if (e.second == 1){
            auto j = dark.lower_bound(b);
            if (j != dark.end()){
                if (!can) {
                    darkCount[*j]--;
                    if (darkCount[*j] == 0){
                        dark.erase(*j);
                    }
                }
                can = true;
            }

            j = light.lower_bound(a);
            if (j != light.end()){
                if (!can) {
                    lightCount[*j]--;
                    if (lightCount[*j] == 0){
                        light.erase(*j);
                    }
                }
                can = true;
            }
        } else {
            auto j = light.lower_bound(b);
            if (j != light.end()){
                if (!can) {
                    lightCount[*j]--;
                    if (lightCount[*j] == 0){
                        light.erase(*j);
                    }
                }
                can = true;
            }

            j = dark.lower_bound(a);
            if (j != dark.end()){
                if (!can) {
                    darkCount[*j]--;
                    if (darkCount[*j] == 0){
                        dark.erase(*j);
                    }
                }
                can = true;
            }
        }

        if (!can){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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