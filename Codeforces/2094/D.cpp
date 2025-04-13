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
    string p; cin >> p;
    string s; cin >> s;

    vector<pii> a;
    vector<pii> b;
    pii cnt = {0, 0};
    rep(i, 0, p.size()){
        if (i > 0 && p[i] != p[i - 1]){
            a.pb(cnt);
            cnt.second = 0;
        }

        cnt.first = (p[i] - 'A');
        cnt.second++;
    }

    a.pb(cnt);
    cnt = {0, 0};

    rep(i, 0, s.size()){
        if (i > 0 && s[i] != s[i - 1]){
            b.pb(cnt);
            cnt.second = 0;
        }

        cnt.first = (s[i] - 'A');
        cnt.second++;
    }

    b.pb(cnt);

    if (a.size() != b.size()){
        cout << "NO" << endl;
        return;
    }

    int n = a.size();
    rep(i, 0, n){
        if (a[i].first != b[i].first){
            cout << "NO" << endl;
            return;
        }

        if (b[i].second < a[i].second || b[i].second > 2 * a[i].second){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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