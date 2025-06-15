
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

class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";
        int cnt = 0;
        rep(i, 0, caption.size()){
            if (caption[i] == ' ') continue;
            if ((i == 0 || caption[i - 1] == ' ')){
                if (cnt == 0){
                    ans += tolower(static_cast<unsigned char>(caption[i]));
                } else {
                    ans += toupper(static_cast<unsigned char>(caption[i]));
                }
                cnt++;
            } else {
                ans += tolower(static_cast<unsigned char>(caption[i]));
            }

            if (ans.size() == 100) break;
        }

        return ans;
    }
};