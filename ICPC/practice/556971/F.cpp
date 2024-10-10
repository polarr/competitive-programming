/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-09
 * Contest: ICPC Practice Codeforces 556971
 * Problem: F
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
    vector<pair<ull, ull>> buyers(n);
    int acount = 0;
    int bcount = 0;
    for (int i = 0; i < n; i++){
        ull a, b; cin >> a >> b;
        if (b == 0){
            acount++;
        }
        if (a == b){
            bcount++;
        }
        buyers[i] = {a, b};
    }

    sort(buyers.begin(), buyers.end());

    set<pair<ull, int>> curr;

    auto calc_max = [&](int index){
        ull ans = 0;
        auto i = curr.begin();
        int t = 0;
        while (i != curr.end()){
            ans = max(ans, (*i).first * (curr.size() - t));
            t++;
            i = next(i);
        }

        return ans;
    };

    vector<ull> dpa(n + 1, 0);
    vector<ull> dpb(n);
    dpb[n - 1] = buyers[n - 1].first;
    for (int i = n - 2; i >= 0; i--){
        dpb[i] = max(dpb[i + 1], buyers[i].first * (n - i));
    }

    if (acount == n){
        cout << dpb[0] << endl;
        return;
    }

    if (bcount == n){
        for (int i = 1; i < n + 1; i++){
            dpa[i] = max(dpa[i - 1], buyers[i].first * (n - i));
        }
    }

    for (int i = 0; i < n; i++){
        curr.insert({buyers[i].second, i});
        dpa[i + 1] = calc_max(i);
    }
    
    ull ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, dpb[i] + dpa[i]);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}