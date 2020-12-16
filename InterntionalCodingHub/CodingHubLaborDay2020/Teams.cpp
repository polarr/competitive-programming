/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> x;
vector <int> t;
vector <int> teams;
vector <int> tt;
int ans = INT_MAX;
int checkTeam(int start, int end){
    for (int i = 0; i < tt.size(); ++i){
        for (int k = start; k <= end; ++k){
            if (tt[i] == t[x[k].second]){
                break;
            }
            if (k == end){
                return -1;
            }
        }
    }

    return x[end].first - x[start].first;
}
int main(){
    int l;
    cin >> l;
    for (int i = 0; i < l; ++i){
        int a, b;
        cin >> a >> b;
        x.push_back(make_pair(a, i));
        t.push_back(b);
    }
    sort(x.begin(), x.end());
    teams = t;
    sort(teams.begin(), teams.end());
    for (int i = 1; i < teams.size(); ++i){
        if (teams[i] != teams[i - 1]){
            tt.push_back(teams[i - 1]);
        }
    }
    tt.push_back(teams[teams.size() - 1]);
    for (int start = 0; start < x.size() - tt.size() + 1; ++start){
        for (int end = start + tt.size() - 1; end < x.size(); ++ end){
            if (t[x[start].second] == t[x[end].second]){
                break;
            }
            int n = checkTeam(start, end);
            if (n == -1){
                continue;
            }
            ans = min<int>(ans, n);
            if (ans == tt.size()){
                cout << ans;
                return 0;
            }
            break;
        }
    }
    cout << ans;
    return 0;
}
