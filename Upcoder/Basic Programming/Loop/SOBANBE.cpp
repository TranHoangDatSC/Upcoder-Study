#include <iostream>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    int sa = 0, sb = 0;
    
    for(int i = 1; i < a; i++) {
        if(a % i == 0) {
            sa += i;
        }
    }
    for(int i = 1; i < b; i++) {
        if(b % i == 0) {
            sb += i;
        }
    }
    if(sa == b && sb == a) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
