/**
 * Solution by 1egend
 * Date: 7/9/2021
 * Contest: USACO 
 * Problem:
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "lineup";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

const vector<string> cowNames = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
int nameToIndex(string cow){
    for (int i = 0; i < 8; ++i){
        if (cow == cowNames[i]){
            return i;
        }
    }

    return -1;
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    fin >> n;
    vector <pair<int, int>> constraints;
    for (int i = 0; i < n; ++i){
        pair<int, int> p;
        for (int k = 0; k < 6; ++k){
            static string t;
            fin >> t;
            if (k == 0){
                p.first = nameToIndex(t);
                continue;
            }

            if (k == 5){
                p.second = nameToIndex(t);
            }
        }
        constraints.pb(p);
    }
    vector<int> ans = {0, 1, 2, 3, 4, 5, 6, 7};
    do {
        bool isAns = true;
        for (int i = 0; i < n; ++i){
            pair <int, int> c = constraints[i];
            for (int k = 0; k < 7; ++k){
                if (ans[k] == c.first){
                    if (ans[k + 1] != c.second){
                        isAns = false;
                    }
                    break;
                }

                if (ans[k] == c.second){
                    if (ans[k + 1] != c.first){
                        isAns = false;
                    }
                    break;
                }
            }

            if (!isAns){
                break;
            }
        }

        if (!isAns){
            continue;
        }

        for (int i = 0; i < 8; ++i){
            fout << cowNames[ans[i]] << endl;
        }
        break;
    } while(next_permutation(ans.begin(), ans.end()));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}