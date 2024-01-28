#include <bits/stdc++.h>

using namespace std;

int main(){
    string x;
    cin >> x;
    char n = x[0];
    int ans = 1;
    int c = 1;
    for (int i = 1; i < x.length(); i++){
        if (x[i] != n){
            n = x[i];
            ans = max<int> (ans, c);
            c = 0;
        }
        c ++;
    }
    cout << max<int> (ans, c);
    return 0;
}