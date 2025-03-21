#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu, mau;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    PhanSo() : tu(0), mau(1) {} // Khởi tạo mặc định

    friend istream& operator>>(istream& is, PhanSo& ps) {
        is >> ps.tu >> ps.mau;
        return is;
    }

    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        os << ps.tu << "/" << ps.mau;
        return os;
    }

    void rutgon() {
        int d = gcd(tu, mau);
        tu /= d;
        mau /= d;
    }

    PhanSo operator+(const PhanSo& other) {
        PhanSo kq;
        kq.tu = this->tu * other.mau + this->mau * other.tu;
        kq.mau = this->mau * other.mau;
        kq.rutgon();
        return kq;
    }

    void operator=(int other) {
        this->tu = other;
        this->mau = 1;
    }
};

template <typename T>
class Mang {
private:
    int size;
    T values[100];

public:
    Mang() : size(0) {} // Khởi tạo mặc định

    T& operator[](int index) {
        return values[index];
    }

    void operator=(const Mang<T>& arr) {
        size = arr.size;
        for (int i = 0; i < size; i++) {
            values[i] = arr.values[i];
        }
    }

    friend istream& operator>>(istream& is, Mang<T>& arr) {
        T x;
        while (is >> x) {
            arr.values[arr.size++] = x;
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, Mang<T> arr) {
        os << arr.Sum();
        return os;
    }

    T Sum() {
        T sum;
        sum = 0;
        for (int i = 0; i < size; i++) {
            sum = sum + values[i];
        }
        return sum;
    }
};

int main() {
    Mang<int> a;
    Mang<PhanSo> b;

    char type;
    cin >> type;
    switch (type) {
        case 'a':
            cin >> a;
            cout << a;
            break;
        case 'b':
            cin >> b;
            cout << b;
            break;
    }
    return 0;
}
