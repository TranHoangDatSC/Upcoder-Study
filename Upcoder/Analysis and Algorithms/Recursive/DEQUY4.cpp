#include <iostream>
using namespace std;

int Pow(int n, int x) {
    if(n == 0) return 1;
    return x * Pow(n - 1, x);
}

int Sum(int n, int x) {
    if(n == 0) return 1;
    return Pow(n,x) + Sum(n - 1, x);
}

int main() {
    int n, x;
    cin >> n >> x;
    cout << Sum(n,x);
    return 0;
}
