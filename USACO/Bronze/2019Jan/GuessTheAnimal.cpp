/**
 * Solution by 1egend
 * Date: 2021-12-17
 * Contest: USACO 2019 January Contest
 * Problem: Bronze P3. Guess the Animal
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "guess";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

struct Counter
{
  struct value_type { template<typename T> value_type(const T&) { } };
  void push_back(const value_type&) { ++count; }
  size_t count = 0;
};

template<typename T1, typename T2>
size_t intersection_size(const T1& s1, const T2& s2)
{
  Counter c;
  set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(c));
  return c.count;
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    fin >> n;

    int ans = 0;
    vector<vector<string>> animals(n);
    for (int i = 0; i < n; ++i){
        string a; int b;
        fin >> a >> b;
        for (int ii = 0; ii < b; ++ii){
            string t;
            fin >> t;
            animals[i].pb(t);
        }

        sort(animals[i].begin(), animals[i].end());
    }

    for (int x = 0; x < n - 1; ++x){
        for (int y = x + 1; y < n; ++y){
            ans = max<int>(ans, intersection_size(animals[x], animals[y]));
        }
    }

    fout << ans + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}