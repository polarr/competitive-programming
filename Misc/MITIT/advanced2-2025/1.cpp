/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-19
 * Contest: MITIT advanced2-2025
 * Problem: 1
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

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
    int n; cin >> n;

    vector<int> container(n);
    vector<bool> cycled(n, false);
    vector<int> cycle(n, -1), target = cycle;
    vector<int> processed(n, 0);
    for (int i = 0; i < n; i++){
        cin >> container[i];
        container[i]--;
    }

    vector<int> c = container;

    int count = 1;

    for (int i = 0; i < n; i++){
        if (processed[i] != 0){
            continue;
        }

        int j = i;
        while (true){
            if (processed[j] == 0){
                processed[j] = count;
            } else if (processed[j] == count){
                int start = container[j];
                while(start != j){
                    cycled[start] = true;
                    cycle[container[start]] = start;
                    start = container[start];
                }

                cycled[j] = true;
                cycle[container[j]] = j;
                break;
            } else {
                break;
            }
            j = container[j];
        }
        count++;
    }

    // debug_out(cycle);

    vector<array<int, 3>> ans;
    vector<bool> sorted(n, false);

    for (int i = 0; i < n; i++){
        if (cycle[container[i]] != -1){
            if (cycle[container[i]] != i){
                ans.pb({2, cycle[container[i]], i});
                c[i] = -1;
            }
            continue;
        }

        if (target[container[i]] == -1){
            target[container[i]] = i;
        } else {
            ans.pb({2, target[container[i]], i});
            c[i] = -1;
        }
    }

    for (int i = 0; i < n; i++){
        if (sorted[i]) {continue;}
        if (cycled[i]){
            int j = container[i];
            while (j != i){
                sorted[j] = true;
                ans.pb({1, i, j});
                j = container[j];
            }

            sorted[i] = true;
        }
    }

    for (int i = 0; i < n; i++){
        if (sorted[i]){continue;}
        int j = c[i];
        while (j != -1){
            sorted[j] = true;
            ans.pb({1, i, j});
            c[i] = c[j];
            j = c[j];
        }

        sorted[i] = true;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] + 1 << " " << ans[i][2] + 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}