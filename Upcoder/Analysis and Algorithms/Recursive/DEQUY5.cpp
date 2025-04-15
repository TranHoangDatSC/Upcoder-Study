#include <iostream>
#include <cmath>
using namespace std;

double Pow(int n, int x) {
    if(n == 0) return 1;
    return x * Pow(n - 1, x);
}

double Factorial(int n) {
    if(n <= 1) return 1;
    return n * Factorial(n - 1);
}

double Sum(int n, int x) {
    if(n == 0) return 1 + x;
    return Pow(2*n + 1,x)/Factorial(2*n + 1) + Sum(n - 1,x);
}

int main() {
    int n, x;
    cin >> n >> x;
    double result = Sum(n,x);
    result = roundf(result * 1000) / 1000;
    cout << result;
    return 0;
}
