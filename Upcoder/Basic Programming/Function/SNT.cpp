#include <bits/stdc++.h>
using namespace std;

bool ktSNT(int n);

int main () {
    int n;
    cin >> n;
  
    if (ktSNT(n)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}

bool ktSNT(int n) {
    if (n < 2) {
        return false;
    }
    else {
        for (int i = 2; i <= sqrt((float)n); i++) { 
            if (n % i == 0) 
                return false;
        }
    }          
    return true;
}
