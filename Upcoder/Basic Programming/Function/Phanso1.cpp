#include <iostream>
using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

void nhapPhanSo(PhanSo &ps) {
    cin >> ps.tu >> ps.mau;
}

PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo tong;
    
    tong.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    tong.mau = ps1.mau * ps2.mau;
    
    int ucln = gcd(abs(tong.tu), abs(tong.mau));
    tong.tu /= ucln;
    tong.mau /= ucln;

    if (tong.mau < 0) {  
        tong.tu = -tong.tu;
        tong.mau = -tong.mau;
    }

    return tong;
}

void xuatPhanSo(PhanSo ps) {
    cout << ps.tu << "/" << ps.mau;
}

int main() {
    
    PhanSo ps1, ps2;
    
    nhapPhanSo(ps1);
    nhapPhanSo(ps2);

    if (ps1.mau == 0 || ps2.mau == 0) {
        cout << -1; 
    } 
    
    else {
        PhanSo kq = tongPhanSo(ps1, ps2);
        xuatPhanSo(kq);
    }

    return 0;
}
