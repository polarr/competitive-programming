/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-06
 * Contest: COCI 2016
 * Problem: zoltan
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

/** 
 * DATASTRUCTURE: Segment Tree
 * PURPOSE: Range Updates and Queries
 * TIME: O(log n) to update and query
*/
template <class T> class SegmentTree {
  private:
	const T UNIT = {0, 0};

    T combine(T a, T b){
        if (a.first == b.first){
            return {a.first, (a.second + b.second) % MOD};
        }

        return max(a, b);
    }

	vector<T> segtree;
	int len;

  public:
	SegmentTree(int len) : len(len), segtree(len * 2, UNIT) {}

	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = combine(segtree[ind], segtree[ind ^ 1]);
		}
	}

    // [start, end)
	T query(int start, int end) {
		T ans = UNIT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { ans = combine(ans, segtree[start++]); }
			if (end % 2 == 1) { ans = combine(ans, segtree[--end]); }
		}
		return ans;
	}
};

/** 
 * ALGORITHM: Modular Exponentiation 
 * PURPOSE: Computes x^n (mod m)
 * CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 * TIME: O(log n)
*/
ll mod_exp(ll x, ll n, ll m) {
	x %= m;

	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}

	return res;
}

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
    int n; cin >> n;

    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vi aa = a;

    sort(all(aa));
    int cnt = 1; 

    map<int, int> b;
    rep(i, 0, n){
        if (i != 0 && aa[i] != aa[i - 1]){
            cnt++;
        }

        b[aa[i]] = cnt;
    }

    rep(i, 0, n){
        a[i] = b[a[i]];
    }

    vi ra = a;
    reverse(all(ra));

    vector<pii> arr(n + 2, {0, 0});
    arr[n + 1] = {0, 1};
    SegmentTree<pii> st(n + 2), nst(n + 2);
    st.set(n + 1, {0, 1});

    rep(i, 0, n){
        int x = ra[i];
        pii amt = st.query(x + 1, n + 2);
        amt.first++;

        if (arr[x].first == amt.first){
            arr[x].second += amt.second;
            arr[x].second %= MOD;
        } else {
            arr[x] = amt;
        }

        st.set(x, arr[x]);

        if (i == n - 2){
            rep(j, 0, n + 2){
                nst.set(j, arr[j]);
            }
        }
    }
    
    pii nlis = nst.query(0, n + 2);
    pii lis = st.query(0, n + 2);
    int mx = lis.first;

    auto mult = [&](pii lis, pii nlis, int rem) -> ll {
        if (nlis.first == lis.first || lis.first == 0){
            ll ans = (ll) nlis.second * mod_exp(2, rem - lis.first - 1, MOD) % MOD;
            ans += (ll) (lis.second + MOD - nlis.second) * mod_exp(2, rem - lis.first, MOD) % MOD;
            return ans % MOD;
        }

        return (ll) lis.second * mod_exp(2, rem - lis.first, MOD) % MOD;
    };

    ll num = mult(lis, nlis, n);

    vector<pii> arr2(n + 1, {0, 0});
    arr2[0] = {0, 1};
    SegmentTree<pii> st2(n + 1);
    st2.set(0, {0, 1});

    rep(i, 0, n - 1){
        int j = n - 1 - i;

        int x = ra[i];
        pii amt = st2.query(0, x);
        amt.first++;

        pii li = st.query(x + 1, n + 2);
        pii nli = nst.query(x + 1, n + 2);

        // debug_out(amt);
        // debug_out(nli);
        // debug_out(li);

        if (li.first + amt.first > mx){
            mx = li.first + amt.first;
            num = (mult(li, nli, n - amt.first) * (ll) amt.second) % MOD;
        } else if (li.first + amt.first == mx){
            num += (mult(li, nli, n - amt.first) * (ll) amt.second) % MOD;
            num %= MOD;
        }

        if (arr2[x].first == amt.first){
            arr2[x].second += amt.second;
            arr2[x].second %= MOD;
        } else {
            arr2[x] = amt;
        }

        st2.set(x, arr2[x]);
    }

    cout << mx << " " << num << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}