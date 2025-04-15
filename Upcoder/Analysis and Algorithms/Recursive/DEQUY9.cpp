#include <iostream>
using namespace std;

long Factorial(long n) {
    if(n <= 1) return 1;
    return Factorial(n - 1) * n;
}
long Sum(long n) {
    if(n == 0) return 0;
    return Sum(n - 1) + n;
}
long SumS(long n) {
    if(n == 0) return 0;
    return SumS(n - 1) + Sum(n);
}
long SumP(long n) {
    if(n == 0) return 0;
    return SumP(n - 1) + Factorial(n);
}

int main() {
    long n;
    cin >> n;
    cout << "S(" << n << ") = " << SumS(n) << "\n";
    cout << "P(" << n << ") = " << SumP(n);
    return 0;
}
