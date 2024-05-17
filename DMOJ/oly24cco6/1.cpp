/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-10
 * Contest: Olympiads School CCO Training Contest 6
 * Problem: 1
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> nums;
    vector<pair<int, int>> palindrome(n + 1, {-1, -1});
    string ans = "";
    string rev_ans = "";
    for (int i = 0; i < 2 * n; i++){
        int a; cin >> a;
        nums.pb(a);
        if (palindrome[a].first < 0){
            palindrome[a].first = i;
        } else {
            palindrome[a].second = i;
        }
    }

    int failed = false;

    ans += "L";
    rev_ans += "L";
    int aStart = 0;
    int aEnd = palindrome[nums[aStart]].second;
    int bEnd = aEnd;
    int bStart = 2 * n - 1;
    aStart++;
    for (int i = 0; i < n - 1; i++){
        if (aStart < aEnd){
            if (aStart < aEnd - 1 && nums[aStart] == nums[aEnd - 1]){
                ans += "L";
                rev_ans += "L";
                aStart++;
                aEnd--;
                continue;
            } 
            
            if (bEnd < bStart && nums[aStart] == nums[bEnd + 1]){
                ans += "L";
                rev_ans += "R";
                aStart++;
                bEnd++;
                continue;
            }
        }

        if (bEnd < bStart){
            if (bEnd < bStart - 1 && nums[bStart] == nums[bEnd + 1]){
                ans += "R";
                rev_ans += "R";
                bEnd++;
                bStart--;
                continue;
            } 
            
            if (aStart < aEnd && nums[bStart] == nums[aEnd - 1]){
                ans += "R";
                rev_ans += "L";
                bStart--;
                aEnd--;
                continue;
            }
        }

        failed = true; break;
    }

    if (failed){
        ans = "R";
        rev_ans = "L";
        bStart = 2 * n - 1;
        bEnd = palindrome[nums[bStart]].first;
        aStart = 0;
        aEnd = bEnd;
        bStart--;
        for (int i = 0; i < n - 1; i++){
            if (aStart < aEnd){
                if (aStart < aEnd - 1 && nums[aStart] == nums[aEnd - 1]){
                    ans += "L";
                    rev_ans += "L";
                    aStart++;
                    aEnd--;
                    continue;
                }
                
                if (bEnd < bStart && nums[aStart] == nums[bEnd + 1]){
                    ans += "L";
                    rev_ans += "R";
                    aStart++;
                    bEnd++;
                    continue;
                }
            }

            if (bEnd < bStart){
                if (bEnd < bStart - 1 && nums[bStart] == nums[bEnd + 1]){
                    ans += "R";
                    rev_ans += "R";
                    bEnd++;
                    bStart--;
                    continue;
                } 
                
                if (aStart < aEnd && nums[bStart] == nums[aEnd - 1]){
                    ans += "R";
                    rev_ans += "L";
                    bStart--;
                    aEnd--;
                    continue;
                }
            }

            cout << -1 << endl;
            return;
        }
    }

    reverse(rev_ans.begin(), rev_ans.end());
    cout << (ans + rev_ans) << endl;
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