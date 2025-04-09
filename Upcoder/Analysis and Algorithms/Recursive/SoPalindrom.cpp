#include <iostream>
using namespace std;

int ReverseNumber(int n, int rev = 0) {
    if(n == 0) return rev;
    return ReverseNumber(n / 10, rev * 10 + n % 10);
}

bool IsPalindrom(int n) {
    return n == ReverseNumber(n);
}

int main() {
    int n;
    cin >> n;
    int *p = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    for(int i = 0; i < n; i++) {
        if(IsPalindrom(p[i]))
            cout << p[i] << " ";
    }
    
    return 0;
}
