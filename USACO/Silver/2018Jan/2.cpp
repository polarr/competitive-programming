/**
 * Solution by 1egend
 * Date: 2024-01-28
 * Contest: USACO 2018 January
 * Problem: Silver P2. Rental Service
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "rental";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<pair<ll, ll>> profit = {make_pair(0, 0)};

int search(ll target){
    int left = 0;
    int right = profit.size();
    while (left < right){
        int middle = (left + right)/2;
        ll val = profit[middle].first;
        if (val == target){
            return middle;
        }

        if (val < target){
            left = middle + 1;
        }
        
        if (val > target){
            right = middle;
        }
    }
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, m, r;
    fin >> n >> m >> r;

    vector<int> cows;
    // price, maximum capacity
    vector<pair<int, int>> stores;
    set<ll> storeMilk = {0};
    vector<int> rentals;

    for (int i = 0; i < n; i++){
        int c;
        fin >> c;
        cows.pb(c);
    }

    sort(cows.begin(), cows.end(), greater{});

    vector<ll> milk = {0};
    ll milkSum = 0;
    for (int i = 0; i < n; i++){
        milkSum += cows[i];
        milk.pb(milkSum);
    }

    for (int i = 0; i < m; i++){
        int q, p;
        fin >> q >> p;
        stores.pb(make_pair(p, q));
    }

    sort(stores.begin(), stores.end(), greater{});

    ll profitSum = 0;
    ll totalMilk = 0;
    
    for (int i = 0; i < m; i++){
        totalMilk += stores[i].second;
        profitSum += stores[i].first * stores[i].second;
        storeMilk.insert(totalMilk);
        profit.pb(make_pair(totalMilk, profitSum));
    }

    stores.pb(make_pair(0, 0));

    for (int i = 0; i < r; i++){
        int x;
        fin >> x;
        rentals.pb(x);
    }

    sort(rentals.begin(), rentals.end(), greater{});

    vector<ll> rentalPrefix = {0};

    ll sum = 0;

    for (int i = 0; i < r; i++){
        sum += rentals[i];
        rentalPrefix.pb(sum);
    }

    ll ans = 0;

    for (int rent = 0; rent <= min(n, r); rent++){
        int sell = n - rent;
        ll lowerIndex = *(--storeMilk.upper_bound(milk[sell]));
        int lowerMilkIndex = search(lowerIndex);
        pair<ll, ll> lowerMilk = profit[lowerMilkIndex];
        ans = max(ans, rentalPrefix[rent] + lowerMilk.second + (milk[sell] - lowerMilk.first) * stores[lowerMilkIndex].first);
    }

    fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    fin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}