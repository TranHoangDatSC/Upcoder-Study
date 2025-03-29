#include <iostream>
using namespace std;

void Solve(int n) {
    if(n % 3 == 0) 
        cout << n << " chia het cho 3" ;
    else if(n % 3 != 0)
        cout << n << " chia 3 du " << n % 3;
    else if(n < 3)
        cout << n << " be hon 3";
    else 
        cout << "Loi";
}

int main() {
    int n;
    cin >> n;
    Solve(n);
    return 0;
}
