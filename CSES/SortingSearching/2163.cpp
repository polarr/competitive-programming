/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-04
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 2163 - Josephus Problem II
**/

#include <bits/stdc++.h>
using namespace std;

// Order statistic tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    /**
    k++;
    vector<int> pr(n);
    vector<int> nx(n);
    pr[0] = n - 1;
    nx[n - 1] = 0;
    for (int i = 1; i < n; i++){
        pr[i] = i - 1;
        nx[i - 1] = i;
    }

    int curr = n - 1;
    int nn = n;

    vector<int> ans(n);

    do {
        int mk = k % nn;
        if (mk == 0){
            mk = nn;
        }

        for (int i = 0; i < mk; i++){
            curr = nx[curr];
        }

        ans[n - nn] = curr + 1;

        nx[pr[curr]] = nx[curr];
        pr[nx[curr]] = pr[curr];
    } while (--nn > 0);
    **/

   // Bruh just use ordered tree

    Tree<int> c;

    for (int i = 0; i < n; i++){
        c.insert(i + 1);
    }

    int curr = 0;

    do {
        curr = (curr + k) % n;
        auto s = c.find_by_order(curr);
        cout << *s << " ";
        c.erase(*s);
    } while(--n);

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}