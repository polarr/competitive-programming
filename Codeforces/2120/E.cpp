/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-21
 * Contest: 
 * Problem: E
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


/** TOOL: Debug
 *  PURPOSE: Prints various data types to terminal
 *  SOURCE: tourist
*/
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

void solve(){
    ll n, k; cin >> n >> k;

    ll ans = 0;
    vl a(n);
    rep(i, 0, n) {
        cin >> a[i];
        ans += (a[i] * (a[i] + 1))/2;
    }

    sort(all(a));

    vl pref(n);
    pref[0] = a[0];
    rep(i, 1, n){
        pref[i] = a[i] + pref[i - 1];
    }

    function<ll(int, int)> sum;
    sum = [&](ll lo, ll hi){
        return (hi * (hi + 1))/2 - (lo * (lo + 1))/2;
    };

    vl added(n, 0);
    for (ll i = 1; i < n; i++){
        added[i] = added[i - 1] + sum(a[i - 1], a[i]) * i;
    }

    debug_out(ans);

    ll use = 0;
    ll curr = ans;
    for (ll i = n - 1; i >= 1; i--){
        ll lo = use;
        ll hi = use + (a[i] - a[i - 1]) * (n - i);
        ll j = n - i;
        while (lo < hi){
            ll mid = (lo + hi + 1)/2;

            ll llo = 0, hhi = n - 1;
            while (llo < hhi){
                ll mmid = (llo + hhi)/2;
                if ((pref[mmid] + mid) <= (mmid + 1) * a[mmid + 1]){
                    hhi = mmid;
                } else {
                    llo = mmid + 1;
                }
            }

            if (llo >= mid) {
                hi = mid - 1;
                continue;
            }

            ll num = pref[llo] + mid;
            ll more = mid - use;
            ll give = LLONG_MAX;
            if (more != 0) give = a[i] - (more - 1)/j;
            ll get = (num + llo)/(llo + 1);
            
            if (give >= get + k){
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        if (lo == use) break;

        ll more = lo - use;
        ll kk = more/j;

        ll c = curr + lo * k;

        c -= sum(a[i] - kk, a[i]) * j;
        more -= kk * j;
        c -= (a[i] - kk) * more;
        
        ll llo = 0, hhi = i - 1;
        while (llo < hhi){
            ll mmid = (llo + hhi)/2;
            if ((pref[mmid] + lo) <= (mmid + 1) * a[mmid + 1]){
                hhi = mmid;
            } else {
                llo = mmid + 1;
            }
        }


        c += added[llo];
        more = lo + pref[llo] - a[llo] * (llo + 1);
        kk = more/(llo + 1);

        c += sum(a[llo], a[llo] + kk) * (llo + 1);
        more -= kk * (llo + 1);
        c += (a[llo] + kk + 1) * more;

        ans = min(ans, c);

        curr -= sum(a[i - 1], a[i]) * (n - i);
        use += (a[i] - a[i - 1]) * (n - i);
    }

    cout << ans << endl;
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