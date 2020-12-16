/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void printAns(string res){
    bool back = false;
    int sum = 0;
    for (int i = 0; i < res.length(); ++i){
        if (res[i] == 'W'){
            if (back){
                sum += 2;
            }
            else{
                sum += 1;
            }
            back = true;
        }
        else{
            back = false;
        }
    }   
    cout << sum << endl;
}
void solve(){
    int x, c;
    cin >> x >> c;
    string res;
    cin >> res;
    int lastChunk = 0;
    int dis = 1;
    int count = 0;
    while(c > 0 && count < x){
        count = 0;
        for (int i = 0; i < x; ++i){
            if (res[i] == 'W'){
                if (lastChunk - i - 1 == dis){
                    for (int n = lastChunk + 1; n < i; ++n){
                        if (c == 0){
                            printAns(res);
                            return;
                        }
                        res[n] = 'W';
                        c--;
                    }
                }
                lastChunk = i;
                count ++;
            }
        }
        dis ++;
    }
    printAns(res);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        // cout << "Case #" << t  << ": " << endl;
        solve();
    }
    return 0;
}