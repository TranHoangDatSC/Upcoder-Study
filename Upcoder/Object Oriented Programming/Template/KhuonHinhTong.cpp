#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

class PhanSo
{
    private:
        int tu,mau;  
    public:
        PhanSo()
        {
            tu = 0;
            mau = 1;
        }
        PhanSo(const PhanSo& p)
        {
            tu = p.tu;
            mau = p.mau;
        }
        friend istream& operator >> (istream& is, PhanSo& p)
        {
            is >> p.tu >> p.mau;
            return is;
        }
        friend ostream& operator << (ostream& os, PhanSo p)
        {
            os << p.tu << "/" << p.mau;
            return os;
        }
        PhanSo operator + (PhanSo other)
        {
            PhanSo kq;
            kq.tu = this->tu * other.mau + other.tu * this->mau;
            kq.mau = this->mau * other.mau;
            int d = gcd(kq.tu,kq.mau);
            /* int d = __gcd(kq.tu, kq.mau); */
            kq.tu /= d;
            kq.mau /= d;
            return kq;
        }
};

template<class T>
class Mang
{
    private:
        int size;
        T values[100];
    public: 
        
        Mang(int _size = 0, T _values[] = new T {})
        {
            size = _size;
            for(int i=0;i<size;i++)
            {
                values[i] = _values[i];
            }
        }
        
        Mang(const Mang& p)
        {
            size = p.size;
            for(int i=0;i<size;i++)
            {
                values[i] = p.values[i];
            }
        }
        
        friend istream& operator >> (istream& is, Mang& p)
        {
            T x;
            p.size = 0;
            while(is >> x)
            {
                
                p.values[p.size++] = x;
            }
            return is;
        }
        friend ostream& operator << (ostream& os, Mang p)
        {
            for(int i=0;i<p.size;i++)
            {
                os << p.values[i] << " ";
            }
            return os;
        }

        T& operator [](int index)
        {
            return values[index];
        }
        
        void operator = (Mang p)
        {
            size = p.size;
            for(int i=0;i<p.size;i++)
            {
                values[i] = p.values[i];
            }
        }
        
        void setSize(int k)
        {
            size = k;
        }
        int getSize()
        {
            return size;
        }

};
int main()
{
    Mang<int> a;
    Mang<PhanSo> b;
    char type;
    
    while(cin>>type)
    {
        switch(type)
        {
            case 'a':
            {
                cin >> a[a.getSize()];
                a.setSize(a.getSize() + 1);
                break;
            }
            case 'b': 
            {
                cin >> b[b.getSize()];
                b.setSize(b.getSize() + 1);
                break;
            }
        }
    }
    
    if(a.getSize() == 0)
    {
        cout << "khong co" << "\n";
    }
    else 
    {
        int sum = 0;
        for(int i=0;i<a.getSize();i++)
        {
            sum = sum + a[i];
        }
        cout << sum << "\n";
    }
    if(b.getSize() == 0)
    {
        cout << "khong co" << "\n";
    }
    else 
    {
        PhanSo sum;
        for(int i=0;i<b.getSize();i++)
        {
            sum = b[i] + sum;
        }
        cout << sum;
    }
    return 0;
}
