    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using ld = long double;
    #define rep(i, a, b) for (int i = (a); i < (b); ++i)
     
    void solve(){
        ld r, s, h; cin >> r >> s >> h;
     
        ld day = r * acos((ld)-1) * 2/(s * h);
     
        ll rday = day + (ld)0.5;
        ld d = abs(day - rday);
     
        int mx = 1000;
     
        ld mn = 1e9;
        array<int, 3> ans;
     
        auto clamp = [&](int lo, int hi, ld x) -> ld {
            if (x < (ld)lo){
                return lo;
            }
     
            if (x > (ld) hi){
                return hi;
            }
     
            return x;
        };
     
        //cout << fixed << d << endl;
     
        rep(aa, 2, 1001){
            rep(bb, 2, 1001){
                ld a = aa, b = bb;
                int lo = 2, hi = (mx/(aa * bb));
                if (hi < lo) {
                    break;
                }
     
                ld adj = d - 1/a + 1/(a * b);
                ld diff;
                int cc;
                if (adj <= 0){
                    diff = abs(adj - 1/(a * b * hi));
                    cc = hi;
                } else {
                    ld want = clamp(lo, hi, 1/(a * b * adj));
                    int lw = floor(want), hw = ceil(want);
     
                    diff = abs(adj - 1/(a * b * lw));
                    cc = lw;
     
                    ld nd = abs(adj - 1/(a * b * hw));
                    if (nd < diff){
                        diff = nd;
                        cc = hw;
                    }
                }
     
                if (diff < mn){
                    mn = diff;
                    ans = {aa, bb, cc};
                }
            }
        }
     
        cout << ans[0] << " " << ans[0] * ans[1] << " " << ans[0] * ans[1] * ans[2] << endl;
    }
     
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        solve();
     
        return 0;
    }