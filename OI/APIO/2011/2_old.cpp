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

void solve(){
    pair<int, int> start;
    pair<int, int> end;
    cin >> start.first >> start.second >> end.first >> end.second;

    int n; cin >> n;
    vector<array<int, 4>> beehives(n);
    for (int i = 0; i < n; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        beehives[i] = {min(a, c), min(b, d), max(a, c), max(b, d)};
    }

    beehives.pb({start.first, start.second, start.first, start.second});
    beehives.pb({end.first, end.second, end.first, end.second});

    vector<ll> v(4 * (n + 2), LLONG_MAX);

    vector<vector<pair<int, ll>>> adj(4 * (n + 2));

    vector<int> minTop(4 * (n + 2), INT_MAX);
    vector<int> minRight(4 * (n + 2), -INT_MAX);
    vector<int> maxBot(4 * (n + 2), -INT_MAX);
    vector<int> maxLeft(4 * (n + 2), -INT_MAX);

    auto edge = [&](int i, int j, ll d){
        adj[i].pb({j, d});
        adj[j].pb({i, d});
    };

    sort(beehives.begin(), beehives.end());

    int s, e;

    // internal rect
    for (int i = 0; i < n + 2; i++){
        if (beehives[i][0] == beehives[i][2]){
            if (beehives[i][0] == start.first && beehives[i][1] == start.second){
                s = i;
            } else {
                e = i;
            }
            continue;
        }
        edge(4 * i, 4 * i + 1, beehives[i][2] - beehives[i][0]);
        edge(4 * i + 1, 4 * i + 2, beehives[i][3] - beehives[i][1]);
        edge(4 * i + 2, 4 * i + 3, beehives[i][2] - beehives[i][0]);
        edge(4 * i + 3, 4 * i, beehives[i][3] - beehives[i][1]);

        minTop[4 * i] = beehives[i][3];
        maxBot[4 * i + 1] = beehives[i][1];

        minRight[4 * i] = beehives[i][2];
        minRight[4 * i + 1] = beehives[i][2];

        maxLeft[4 * i + 3] = beehives[i][1];
        maxLeft[4 * i + 2] = beehives[i][1];

        minTop[4 * i + 3] = beehives[i][3];
        maxBot[4 * i + 2] = beehives[i][1];
    }

    // clockwise rect point
    auto pt = [&](int i, int e){
        array<int, 4> b = beehives[i];
        if (e == 0){
            return pair<int, int>{b[0], b[1]};
        } else if (e == 1){
            return pair<int, int>{b[0], b[3]};
        } else if (e == 2){
            return pair<int, int>{b[2], b[3]};
        } else {
            return pair<int, int>{b[2], b[1]};
        }
    };
    
    auto in_range = [&](int i, int j, pair<int, int> a, pair<int, int> b){
        bool ba = true;
        bool ab = true;
        if ((b.first < beehives[i][0] || b.first > beehives[i][2]) && (b.second > beehives[i][3] || b.second < beehives[i][1])){
            ba = false;
        }

        swap(a, b);
        swap(i, j);

        if ((b.first < beehives[i][0] || b.first > beehives[i][2]) && (b.second > beehives[i][3] || b.second < beehives[i][1])){
            ab = false;
        }

        return ba || ab;
    };

    // external rect
    for (int i = 0; i < n + 1; i++){
        for (int j = i + 1; j < n + 2; j++){
            for (int ae = 0; ae < 4; ae++){
                for (int be = 0; be < 4; be++){
                    pair<int, int> a = pt(i, ae);
                    int apt = 4 * i + ae;
                    pair<int, int> b = pt(j, be);
                    int bpt = 4 * j + be;
                    
                    if (!in_range(i, j, a, b)){
                        // can't go corner to corner
                        cout << "Spaced" << " " << i << " " << a.first << " " << a.second << " " << j << " " << b.first << " " << b.second << endl;
                        continue;
                    }

                    // check blockade
                    if (b.first > a.first){
                        if (b.second > a.second){
                            if (maxBot[bpt] > a.second) {
                                cout << "Can't Reach" << " " << i << " " << a.first << " " << a.second << " " << j << " " << b.first << " " << b.second << endl;
                                continue;
                            }
                        } else {
                            if (minTop[bpt] < a.second) {
                                cout << "Can't Reach" << " " << i << " " << a.first << " " << a.second << " " << j << " " << b.first << " " << b.second << endl;
                                continue;
                            }
                        }
                    } else {
                        if (a.second > b.second){
                            if (maxBot[apt] > b.second) {
                                cout << "Can't Reach" << " " << i << " " << a.first << " " << a.second << " " << j << " " << b.first << " " << b.second << endl;
                                continue;
                            }
                        } else {
                            if (minTop[apt] < b.second) {
                                cout << "Can't Reach" << " " << i << " " << a.first << " " << a.second << " " << j << " " << b.first << " " << b.second << endl;
                                continue;
                            }
                        }
                    }

                    // connected!
                    edge(apt, bpt, abs(a.first - b.first) + abs(a.second + b.second));

                    // update blockade
                    if (b.first <= beehives[i][2]){
                        if (b.second <= beehives[i][3]){
                            maxBot[bpt] = max(maxBot[bpt], beehives[i][3]);
                        } else {
                            minTop[bpt] = min(minTop[bpt], beehives[i][1]);
                        }
                    }
                }
            }
        }
    }

    v[4 * s] = 0;
    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0LL, 4 * s});

    while(!pq.empty()){
        auto [ndist, k] = pq.top();
        pq.pop();

        if (ndist != v[k]) { continue; }

        for (pair<int, ll> &node: adj[k]){
            if (ndist + node.second < v[node.first]){
                v[node.first] = ndist + node.second;
                pq.push({v[node.first], node.first});
            }
        }
    }

    cout << adj[4 * s].size() << endl;

    for (int i = 0; i < 4 * (n + 2); i++){
        cout << v[i] << endl;
    }

    if (v[4 * e] == LLONG_MAX){
        cout << "No Path" << endl;
        return;
    }

    cout << v[4 * e] << endl;
}

