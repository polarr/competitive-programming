/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-04
 * Contest: Codeforces 2092
 * Problem: D
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
    int n; cin >> n;
    string s; cin >> s;
    vi a(n);
    vi cnt(3);
    rep(i, 0, n){
        if (s[i] == 'T'){
            a[i] = 0;
            cnt[0]++;
        } else if (s[i] == 'L'){
            a[i] = 1;
            cnt[1]++;
        } else {
            a[i] = 2;
            cnt[2]++;
        }
    }

    rep(i, 0, 3){
        if (cnt[i] == n){
            cout << -1 << endl;
            return;
        }
    }

    auto other = [&](int a, int b){
        rep(i, 0, 3){
            if (a != i && b != i){
                return i;
            }
        }
    };
    
    auto getMax = [&](){
        int mx = 0;
        int ans = -1;
        rep(i, 0, 3){
            if (cnt[i] > mx){
                mx = cnt[i];
                ans = i;
            }
        }
        return ans;
    };

    auto getMin = [&](){
        int mx = INT_MAX;
        int ans = -1;
        rep(i, 0, 3){
            if (cnt[i] < mx){
                mx = cnt[i];
                ans = i;
            }
        }
        return ans;
    };

    auto atLarge = [&](){
        int mx = 0;
        rep(i, 0, 3){
            mx = max(mx, cnt[i]);
        }
        int c = 0;
        rep(i, 0, 3){
            if (cnt[i] == mx){
                c++;
            }
        }

        return c;
    };

    vi moves;

    while (atLarge() == 1){
        rep(i, 0, a.size() - 1){
            if (a[i] == a[i + 1]) continue;
            int o = other(a[i], a[i + 1]);
            if (o != getMax()){
                moves.pb(i + 1);
                a.insert(a.begin() + i + 1, o);
                cnt[o]++;
                break;
            }
        }
    }

    while (atLarge() == 2){
        int small = getMin();
        bool found = false;
        rep(i, 0, a.size() - 1){
            if (a[i] == a[i + 1]) continue;
            int o = other(a[i], a[i + 1]);
            if (o == small){
                moves.pb(i + 1);
                a.insert(a.begin() + i + 1, o);
                cnt[o]++;
                found = true;
                break;
            }
        }

        if (found){
            continue;
        }

        rep(i, 0, a.size() - 1){
            if (a[i] != a[i + 1]){
                int f = a[i + 1] == small ? a[i] : a[i + 1];
                int pos = a[i + 1] == small ? i + 2 : i + 1;
                int o = other(a[i], a[i + 1]);
                moves.pb(i + 1);
                a.insert(a.begin() + i + 1, o);
                moves.pb(pos);
                a.insert(a.begin() + pos, f);
                cnt[o]++;
                cnt[f]++;
                break;
            }
        }
    }

    if (moves.size() > 2 * n){
        cout << -1 << endl;
        return;
    }

    cout << moves.size() << endl;
    for(int i : moves){
        cout << i << endl;
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