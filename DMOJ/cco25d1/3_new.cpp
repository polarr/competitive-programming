/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-05
 * Contest: CCO 2025 Day 1
 * Problem: 3
**/

#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(ll i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const ll MAX_N = 1e18;
const ll MAX_SEARCH = 1e18;
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

vl odd, even;

bool check(ll x, ll b){
    for (ll i = 2; i <= b; i++){
        ll cnt = 0;
        ll sum = 0;

        ll xx = x;

        while (xx > 0){
            sum += xx % i;
            cnt++;
            xx /= i;
        }

        if (sum * 2 != (i - 1) * cnt){
            return false;
        }
    }

    return true;
}

// KACTL
ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}
ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	if ((a - b) % g != 0) {return -1;}
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

using T = pair<ll, ll>;

vector<T> intersect(vector<T>& a, vector<T>& b) {
    vector<T> ans;

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        auto [la, ra] = a[i];
        auto [lb, rb] = b[j];

        ll l = max(la, lb);
        ll r = min(ra, rb);

        if (l <= r) {
            ans.pb({l, r});
        }

        if (ra < rb) {
            ++i;
        } else {
            ++j;
        }
    }

    return ans;
}

void solve(){
    ll b, n; cin >> b >> n;
    vector<vl> pow(12, vl(1, 1));

    rep(i, 2, 12){
        int j = 1;
        while (pow[i][j - 1] <= MAX_N/i){
            pow[i].pb(pow[i][j - 1] * i);
            j++;
        }
    }
    
    ll l = 1;
    vector<T> space = {{1, MAX_N}};
    for (ll i = 2; i <= b; i += 2){
        vector<T> sub;
        for (int j = 1; j < pow[i].size(); j += 2){
            ll ed = MAX_N;
            if (j != pow[i].size() - 1){
                ed = pow[i][j + 1] - 1;
            }
            sub.pb({pow[i][j], ed});
        }

        space = intersect(space, sub);

        l = lcm(l, i - 1);
    }

    ll numodd = 0;
    ll md = l;
    for (ll i = 3; i <= b; i += 2){
        numodd++;
        odd.pb(i);
        md = lcm(md, i - 1);
        vector<T> sub;

        for (int j = 1; j < pow[i].size(); j += 2){
            ll ed = MAX_N;
            if (j != pow[i].size() - 1){
                ed = pow[i][j + 1] - 1;
            }
            sub.pb({pow[i][j], ed});
        }
    }

    vl residues;

    rep(mask, 0, (1 << numodd)){
        ll need = 0;
        ll g = l;

        if (need == -1) {
            continue;
        }

        residues.pb(need);
    }

    sort(all(residues));
    int nn = residues.size();

    ll s = (n - residues[0] + md - 1)/md;

    int cnt = 0;

    rep(k, s, s + MAX_SEARCH){
        ll y = k * md;
        
        while (y > space[cnt].second){
            cnt++;
        }

        if (space[cnt].first - y > md){
            k = space[cnt].first/md - 1;
            continue;
        }

        rep(i, 0, nn){
            ll x = y + residues[i];
            if (check(x, b)){
                cout << x << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}