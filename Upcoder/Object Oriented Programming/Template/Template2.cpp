#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}

struct PhanSo
{
    int tu,mau;
    
    friend istream& operator >> (istream& is, PhanSo& ps)
    {
        is >> ps.tu >> ps.mau;
        return is;
    }
    friend ostream& operator << (ostream& os, PhanSo ps)
    {
        os << ps.tu << "/" << ps.mau;
        return os;
    }
    
    void rutgon()
    {
        int d = gcd(this->tu, this->mau);
        this->tu /= d;
        this->mau /= d;
    }
    
    PhanSo operator + (PhanSo other)
    {
        PhanSo kq;
        kq.tu = this->tu * other.mau + this->mau * other.tu;
        kq.mau = this->mau * other.mau;
        kq.rutgon();
        return kq;
    }
    void operator = (int other)
    {
        this->tu = other;
        this->mau = 1;
    }
};

template<typename T>
struct Mang
{
    int size = 0;
    T values[100];
    
    T& operator [](int index)
    {
        return values[index];
    }
    void operator = (Mang arr)
    {
        size = arr.size;
        for(int i = 0; i < size; i++)
        {
            values[i] = arr.values[i];
        }
    }
    
    friend istream& operator >> (istream& is, Mang& arr)
    {
        T x;
        
        while(is >> x)
        {
            arr.values[arr.size++] = x;
        }
        return is;
    }
    friend ostream& operator << (ostream& os, Mang arr)
    {
        cout << arr.Sum();
        return os;
    }
    T Sum()
    {
        T sum;
        sum = 0;
        for(int i = 0; i < this->size; i++)
        {
            sum = sum + this->values[i];
        }
        return sum;
    }
};

int main()
{
    Mang<int> a;
    Mang<PhanSo> b;
    
    char type;
    cin >> type;
    switch(type)
    {
        case 'a':
        {
            cin >> a;
            cout << a;
            break;
        }
        case 'b':
        {
            cin >> b;
            cout << b;
            break;
        }
    }
    return 0;
}
