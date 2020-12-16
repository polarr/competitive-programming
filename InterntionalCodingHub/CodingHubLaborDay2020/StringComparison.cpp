/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

bool checkString(string n, string m){
    for (int i = 0; i < m.length(); ++i){
        if (n.find(m[i]) == string::npos){
            return false;
        }
    }

    return true;
}
int main(){
    string n, m;
    cin >> n >> m;
    int ans = INT_MAX;
    for (int a = 0; a < n.length() - 1; ++a){
        for (int b = a + 1; b < n.length(); ++b){
            if (checkString(n.substr(a, b - a + 1), m)){
                ans = min<int>(ans, b - a + 1);
            }
        }
    }
    cout << (ans == INT_MAX ? "N/A": to_string(ans));
    return 0;
}

