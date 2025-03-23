// Đề bài kêu tính cos(x) + sin(x) + cos(2x) + sin(2x) +... + cos(nx) + sin(nx)

#include <iostream>
#include <cmath>
using namespace std;

double Algorithm(int n,int x) {
    if(n == 0) return 0;
    return cos(n*x) + sin(n*x) + Algorithm(n - 1, x) ;
}

int main() {
    int n,x;
    cin >> n;
    cin >> x;
    
    cout << Algorithm(n,x);

    return 0;
}
