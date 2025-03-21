#include <iostream>
using namespace std;

class Hinh {
public: 
    virtual istream& nhap(istream& in) = 0;
    virtual double dienTich() = 0;
};

class HinhVuong : public Hinh {
private:
    double canh;
public:
    virtual istream& nhap(istream& in) {
        in >> canh;
        return in;
    }

    virtual double dienTich() {
        return canh * 4;
    }
};

class HinhChuNhat : public Hinh {
private:
    double dai, rong;
public: 
    virtual istream& nhap(istream& in) {
        in >> dai >> rong;
        return in;
    }

    virtual double dienTich() {
        return (dai + rong) * 2;
    }
};

int main() {
    Hinh* a[100];
    int i = 0; 
    char c;

    while (cin >> c) {
        if (c == 'a') a[i] = new HinhVuong();
        if (c == 'b') a[i] = new HinhChuNhat();
        a[i]->nhap(cin);
        cout << a[i]->dienTich() << '\n';
    }

    return 0;
}


/*
#include <iostream>
using namespace std;

class HinhHoc
{
    public:
        virtual int getCV() = 0; // Phương thức thuần ảo
};

class HCN : public HinhHoc
{
    private:
        int dai,rong;
    public:
        HCN(int _dai = 2, int _rong = 1) 
        {
            dai = _dai;
            rong = _rong;
        }
        HCN(const HCN& h) 
        {
            dai = h.dai;
            rong = h.rong;
        }
        
        friend istream& operator >> (istream& is, HCN& h)
        {
            is >> h.dai >> h.rong;
            return is;
        }
        int getCV()
        {
            return ((this->dai + this->rong) * 2);
        }
};

class HV : public HCN
{
    private:
        int canh;
    public:
        HV(int _canh = 1) : HCN(_canh,_canh) 
        {
            canh = _canh;
        }
        HV(const HV& h) : HCN(h)
        {
            canh = h.canh;
        }
        friend istream& operator >> (istream& is, HV& h)
        {
            int c;
            cin >> c;
            h = HV(c);
            return is;
        }
};

int main()
{
    char type;
    int cnt = 0;
    HinhHoc *p[10];
    int a,b; 
    
    while(cin >> type)
    {
        if(type == 'a')
        {
            cin >> a;
            p[cnt] = new HV(a);
            cnt++;
        }
        else 
        {
            cin >> a >> b; 
            p[cnt] = new HCN(a,b);
            cnt++;
        }
    }
    
    for(int i=0;i<cnt;i++)
    {
        cout << p[i]->getCV() << "\n";
    }
    
    return 0;
}
*/
