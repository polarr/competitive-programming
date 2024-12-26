/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-04
 * Contest: APIO 2011
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

/** No idea why doesn't work */
void solve(){
    pair<int, int> st = {0, 0};
    pair<int, int> ed = {0, 0};
    cin >> st.first >> st.second >> ed.first >> ed.second;

    vector<int> xs = {st.first, ed.first};
    vector<int> ys = {st.second, ed.second};

    int n; cin >> n;
    vector<array<int, 4>> rect(n);

    for (int i = 0; i < n; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a > c){
            swap(a, c);
        }
        if (b > d){
            swap(b, d);
        }

        rect[i] = {a, b, c, d};

        xs.pb(a);
        xs.pb(c);
        ys.pb(b);
        ys.pb(d);
    }

    auto prune = [&](vector<int>& arr){
        if (arr.size() == 0) return;
        vector<int> a = {arr[0]};
        for (int i = 1; i < arr.size(); i++){
            if (arr[i] != arr[i - 1]){
                a.pb(arr[i]);
            }
        }

        arr = a;
    };

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    prune(xs); prune(ys);

    int xx = xs.size(), yy = ys.size();

    vector<ll> d(xx * yy, LLONG_MAX);
    vector<int> status(xx * yy, -3);
    vector<vector<pair<int, ll>>> adj(xx * yy);
    map<pair<int, int>, int> pIndex;

    int k = 0;
    int s, e;

    for (int i = 0; i < xx; i++){
        for (int j = 0; j < yy; j++){
            pair<int, int> p = {xs[i], ys[j]};

            pIndex[p] = k;

            if (p.first == st.first && p.second == st.second){
                s = k;
                status[k] = -1;
            }

            if (p.first == ed.first && p.second == ed.second){
                e = k;
                status[k] = -2;
            }

            k++;
        }
    }

    for (int i = 0; i < n; i++){
        array<int, 4> c = rect[i];
        status[pIndex[{c[0], c[1]}]] = 1;
        status[pIndex[{c[0], c[3]}]] = 2;
        status[pIndex[{c[2], c[3]}]] = 3;
        status[pIndex[{c[2], c[1]}]] = 4;
    }

    auto edge = [&](int i, int j){
        int ix = xs[i/yy], iy = ys[i % yy];
        int jx = xs[j/yy], jy = ys[j % yy];

        assert(ix == jx || iy == jy);

        ll d = (ll)abs(ix - jx) + (ll)abs(iy - jy);

        adj[i].pb({j, d});
        adj[j].pb({i, d});
    };

    auto connect = [&](int i, int j){
        if (i < 0 || j < 0){
            return;
        }

        int curr = status[i];
        int pr = status[j];

        if (curr > pr){
            swap(curr, pr);
        }

        if (curr == 0 || pr == 0 || curr == 9 || pr == 9){
            // floating or inside rect
            return;
        }

        if ((curr == 5 && pr == 7) || (curr == 6 && pr == 8)){
            // opposite rect sides
            return;
        }

        edge(i, j);
    };


    k = 0;

    for (int i = 0; i < xx; i++){
        for (int j = 0; j < yy; j++){
            if (status[k] == -3){
                status[k] = 0;

                if (i > 0){
                    int prevX = status[k - yy];

                    // inside
                    if (prevX == 5 || prevX == 9){
                        status[k] = 9;
                    }

                    // edge
                    if (prevX == 1 || prevX == 8) {
                        status[k] = 8;
                    }

                    if (prevX == 2 || prevX == 6){
                        status[k] = 6;
                    }
                }

                if (j > 0){
                    int prevY = status[k - 1];
                    if (prevY == 1 || prevY == 5){
                        status[k] = 5;
                    }
                    if (prevY == 4 || prevY == 7){
                        status[k] = 7;
                    }
                }
            }

            connect(k, k - yy);
            connect(k, k - 1);

            k++;
        }
    }

    d[s] = 0LL;

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0LL, s});

    while(!pq.empty()){
        auto [ndist, kk] = pq.top();
        pq.pop();

        if (ndist != d[kk]) { continue; }

        for (pair<int, ll> &node: adj[kk]){
            if (ndist + node.second < d[node.first]){
                d[node.first] = ndist + node.second;
                pq.push({d[node.first], node.first});
            }
        }
    }

    if (d[e] == LLONG_MAX){
        cout << e;
        cout << " No Path" << endl;
        return;
    }

    cout << d[e] << endl;
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