/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-13
 * Contest: Codeforces 2022
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;
    ull ans = 0;
    vector<ull> cars(n);
    for (int i = 0; i < n; i++){
        cin >> cars[i];
    }

    sort(cars.begin(), cars.end());
    reverse(cars.begin(), cars.end());
    vector<ull> customers(9, 0);
    vector<ull> nextcustomers(9, 0);

    for (int i = 0; i < n; i++){
        ull car = cars[i];
        for (int j = 8; j >= 0; j--){
            ull minus = min(car, customers[j]);
            customers[j] -= minus;
            car -= minus;
            if (j != 0){
                nextcustomers[j - 1] = minus;
            }
        }

        for (int j = 0; j < 9; j++){
            customers[j] += nextcustomers[j];
            nextcustomers[j] = 0;
        }
        
        if (x != 1) {
            customers[x - 2] += car;
        }
        ans += car;
    }

    cout << ans << endl;
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