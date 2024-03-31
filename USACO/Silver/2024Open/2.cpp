/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-03-18
 * Contest: USACO 2024 Open
 * Problem: Silver P2. Painting Fence Posts
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

ull d(pair<int, int> a, pair<int, int> b){
    return (ull)(abs((ll)a.first - (ll)b.first) + abs((ll)a.second - (ll)b.second));
}

void solve(){
    int n, p;
    cin >> n >> p;

    vector<pair<int, int>> posts;
    vector<ull> dist;

    unordered_map<int, set<int>> postsX;
    unordered_map<int, set<int>> postsY;
    unordered_map<int, unordered_map<int, int>> pos;

    int ldx = INT_MAX;
    int ldy = INT_MAX;
    int dlx = INT_MAX;
    int dly = INT_MAX;
    int rux = 0;
    int ruy = 0;
    int urx = 0;
    int ury = 0;
    for (int i = 0; i < p; i++){
        int x, y;
        cin >> x >> y;

        if (x < ldx){
            ldx = x;
            ldy = y;
        } else if (x == ldx && y < ldy){
            ldy = y;
        }

        if (y < dly){
            dlx = x;
            dly = y;
        } else if (y == dly && x < dlx){
            dlx = x;
        }

        if (x > rux){
            rux = x;
            ruy = y;
        } else if (x == rux && y > ruy){
            ruy = y;
        }

        if (y > ury){
            urx = x;
            ury = y;
        } else if (y == ury && x > urx){
            urx = x;
        }

        postsX[x].insert(y);
        postsY[y].insert(x);
    }

    posts.pb(make_pair(ldx, ldy));
    pos[ldx][ldy] = 0;
    ull total = 0;
    dist.pb(0);
    bool vert = true;
    bool up = true;
    bool right = true;
    pair<int, int> curr;
    for (int i = 1; i < p; i++){
        pair<int, int> prev = posts[i - 1];

        if (prev.first == urx && prev.second == ury){
            up = false;
        }

        if (prev.first == rux && prev.second == ruy){
            right = false;
        }

        if (prev.first == dlx && prev.second == dly){
            up = true;
        }

        if (vert){
            if (up){
                curr = make_pair(prev.first, *postsX[prev.first].upper_bound(prev.second));
            } else {
                curr = make_pair(prev.first, *(--postsX[prev.first].lower_bound(prev.second)));
            }
        } else {
            if (right){
                curr = make_pair(*postsY[prev.second].upper_bound(prev.first), prev.second);
            } else {
                curr = make_pair(*(--postsY[prev.second].lower_bound(prev.first)), prev.second);
            }
        }

        pos[curr.first][curr.second] = i;
        posts.pb(curr);
        total += d(prev, curr);
        dist.pb(total);
        vert = !vert;
    }

    total += d(curr, posts[0]);

    int all = 0;
    vector<int> prefix(p);

    for (int i = 0; i < n; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        int left1, right1, up1, down1;
        int start;
        ull startDist;
        int left2, right2, up2, down2;
        ull endDist;

        if (postsY[y].size() > 0 && postsY[y].count(x) > 0){
            start = pos[x][y];
        } else {
            left1 = *(--postsY[y].upper_bound(x));
            right1 = *postsY[y].upper_bound(x);
            down1 = *(--postsX[x].upper_bound(y));
            up1 = *postsX[x].upper_bound(y);

            if ((abs(pos[left1][y] - pos[right1][y]) % (p - 1)) <= 1){
                if (pos[left1][y] < pos[right1][y] && pos[left1][y] != 0){
                    start = pos[left1][y];
                } else {
                    start = pos[right1][y];
                }
            } else {
                if (pos[x][up1] < pos[x][down1]){
                    start = pos[x][up1];
                } else {
                    start = pos[x][down1];
                }
            }
        }

        if (postsY[b].size() > 0 && postsY[b].count(a) > 0){
            end = pos[a][b];
        } else {
            left2 = *(--postsY[b].upper_bound(a));
            right2 = *postsY[b].upper_bound(a);
            down2 = *(--postsX[a].upper_bound(b));
            up2 = *postsX[a].upper_bound(b);

            if ((abs(pos[left2][b] - pos[right2][b]) % (p - 1)) <= 1){
                if (pos[left2][b] < pos[right2][b] && pos[left2][b] != 0){
                    end = pos[left2][b];
                } else {
                    end = pos[right2][b];
                }
            } else {
                if (pos[a][up2] < pos[a][down2]){
                    end = pos[a][up2];
                } else {
                    end = pos[a][down2];
                }
            }
        }

        ull startDist = dist[start] + d(make_pair(x, y), posts[start]);
        ull endDist = dist[end] + d(make_pair(a, b), posts[end]);

        if (startDist > endDist){
            swap(start, end);
            swap(startDist, endDist);
        }

        ull route = endDist - startDist;

        if (route > total - route){
            if (d(make_pair(x, y), posts[start]) > 0 && start < p - 1){
                prefix[start + 1]++;
            } else {
                prefix[start]++;
            }
            
            if (end < p - 1){
                prefix[end + 1]--;
            }
        } else {
            all++;
            prefix[start + 1]--;
            prefix[end]++;
        }
    }
    
    int cumu = all;
    for (int i = 0; i < p; i++){
        cumu += prefix[i];
        cout << cumu << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}