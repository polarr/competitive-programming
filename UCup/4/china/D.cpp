/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-07
 * Contest: 
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
    string s; cin >> s;
    int n = sz(s);

    using T = array<int, 2>;
    vector<vector<T>> lines;
    vector<T> line;
    rep(i, 0, n) {
        if (s[i] == '1') {
            if (!line.empty()) lines.pb(line);
            line = {};
            continue;
        }

        if (s[i] == '0') {
            if (line.empty() || line.back()[1] == 0) {
                line.pb({1, 1});
            } else {
                line.back()[0]++;
            }
        } else {
            line.pb({1, 0});
        }
    }

    if (!line.empty()) lines.pb(line);

    int ans = 0;
    rep(t, 0, sz(lines)) {
        ans = max(ans, 1);
        vector<T> line = lines[t];
        int m = sz(line);
        vi cnt(m, 0);
        vector<array<int, 4>> pos(m);

        vector<T> left(m), right(m);
        rep(i, 0, m) {
            if (line[i][1] == 0) {
                int j = i + 1;
                int sum = line[i][0];
                if (j < m) {
                    if (line[j][1] == 1) {
                        sum += line[j][0];
                        j++;
                    }
                }
                right[i] = {sum, j};
                sum = line[i][0];
                j = i - 1;
                if (j > -1) {
                    if (line[j][1] == 1) {
                        sum += line[j][0];
                        j--;
                    }
                }
                left[i] = {sum, j};
            } else {
                int j = i + 1;
                int sum = line[i][0];
                bool found = false;
                while (j < m) {
                    if (line[j][1] == 0) {
                        if (found) {
                            break;
                        }
                        found = true;
                    }
                    sum += line[j][0];
                    j++;
                }
                right[i] = {sum, j};
                j = i - 1;
                sum = line[i][0];
                found = false;
                while (j > -1) {
                    if (line[j][1] == 0) {
                        if (found) {
                            break;
                        }
                        found = true;
                    }
                    sum += line[j][0];
                    j--;
                }
                left[i] = {sum, j};
            }

            // cout << i << ": " << left[i][1] << " " << right[i][1] << endl;
        }

        rep(i, 0, m) {
            T at = right[i];
            int curr = at[0];
            int x = at[1];

            int r = curr, l = curr;

            int r1 = r, r2 = r, r3 = r;
            // case r
            if (x != m) {
                T at1 = right[x];
                int x1 = at1[1];
                r1 += at1[0];
                r2 += at1[0];
                if (x1 != m) {
                    T at2 = right[x1];
                    int x2 = at2[1];
                    r2 += at2[0];
                    r3 = at2[0];
                    if (x2 != m) {
                        T at3 = right[x2];
                        r3 += at3[0];
                    }
                }
            }
            r = max(r1, min(r2, r3));

            // case l
            x = i - 1;
            int l1 = l, l2 = l, l3 = l;
            if (x != -1) {
                T at1 = left[x];
                int x1 = at1[1];
                l1 += at1[0];
                l2 += at1[0];
                if (x1 != -1) {
                    T at2 = left[x1];
                    int x2 = at2[1];
                    l2 += at2[0];
                    l3 = at2[0];
                    if (x2 != -1) {
                        T at3 = left[x2];
                        l3 += at3[0];
                    }
                }
            }
            l = max(l1, min(l2, l3));

            ans = max(ans, min(r, l));
            
            // go right
            // cout << curr << "a";
            // int val = line[i][0] + max(left[0] + min(left[1], right[0]), right[0] + min(right[1], left[0]));
            // cnt[i] = val;
            // pos[i] = {left[1], left[0], right[0], right[1]};
            // cout << i << endl;
            // cout << left[1] << " " << left[0] << " " << right[0] << " " << right[1] << endl;
        }
    }

    cout << ans << '\n';
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