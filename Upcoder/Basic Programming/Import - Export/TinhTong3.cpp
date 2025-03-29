#include <iostream>
using namespace std;

int LastNumber(int n) {
    if(n < 10) return n;
    return LastNumber(n % 10);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << LastNumber(a) + LastNumber(b);
    return 0;
}
