#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;
const ld INF = 1e15;

void solve() {
    int n; cin >> n;

    set<pair<ld, int>> positions;
    set<pair<ld, int>> weights;
    positions.insert({-INF, -1});
    positions.insert({INF, -1});

    vector<ld> weight(n), pos(n);
    vector<ld> acc(n, 1);
    rep(i, 0, n) {
        cin >> pos[i];
        cin >> weight[i];
        positions.insert({pos[i], i});
        weights.insert({weight[i], i});
    }

    ld c = 0;
    ld ans = 0;
    rep(i, 0, n){
        c += pos[i] * weight[i];
    }

    c *= -1;
    ld curr = 0;

    while (c != curr){
        // use the max weight guy
        auto it = prev(weights.end());
        ld w = (*it).first;
        int idx = (*it).second;
        ld p = pos[idx];
        
        auto here = positions.find({p, idx});
        auto up = next(here);
        auto down = prev(here);

        if (c > 0){
            ld delta = (*up).first - p;
            int j = (*up).second;
            ld mult = acc[idx];
            if (curr + mult * delta * w >= c){
                ans += abs((curr - c)/w);
                break;
            }
            

            curr += mult * delta * w;
            ans += abs(mult * delta);   

            positions.erase(here);
            weights.erase(it);
            auto hw = weights.find({weight[j], j});
            weights.erase(hw);
            weight[j] = (w * acc[idx] + weight[j] * acc[j])/(ld)(acc[j] + acc[idx]);
            acc[j] += acc[idx];
            weights.insert({weight[j], j});
        } else {
            ld delta = (*down).first - p;
            int j = (*down).second;
            ld mult = acc[idx];
            if (curr + mult * delta * w <= c){
                ans += abs((curr - c)/w);
                break;
            }


            curr += mult * delta * w;
            ans += abs(mult * delta);            

            positions.erase(here);
            weights.erase(it);
            auto hw = weights.find({weight[j], j});
            weights.erase(hw);
            weight[j] = (w * acc[idx] + weight[j] * acc[j])/(ld)(acc[j] + acc[idx]);
            acc[j] += acc[idx];
            weights.insert({weight[j], j});
        }
    }

    cout << fixed << setprecision(20) << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}