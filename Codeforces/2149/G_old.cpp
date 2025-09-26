/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-25
 * Contest: 
 * Problem: G
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

vector<vi> ans;
vi arr;

vi rec(int l, int r, vector<array<int, 3>> q){
    if (l == r){
        for (auto &[ql, qr, j] : q){
            ans[j].pb(arr[l]);
        }

        return {arr[l]};
    }

    vector<array<int, 3>> now, lo, hi;
    int mid = (l + r)/2;
    int target = (r - l + 1)/3;
    for (array<int, 3> qr : q){
        if (l <= qr[0] && qr[1] <= r){
            now.pb(qr);
        } else if (qr[1] <= mid){
            lo.pb(qr);
        } else {
            hi.pb(qr);
        }
    }

    vi possible, could;
    vi c1 = rec(l, mid, lo);
    vi c2 = rec(mid + 1, r, hi);
    
    for (int c : c1){
        bool has = false;
        for (int cc : possible){
            if (cc == c){
                has = true;
                break;
            }
        }
        if (!has) possible.pb(c);
    }

    for (int c : c2){
        bool has = false;
        for (int cc : possible){
            if (cc == c){
                has = true;
                break;
            }
        }
        if (!has) possible.pb(c);
    }

    vector<vi> prefix(sz(possible));
    rep(i, 0, sz(possible)){
        int c = possible[i];
        int cnt = 0;
        prefix[i].pb(0);
        rep(j, l, r + 1){
            if (arr[j] == c){
                cnt++;
            }
            prefix[i].pb(cnt);
        }

        if (cnt > target){
            could.pb(c);
        }
    }

    for (auto &[ql, qr, j] : now){
        rep(i, 0, sz(possible)){
            int t = (qr - ql + 1)/3;
            if (prefix[i][qr - l + 1] - prefix[i][ql - l] > t){
                ans[j].pb(possible[i]);
            }
        }
    }

    return could;
}

void solve(){
    int n, q; cin >> n >> q;

    ans = vector<vi>(q);
    arr = vi(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    vector<array<int, 3>> queries;
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        queries.pb({l - 1, r - 1, i});
    }

    rec(0, n - 1, queries);

    rep(i, 0, q){
        if (ans[i].size() == 0){
            cout << -1 << endl;
            continue;
        }

        sort(all(ans[i]));
        for (int a : ans[i]){
            cout << a << " ";
        }

        cout << endl;
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