// Đề kêu tính sin(sin(...sin(x))) n lần

#include <iostream>
#include <cmath>
using namespace std;

double Nested_Sin(int n,int x) {
    if(n == 0) return x;
    return sin(Nested_Sin(n - 1, x));
}

int main() {
    int n,x;
    cin >> n;
    cin >> x;
    
    cout << Nested_Sin(n,x);

    return 0;
}
