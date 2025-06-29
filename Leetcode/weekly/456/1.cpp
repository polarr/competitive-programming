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
    vector<string> partitionString(string s) {
        set<string> st;
        string curr = "";
        vector<string> ans;
        rep(i, 0, s.size()){
            curr += s[i];
            if (!st.contains(curr)){
                st.insert(curr);
                ans.pb(curr);
                curr = "";
            }
        }
        return ans;
    }
};