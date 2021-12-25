#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    if (x == 1){
        cout << 1;
    }
    else if (x <= 3){
        cout << "NO SOLUTION";
    }
    else{
        for (int i = 2; i <= x; i+= 2){
            cout << i << " ";
        }
        for (int i = 1; i <= x; i+= 2){
            cout << i << " ";
        }
    }

    return 0;
}