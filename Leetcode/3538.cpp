/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-10
 * Contest: Leetcode
 * Problem: 3538
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
    int l, n, k; cin >> l >> n >> k;
    vector<int> position = {0, 2, 3, 4, 5};
    vector<int> time = {1, 1, 3, 2, 1};

    position.push_back(position[n - 1]);
    time.push_back(0);

    // nvm just some dp, but too lazy to write

    for (int kk = 0; kk < k; kk++){
        int mn = INT_MAX;
        int idx = -1;
        for (int i = 1; i < time.size() - 2; i++){
            int delta = (position[i + 2] - position[i + 1]) * time[i] + (position[i + 1] - position[i]) * (time[i - 1] - time[i]);

            if (delta < mn){
                mn = delta;
                idx = i;
            }
        }
        cout << idx << endl;

        time[idx + 1] += time[idx];
        time.erase(time.begin() + idx);
        position.erase(position.begin() + idx);
    }

    int ans = 0;

    for (int i = 0; i < time.size() - 2; i++){
        ans += time[i] * (position[i + 1] - position[i]);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}