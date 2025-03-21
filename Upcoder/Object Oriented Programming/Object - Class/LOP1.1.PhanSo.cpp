#include <iostream>
using namespace std;

class PhanSo {
    private:
        int tu,mau;
    public:
        void nhap();
        void xuat();
};

int main() {
    PhanSo a,b;
    a.nhap();
    a.xuat();
    return 0;
}

void PhanSo::nhap() {
    cin >> tu >> mau;
}
void PhanSo::xuat() {
    cout << tu << "/" << mau;
}
