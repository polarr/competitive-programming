/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-19
 * Contest: USACO 2024 February Contest
 * Problem: P2. Test Tubes
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, p;
    cin >> n >> p;

    stack<int> first;
    int firstBase;
    int secondBase;
    stack<int> second;

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++){
        int f;
        cin >> f;
        if (i == 0){
            firstBase = f;
            first.push(f);
            continue;
        }

        if (f != first.top()){
            first.push(f);
        }
    }

    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        if (i == 0){
            secondBase = s;
            second.push(s);
            continue;
        }

        if (s != second.top()){
            second.push(s);
        }
    }

    stack<int> third;

    if (first.size() == 1 && second.size() == 1){
        cout << 0 << endl;
        return;
    }

    if (first.size() == 1){
        while (second.size() > 1){
            if (second.top() == first.top()){
                ans.pb(make_pair(2, 1));
            } else {
                ans.pb(make_pair(2, 3));
                third.pop();
                third.push(second.top());
            }

            second.pop();
        }

        if (third.size() > 0){
            if (second.top() == first.top()){
                ans.pb(make_pair(2, 1));
            }

            ans.pb(make_pair(3, 2));
        }
    }
    else if (second.size() == 1){
        while (first.size() > 1){
            if (second.top() == first.top()){
                ans.pb(make_pair(1, 2));
            } else {
                ans.pb(make_pair(1, 3));
                third.pop();
                third.push(first.top());
            }

            first.pop();
        }

        if (third.size() > 0){
            if (second.top() == first.top()){
                ans.pb(make_pair(1, 2));
            }

            ans.pb(make_pair(3, 1));
        }
    }
    else if (firstBase != first.top()){
        while (second.size() > 1){
            if (third.size() == 0){
                third.push(first.top());
                first.pop();
                ans.pb(make_pair(1, 3));
                continue;
            }

            if (second.top() == third.top()){
                ans.pb(make_pair(2, 3));
            } else {
                ans.pb(make_pair(2, 1));
            }

            second.pop();
        }

        if (first.size() == 1){
            if (second.top() == first.top()){
                ans.pb(make_pair(2, 1));
            }

            ans.pb(make_pair(3, 2));
        }
    } else if (secondBase != second.top()){
        while (first.size() > 1){
            if (third.size() == 0){
                third.push(second.top());
                second.pop();
                ans.pb(make_pair(2, 3));
                continue;
            }

            if (first.top() == third.top()){
                ans.pb(make_pair(1, 3));
            } else {
                ans.pb(make_pair(1, 2));
            }

            first.pop();
        }

        if (second.size() == 1){
            if (first.top() == second.top()){
                ans.pb(make_pair(1, 2));
            }

            ans.pb(make_pair(3, 1));
        }
    } else {
        while (second.size() > 1){
            if (third.size() == 0){
                third.push(first.top());
                first.pop();
                ans.pb(make_pair(1, 3));
                continue;
            }

            if (second.top() == third.top()){
                ans.pb(make_pair(2, 3));
            } else {
                ans.pb(make_pair(2, 1));
            }

            second.pop();
        }

        while (first.size() > 1){
            if (third.size() == 0){
                third.push(second.top());
                second.pop();
                ans.pb(make_pair(2, 3));
                continue;
            }

            if (first.top() == third.top()){
                ans.pb(make_pair(1, 3));
            } else {
                ans.pb(make_pair(1, 2));
            }

            first.pop();
        }

        ans.pb(make_pair(3, 1));
    }

    cout << ans.size() << endl;

    if (p == 1){
        return;
    }

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }


    /**
    if (first.size() == 1 && second.size() == 1){
        cout << 0 << endl;
        return;
    }

    if (firstBase == secondBase){
        cout << first.size() + second.size() << endl;
    } else {
        cout << first.size() + second.size() - 1 << endl;
    }

    if (p == 1){
        return;
    }

    if (firstBase == secondBase){
        
    } else {

    }
    **/
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