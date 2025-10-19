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

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;

class HashedString {
    private:
        static const ll M = (1LL << 61) - 1;
        static const ll B;
        static vl pow;
        vl p_hash;

        __int128 mul(ll a, ll b) { return (__int128)a * b; }
        ll mod_mul(ll a, ll b) { return mul(a, b) % M; }

    public:
        HashedString(const string&s) : p_hash(s.size()+ 1){
            while (pow.size() < s.size()){
                pow.pb(mod_mul(pow.back(), B));
            }
            p_hash[0] = 0;
            for (int i = 0; i < s.size(); i++){
                p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
            }
        }

        ll get_hash(int start, int end){
            ll raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
            return (raw_val + M) % M;
        }
};

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);

void solve(){
    string s; cin >> s;
    int q; cin >> q;
    int n = sz(s);
    HashedString hashs(s);

    vector<vi> starts(26);

    map<ll, vi> mp;
    int rt = 20;
    rep(i, 0, n){
        starts[s[i] - 'a'].pb(i);
        rep(j, 0, rt){
            if (i + j >= n){
                break;
            }
            ll hsh = hashs.get_hash(i, i + j);
            mp[hsh].pb(i);
        }
    }

    string qs = "";
    int idx = 0;
    vector<string> queryString(q);
    vector<array<int, 3>> queries(q);
    rep(i, 0, q){
        string t; cin >> t;
        queryString[i] = t;
        int k; cin >> k;
        qs += t;
        queries[i] = {idx, sz(t), k};
        idx += sz(t);
    }

    HashedString hasht(qs);

    rep(i, 0, q){
        int lo = queries[i][0];
        int m = queries[i][1];
        int k = queries[i][2];
        ll hsh1 = hasht.get_hash(lo, lo + min(m, rt) - 1);
        ll hsh = hasht.get_hash(lo, lo + m - 1);
        if (m > rt){
            int cnt = 0;
            bool found = false;
            for (int j : mp[hsh1]){
                if (j + m > n) {
                    continue;
                }
                if (hashs.get_hash(j, j + m - 1) == hsh){
                    cnt++;
                    if (cnt == k){
                        found = true;
                        cout << j + 1 << endl;
                        break;
                    }
                }
            }
            if (!found){
                cout << -1 << endl;
            }
            continue;
        }

        if (!mp.contains(hsh) || mp[hsh].size() < k){
            cout << -1 << endl;
        } else {
            cout << mp[hsh][k - 1] + 1 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}