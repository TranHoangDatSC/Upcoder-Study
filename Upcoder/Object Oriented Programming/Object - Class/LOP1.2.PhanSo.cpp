#include <iostream>
using namespace std;

class PhanSo {
    private: 
        int tu,mau;
        
    public:
            
        int gcd(int a,int b) {
            if(b == 0) return a;
            return gcd(b,a%b);
        }
    
        // Nhập, xuất.
        friend istream& operator >> (istream& is, PhanSo& ps);
        friend ostream& operator << (ostream& os, PhanSo ps);
        
        // Lấy tử số, mẫu số.
        void setTu(int k) { tu = k; }
        void setMau(int k) { mau = k; }
        int getTu() { return this->tu; }
        int getMau() { return this->mau; }
        
        // Gán giá trị cho tử số, mẫu số.
      
        PhanSo() : tu(0), mau(1) {}
        PhanSo(int _tu, int _mau) : tu(_tu), mau(_mau) { 
            RutGon(); 
        }
        
        PhanSo(int n) : tu(n), mau(n) {}
        PhanSo(const PhanSo& ps) : tu(ps.tu), mau(ps.mau) {}
        
        // Nghịch đảo, rút gọn.
        void NghichDao();
        void RutGon();
        
        // Cộng, trừ, nhân, chia, so sánh với phân số khác.
        
        void Cong(); 
        void Tru();
        void Nhan();
        void Chia();
            
};
int main() {
    PhanSo a,b;
    cin >> a >> b;
    cout << a << "\n";
    cout << a.getTu() << "\n" << a.getMau() << "\n";
    a.NghichDao(); 
    a.RutGon(); 
    a.Cong();
    
    return 0;
}

istream& operator >> (istream& is, PhanSo& ps) {
    is >> ps.tu >> ps.mau; 
    return is;
}
ostream& operator << (ostream& os, PhanSo ps) {
    os << ps.tu << "/" << ps.mau;
    return os;
}

void PhanSo::RutGon() {
    if(tu != 0) {
        int d = gcd(tu,mau);
        tu /= d;
        mau /= d;
    }
    cout << tu << "/" << mau << "\n";
}
void PhanSo::NghichDao() {
    cout << mau << "/" << tu << "\n";
}

void PhanSo::Cong() {
    int a,b;
    a = tu * tu + mau * mau;
    b = mau * tu;
    cout << a << "/" << b;
}
void PhanSo::Tru() {
    int a,b;
    a = tu * tu - mau * mau;
    b = mau * tu;
    cout << a << "/" << b;
}
void PhanSo::Nhan() {
    int a,b;
    a = tu * tu;
    b = mau * mau;
    cout << a << "/" << b;
}
void PhanSo::Chia() {
    int a,b;
    a = tu * mau;
    b = mau * tu;
    cout << a << "/" << b;
}
