/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-01
 * Contest: Codeforces 782
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const double EPSILON = 1e-7;
 
// Misread the problem...

/**
void solve(){
    int n; cin >> n;
    
    vector<double> coords(n);
    for (int i = 0; i < n; i++){
        double c; cin >> c;
        coords[i] = c;
    }

    vector<double> speeds(n);

    for (int i = 0; i < n; i++){
        double s; cin >> s;
        speeds[i] = s;
    }

    vector<pair<double, double>> people(n);
    for (int i = 0; i < n; i++){
        people[i] = make_pair(coords[i], speeds[i]);
    }

    sort(people.begin(), people.end());

    double left = 0, right = 0;
    double leftinv = 0, rightinv = 0;

    for (int i = 1; i < n; i++){
        right += (people[i].first - people[0].first)/people[i].second;
        rightinv += 1/people[i].second;
    }

    double ans = left + right;

    cout << ans << endl;

    for (int i = 1; i < n; i++){
        leftinv += 1/people[i - 1].second;

        left += (people[i].first - people[i - 1].first) * leftinv;
        right -= (people[i].first - people[i - 1].first) * rightinv;

        rightinv -= 1/people[i].second;

        ans = min(ans, left + right);
    }

    cout << ans << endl;
}
**/

void solve(){
    int n; cin >> n;
    
    vector<double> coords(n);

    double left = 0, right = 1e15;
    for (int i = 0; i < n; i++){
        double c; cin >> c;
        coords[i] = c;
    }

    vector<double> speeds(n);

    for (int i = 0; i < n; i++){
        double s; cin >> s;
        speeds[i] = s;
    }

    while (right - left > EPSILON){
        double time = (left + right)/2.0;
        double mx = 1e15, mn = 0;
        for (int i = 0; i < n; i++){
            mx = min(mx, coords[i] + speeds[i] * time);
            mn = max(mn, coords[i] - speeds[i] * time);
        }

        if (mx > mn){
            right = time;
        } else {
            left = time;
        }
    }

    cout << setprecision(10) << left << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}