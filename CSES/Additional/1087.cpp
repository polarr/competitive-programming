/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-07
 * Contest: CSES Problemset
 * Problem: 1087
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

vector<char> dna = {'A', 'C', 'G', 'T'};

void solve(){
    string s; cin >> s;
    int n = sz(s);
    vi arr(n);
    rep(i, 0, n) {
        rep(j, 0, 4) {
            if (s[i] == dna[j]) {
                arr[i] = j;
                break;
            }
        }
    }

    string ans = "";
    vi cnt(4, 0);
    rep(i, 0, n) {
        cnt[arr[i]]++;
        bool flag = false;
        rep(j, 0, 4) {
            if (cnt[j] == 0) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            ans += dna[arr[i]];
            cnt = vi(4, 0);
        }
    }

    rep(j, 0, 4) {
        if (cnt[j] == 0) {
            ans += dna[j];
            break;
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