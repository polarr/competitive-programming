/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-06
 * Contest: 1979 - Codeforces Round 951 (Div. 2)
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> block;
    int counter = 0;
    for (int i = n - 1; i >= 0; i--){
        if (i < n - 1 && s[i] != s[i + 1]){
            block.pb(counter);
            counter = 1;
        } else {
            counter++;
        }
    }

    block.pb(counter);

    int sum = block[0];
    for (int i = 1; i < block.size(); i++){
        if (block[i] != k){
            if (block[i] < k){
                if (i % 2 == 0 && block[0] + block[i] == k){
                    for (int j = i + 1; j < block.size() - 1; j++){
                        if (block[j] != k){
                            cout << -1 << endl;
                            return;
                        }
                    }

                    cout << n - sum << endl;
                    return;
                } else if (i == block.size() - 1 && block[0] == k){
                    cout << n - k << endl;
                    return;
                }
                cout << -1 << endl;
                return;
            } else {
                int diff = block[i] - k;
                if (i % 2 == 1 && block[0] == k && diff == k){
                    for (int j = i + 1; j < block.size() - 1; j++){
                        if (block[j] != k){
                            cout << -1 << endl;
                            return;
                        }
                    }

                    cout << n - (sum + k) << endl;
                } else if (i % 2 == 0 && diff + block[0] == k){
                    for (int j = i + 1; j < block.size() - 1; j++){
                        if (block[j] != k){
                            cout << -1 << endl;
                            return;
                        }
                    }

                    cout << n - (sum + k) << endl;
                } else if (i == block.size() - 1 & block[0] == k && diff < k){
                    cout << n - (sum + k) << endl;
                } 
                else {
                    cout << -1 << endl;
                }
                return;
            }
        } else {
            sum += block[i];
        }
    }

    if (block[0] == k){
        cout << n << endl;
    } else {
        cout << -1 << endl;
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