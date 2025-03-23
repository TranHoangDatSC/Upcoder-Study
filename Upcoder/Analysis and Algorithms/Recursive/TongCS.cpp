#include <iostream>
using namespace std;

int TongCS(int n) {
    if(n < 10) return n;
    return n % 10 + TongCS(n / 10);
}

int main() {
    int n;
    cin >> n;
    cout << TongCS(n);
    return 0;
}
