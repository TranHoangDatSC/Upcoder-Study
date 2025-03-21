#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
    
    friend istream& operator >> (istream& is, PhanSo& ps)
    {
        is >> ps.tu >> ps.mau;
        return is;
    }
    friend ostream& operator << (ostream& os, PhanSo ps)
    {
        os << ps.tu << "/" << ps.mau << "\n";
        return os;
    }
    
    bool operator < (PhanSo other)
    {
        return this->tu * other.mau < this->mau * other.tu;
    }
};

template<typename T>
T maxThree(T a, T b, T c)
{
    T max = a;
    if(max < b) max = b;
    if(max < c) max = c;
    return max;
}

template<typename T>
void solve()
{
    T a,b,c; 
    cin >> a >> b >> c;
    cout << maxThree(a,b,c);
}

int main()
{
    char type;
    cin >> type;
    
    switch(type)
    {
        case 'a':
            solve<int>();
            break;
        case 'b':
            solve<float>();
            break;
        case 'c':
            solve<PhanSo>();
            break;
    }
    return 0;
}
