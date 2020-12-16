#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long x;
    cin >> x;
    unsigned long long s = x * (x + 1)/2;
    if (s % 2 == 1){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    s/= 2;
    vector <int> a;
    vector <int> b;
    for (unsigned long long i = x; i >= 1; --i){
        if (s >= i){
            s -= i;
            a.push_back(i);
            continue;
        }
        b.push_back(i);
    }
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl << b.size() << endl;
    for (int i = 0; i < b.size(); ++i){
        cout << b[i] << " ";
    }
    return 0;
}