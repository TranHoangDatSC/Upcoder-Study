// Viết hàm tính tổng các số lẻ/chẵn 

#include <iostream>
using namespace std;

int sum_odd(int n) {
    if(n == 0) return 0;
    else if(n % 2 == 0) return sum_odd(n-1);
    return n + sum_odd(n - 1);
}
int sum_even(int n) {
    if(n == 0) return 0;
    else if(n % 2 != 0) return sum_even(n-1);
    return n + sum_even(n - 1);
}
int main() {
    int n;
    cin >> n;
    cout << sum_even(n);
    return 0;
}
