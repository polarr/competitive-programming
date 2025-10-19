#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, d, w; cin >> n >> d >> w;
    string s = "";
    vi words;
    rep(i, 0, n){
        string c; cin >> c;
        if (i % 2 == 1){
            reverse(all(c));
        }

        s += c;
    }

    int sw = sz(s);
    int len = 0;
    rep(i, 0, sw){
        if (s[i] == ' '){
            words.pb(len);
            len = 0;
            break;
        }

        if (s[i] == '.'){
            words.pb(len);
            len = 0;
            continue;
        }

        len++;
    }

    if (len > 0){
        words.pb(len);
    }

    int curr = 0;
    int ans = 1;
    rep(i, 0, sz(words)){
        int wordLen = words[i];
        if (curr + wordLen > w){
            ans++;
            curr = wordLen;
            if (curr < w){
                curr++;
            }
        } else {
            curr += wordLen;
            if (curr < w){
                curr++;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}