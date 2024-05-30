/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-30
 * Contest: Codeforces 1976 - Educational Codeforces Round 166 (Rated for Div. 2)
 * Problem: D
 **/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

// Probably just use RMQ data structures, if I knew this maybe top 300

void solve(){
    string sequence; cin >> sequence;
    int n = sequence.size();
    vector<int> prefix = {0};
    int curr = 0;
    //unordered_map<int, int> nums;
    unordered_map<int, vector<int>> pos; 
    vector<int> nums;
    nums.pb(0);
    pos[0].pb(0);
    for (int i = 0; i < n; i++){
        if (sequence[i] == '('){
            prefix.pb(++curr);
        } else {
            prefix.pb(--curr);
        }

        if (pos[prefix[i + 1]] == 0){
            nums.pb(prefix[i + 1]);
        }
        pos[prefix[i + 1]].pb(i + 1);

        //nums[prefix[i + 1]]++;
    }

    sort(nums.begin(), nums.end(), greater<int>());
    
    set<int> pot;

    for (int i = 0; i < nums.size(); i++){
        int num = nums[i];
        for (auto j = pot.upper_bound());
    }

    unordered_map<int, int> targets;
    ll ans = 0;
    /**
    for (int l = 0; l < n - 1; l++){
        int target = prefix[l];
        if (nums[target] == 0 || l < targets[target]){
            continue;
        }
        nums[target]--;
        ll c = 1;
        for (int r = l + 1; r < n + 1; r++){
            if (prefix[r] > 2 * target){
                targets[target] = r;
                break;
            }

            if (prefix[r] == target){
                targets[target] = r + 1;
                nums[target]--;
                c++;
                if (nums[target] == 0){
                    break;
                }
            }
        }

        ans += c * (c - 1) / 2LL;
    }
    **/

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