void solve2(){
    pair<int, int> start;
    pair<int, int> end;
    cin >> start.first >> start.second >> end.first >> end.second;

    int n; cin >> n;
    vector<array<int, 4>> rect(n);
    vector<int> xs = {start.first, end.first};
    vector<int> ys = {start.second, end.second};

    map<pair<int, int>, bool> real;
    map<pair<int, int>, bool> realBot;
    map<pair<int, int>, bool> realLeft;

    real[start] = true;
    real[end] = true;
    realBot[start] = false;
    realLeft[start] = false;
    realBot[end] = false;
    realLeft[end] = false;

    for (int i = 0; i < n; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a > c){
            swap(a, c);
        }
        if (b > d){
            swap(b, d);
        }

        realBot[{a, b}] = true;
        realLeft[{a, b}] = true;
        realBot[{a, d}] = false;
        realLeft[{a, d}] = true;
        realBot[{c, b}] = true;
        realLeft[{c, b}] = false;
        realBot[{c, d}] = false;
        realLeft[{c, d}] = false;

        real[{a, b}] = true;
        real[{a, d}] = true;
        real[{c, b}] = true;
        real[{c, d}] = true;

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

    vector<ll> d(xs.size() * ys.size(), LLONG_MAX);
    vector<vector<pair<int, ll>>> adj(xs.size() * ys.size());
    map<int, pair<int, int>> pIndex;

    int k = 0;
    int s, e;

    auto checkReal = [&](int a, int b){
        pair<int, int> pa = pIndex[a];
        pair<int, int> pb = pIndex[b];
        if (!real.contains(pa)){
            realLeft[pa] = (a >= ys.size() && realLeft[pIndex[a - ys.size()]]);
            realBot[pa] = (a >= 1 && realBot[pIndex[a - 1]]);
            real[pa] = false;
        }

        if (!real.contains(pb)){
            realLeft[pb] = (b >= ys.size() && realLeft[pIndex[b - ys.size()]]);
            realBot[pb] = (b >= 1 && realBot[pIndex[b - 1]]);
            real[pb] = false;
        }

        bool rla = realLeft[pa];
        bool rba = realBot[pa];
        bool ra = real[pa];
        bool rlb = realLeft[pb];
        bool rbb = realBot[pb];
        bool rb = real[pb];
        
        return (ra || rla || rba) && (rb || rlb || rbb) && (ra || rb || !((abs(a - b) == ys.size() && rba && rbb) || (abs(a - b) == 1 && rla && rlb)));
    };

    for (int i = 0; i < xs.size(); i++){
        for (int j = 0; j < ys.size(); j++){
            pair<int, int> p = {xs[i], ys[j]};

            pIndex[k] = p;

            if (p.first == start.first && p.second == start.second){
                s = k;
            }

            if (p.first == end.first && p.second == end.second){
                e = k;
            }

            if (i > 0 && checkReal(k, k - ys.size())){
                ll dist = abs(p.first - pIndex[k - ys.size()].first) + abs(p.second - pIndex[k - ys.size()].second);
                adj[k - ys.size()].pb({k, dist});
                adj[k].pb({k - ys.size(), dist});
            }

            if (j > 0 && checkReal(k, k - 1)){
                ll dist = abs(p.first - pIndex[k - 1].first) + abs(p.second - pIndex[k - 1].second);
                adj[k].pb({k - 1, dist});
                adj[k - 1].pb({k, dist});
            }

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

        // cout << pIndex[kk].first << " " << pIndex[kk].second << " " << ndist << endl;

        if (ndist != d[kk]) { continue; }

        for (pair<int, ll> &node: adj[kk]){
            if (ndist + node.second < d[node.first]){
                d[node.first] = ndist + node.second;
                pq.push({d[node.first], node.first});
            }
        }
    }

    if (d[e] == LLONG_MAX){
        cout << "No Path" << endl;
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