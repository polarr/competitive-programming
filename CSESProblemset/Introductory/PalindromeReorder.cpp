#include <bits/stdc++.h>

using namespace std;

int main(){
    string x;
    cin >> x;
    sort(x.begin(), x.end());

    string ans = "";
    string second = "";
    string mid = "";
    int count = 0;
    for (int i = 0; i < x.size(); ++i){
        count ++;
        if ((i == x.size() - 1 || x[i] != x[i + 1]) && count % 2 == 1){
            if (mid.size() == 0){
                mid += x[i];
                count = 0;
                continue;
            }
            cout << "NO SOLUTION";
            return 0;
        }

        if (i % 2 == 0){
            ans += x[i];
        }
        else{
            second += x[i];
        }
    }
    reverse(second.begin(), second.end());
    cout << (ans + mid + second);
    return 0;
}