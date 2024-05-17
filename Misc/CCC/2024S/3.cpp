/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<pair<int, int>> blocks;
    vector<int> ans;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = x;
    }

    int prev = 0;

    for (int i = 0; i < n; i++){
        int y;
        cin >> y;
        b[i] = y;

        if (y != prev){
            blocks.pb(make_pair(y, i));
            prev = y;
        }
    }

    vector<int> right;
    int block = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == blocks[block].first){
            block++;
            right.pb(i);
        }

        if (block == blocks.size()){
            break;
        }
    }

    if (block != blocks.size()){
        cout << "NO" << endl;
        return;
    }   

    cout << "YES" << endl;

    // reverse(right.begin(), right.end());

    vector<vector<int>> sequence;

    for (int i = 0; i < blocks.size(); i++){
        if (right[i] > blocks[i].second){
            sequence.pb(vector<int>{0, blocks[i].second, right[i]});
        }

        if (right[i] < blocks[i].second){
            if (i < blocks.size() - 1 && right[i + 1] - 1 < blocks[i].second){
                sequence.pb(vector<int>{1, right[i + 1] - 1, blocks[i + 1].second - 1});
            }
            sequence.pb(vector<int>{1, right[i] - 1, blocks[i].second - 1});
        }
    }

    if (blocks[blocks.size() - 1].first != a[n - 1]){
        sequence.pb(vector<int>{1, blocks[blocks.size() - 1].second, n - 1});
    }

    cout << sequence.size() << endl;
    for (int i = 0; i < sequence.size(); i++){
        vector<int> s = sequence[i];
        cout << (s[0] == 0 ? "L ":"R ") << s[1] << " " << s[2] << endl;
    }

    /**
    for (int i = 0; i < right.size(); i++){
        cout << "R " << right[i] << " " << n - 1 - i << endl;
    }

    for (int i = 0; i < blocks.size(); i++){
        cout << "L " << blocks[i].second << " " << n - blocks.size() + i << endl;
    }
    **/
}

/**
 * vector<vector<int>> ans;
    vector<vector<int>> temp;
    bool chain = false;
    bool backtrack = false;
    int wrong = 0;
    //int backIndex = 

    for (int i = 0; i < n; i++){
        int target = b[i];
        if (a[i] != target){
            if (i > 0 && a[i - 1] == target){
                temp.pb({1, i - 1, i});
                chain = true;
            }
            else {
                if (chain){
                    reverse(temp.begin(), temp.end());
                    for (int j = 0; j < temp.size(); j++){
                        ans.pb(temp[j]);
                    }
                    temp = {};
                    a[i - 1] = a[i - 2];
                    chain = false;
                    i--;
                    continue;
                }

                if (i < n - 1 && a[i + 1] == target){
                    ans.pb({0, i, i + 1});
                    a[i] = target;
                    if (backtrack){
                        wrong--;
                    }
                    if (i > 0){
                        i-= 2;
                        backtrack = true;
                    } else {
                        if (wrong > 0){
                            cout << "NO" << endl;
                            return;
                        }
                        backtrack = false;
                    }
                    continue;
                }
                else {
                    wrong++;
                    if (backtrack){
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        } else {
            if (wrong > 0){
                cout << "NO" << endl;
                return;
            }
            backtrack = false;
            if (chain){
                reverse(temp.begin(), temp.end());
                for (int j = 0; j < temp.size(); j++){
                    ans.pb(temp[j]);
                }
                a[i - 1] = a[i - 2];
                temp = {};
                chain = false;
            }
        }
    }

    if (wrong > 0){
        cout << "NO" << endl;
        return;
    }

    if (chain){
        reverse(temp.begin(), temp.end());
        for (int j = 0; j < temp.size(); j++){
            ans.pb(temp[j]);
        }
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (vector<int> j : ans){
        cout << (j[0] == 1 ? "R":"L") << " " << j[1] << " " << j[2] << endl;
    }
 * 
 */

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}