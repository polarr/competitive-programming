/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-28
 * Contest: DMOJ Spring Coding Bowl 2024
 * Problem: 5
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

using T = pair<ll, pair<int, int>>;

const vector<pair<int, int>> cardinal = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(){
    int n, m;

	cin >> n >> m;

    vector<vector<ll>> grass(n, vector<ll>(m));
    vector<vector<ll>> dist(n, vector<ll>(m, LLONG_MAX));
    vector<vector<ll>> rev_dist(n, vector<ll>(m, LLONG_MAX));
    vector<ll> ans(n, LLONG_MAX);
    vector<ll> min_row(n, LLONG_MAX);
    vector<ll> rev_ans(n, LLONG_MAX);


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ll g; cin >> g;
            grass[i][j] = g;
            min_row[i] = min(min_row[i], g);
        }
    }
    

	priority_queue<T, vector<T>, greater<T>> pq;
    priority_queue<T, vector<T>, greater<T>> rev_pq;

	pair<int, int> start = {0, 0};
	dist[0][0] = 0LL;
	pq.push({0LL, start});

	while (!pq.empty()) {
		const auto [cdist, node] = pq.top();
		pq.pop();

		if (cdist != dist[node.first][node.second]) { continue; }

		for (const pair<int, int> add: cardinal) {
            int ny = node.first + add.first;
            int nx = node.second + add.second;
            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1){
                continue;
            }

			if (cdist + grass[ny][nx] < dist[ny][nx]) {
				pq.push({dist[ny][nx] = cdist + grass[ny][nx], {ny, nx}});
                ans[ny] = min(ans[ny], dist[ny][nx]);
			}
		}
	}

    pair<int, int> rev_start = {n - 1, m - 1};
	rev_dist[n - 1][m - 1] = 0LL;
	pq.push({0LL, rev_start});

	while (!pq.empty()) {
		const auto [cdist, node] = rev_pq.top();
		rev_pq.pop();

		if (cdist != rev_dist[node.first][node.second]) { continue; }

		for (const pair<int, int> add: cardinal) {
            int ny = node.first + add.first;
            int nx = node.second + add.second;
            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1){
                continue;
            }

			if (cdist + grass[ny][nx] < rev_dist[ny][nx]) {
				pq.push({rev_dist[ny][nx] = cdist + grass[ny][nx], {ny, nx}});
                rev_ans[ny] = min(rev_ans[ny], cdist);
			}
		}
	}

    vector<ll> ans_rows;
    ll mn = LLONG_MAX;
    for (int i = 0; i < ans.size(); i++){
        mn = min(mn, ans[i] + rev_ans[i] + min_row[i]);
    }

    for (int i = 0; i < ans.size(); i++){
        if(ans[i] + rev_ans[i] + min_row[i] == mn){
            ans_rows.pb(i);
        }
    }

    cout << mn << " " << ans_rows.size() << endl;
    cout << ans_rows[0];
    for (int i = 1; i < ans_rows.size(); i++){
        cout << " " << ans_rows[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}