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

const int MAX_N = 5e5 + 1;
const ll MOD = 1e9 + 7;

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        multiset<int> prefix;
        int n = words.size();

        auto prefixSize = [&](string a, string b){
            int curr = 0;
            rep(i, 0, min(a.size(), b.size())){
                if (a[i] != b[i]){
                    break;                    
                }
                curr++;
            }
            return curr;
        };
        
        rep(i, 0, n - 1){
            string a = words[i];
            string b = words[i + 1];
            
            prefix.insert(prefixSize(a, b));
        }

        vi ans(n, 0);

        rep(i, 0, n){
            if (i != 0){
                prefix.erase(prefix.find(prefixSize(words[i], words[i - 1])));
            }

            if (i != n - 1){
                prefix.erase(prefix.find(prefixSize(words[i], words[i + 1])));
            }

            if (i != 0 && i != n - 1){
                prefix.insert(prefixSize(words[i - 1], words[i + 1]));
            }

            if (!prefix.empty()){
                ans[i] = *prev(prefix.end());
            }

            if (i != 0){
                prefix.insert(prefixSize(words[i], words[i - 1]));
            }

            if (i != n - 1){
                prefix.insert(prefixSize(words[i], words[i + 1]));
            }

            if (i != 0 && i != n - 1){
                prefix.erase(prefix.find(prefixSize(words[i - 1], words[i + 1])));
            }
        }
        
        return ans;
    }
};