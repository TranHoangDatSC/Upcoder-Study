#include <iostream>
using namespace std;

class PhanSo {
    private:
        int tu, mau;
        
    public:
        PhanSo() {                  // Khởi tạo mặc định phân số = 0.
            tu = 0; 
            mau = 1;
        }
        
        PhanSo(int _tu, int _mau) { // Khởi tạo với tử và mẫu cho trước.
            tu = _tu;
            mau = _mau;
        }
        
        PhanSo(int n) {             // Khởi tạo từ giá trị nguyên cho trước.
            tu = n; 
            mau = 1;
        }
        
        PhanSo(const PhanSo &ps) {  // Khởi tạo từ một phân số khác. (copy)
            tu = ps.tu;
            mau = ps.mau;
        }
        
        ~PhanSo() {}                // Phương thức hủy phân số.
        
        void setTu(int k) { tu = k; }
        void setMau(int k) { mau = k; }
        int getTu() { return this->tu; }
        int getMau() { return this->mau; }
        
        friend istream& operator >> (istream& is, PhanSo &ps) {
            is >> ps.tu >> ps.mau;
            return is;
        }
        
        friend ostream& operator << (ostream& os, PhanSo ps) {
            os << ps.tu << "/" << ps.mau;
            return os;
        }
        
        int gcd(int a, int b) {
            if(b == 0) return a;
            return gcd(b,a%b);
        }
        
        PhanSo rutgon() {
            int result = gcd(this->tu,this->mau);
            this->tu /= result;
            this->mau /= result;
            return result;
        }
        
        PhanSo nghichdao() {
            if(this->tu == 0) return PhanSo(0,1);
            return PhanSo(this->mau,this->tu);
        }
        
        PhanSo operator + (PhanSo ps) {
            PhanSo kq;
            kq.tu = this->tu * ps.mau + this->mau * ps.tu;
            kq.mau = this->mau * ps.mau;
            return kq;
        }
        
        PhanSo operator - (PhanSo ps) {
            PhanSo kq;
            kq.tu = this->tu * ps.mau - this->mau * ps.tu;
            kq.mau = this->mau * ps.mau;
            return kq;
        }
        
        PhanSo operator * (PhanSo ps) {
            PhanSo kq;
            kq.tu = this->tu * ps.tu;
            kq.mau = this->mau * ps.mau;
            return kq;
        }
        
        PhanSo operator / (PhanSo ps) {
            PhanSo kq;
            kq.tu = this->tu * ps.mau;
            kq.mau = this->mau * ps.tu;
            return kq;
        }
};

int main() {
    
    PhanSo a,b;
    cin >> a >> b;
    
    cout << a << "\n";
    
    cout << a.getTu() << "\n" << a.getMau() << "\n";
    cout << a.nghichdao() << "\n";
    a.rutgon();
    cout << a << "\n";
    cout << a + a.nghichdao();
    
    return 0;
}
