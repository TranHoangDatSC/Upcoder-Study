#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, n, a[100], tong = 0;
    
    while(cin >> x) {
        a[n++] = x;
    }
    for(int i = 0 ; i < n; i++) {
        double k = sqrt(a[i]);
        if(k == (int)k) 
            tong += a[i];
    }
    cout << tong;
    
    return 0;
}
