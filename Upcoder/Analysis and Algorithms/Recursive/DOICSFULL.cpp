#include <iostream>
using namespace std;

string soHe16 = "0123456789ABCDEF";

void DoiCoSo(long n, int base) {
    if (n == 0) return;
    DoiCoSo(n / base, base);
    cout << soHe16[n % base];
}

int main() {
    long soHe10;
    int soHeMoi;
    cin >> soHe10 >> soHeMoi;

    if (soHe10 == 0) cout << 0;
    else DoiCoSo(soHe10, (soHeMoi == 0 ? 2 : (soHeMoi == 1 ? 8 : 16)));

    return 0;
}
