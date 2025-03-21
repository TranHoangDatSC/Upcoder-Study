#include <iostream>
#include <string>
using namespace std;

class KhachHang
{
    private:
        string name;
        int timeUse;
        int numCpt;
        int price;
    public:
    
        string getName() {return name;}
        int getTimeUse() {return timeUse;}
        int getNumCpt() {return numCpt;}
        int getPrice() {return price;}
    
        KhachHang(string _name = "name", int _timeUse = 0,int _numCpt = 0, int _price = 0)
        {
            name = _name;
            timeUse = _timeUse;
            numCpt = _numCpt;
            price = _price;
        }
        KhachHang(const KhachHang& kh)
        {
            name = kh.name;
            timeUse = kh.timeUse;
            numCpt = kh.numCpt;
            price = kh.price;
        }
        ~KhachHang() {}
        
        virtual string getType() = 0;
        virtual int getCount() = 0;
        
        void Output()
        {
            cout << "Loai khach: " << getType() << "\n";
            cout << "Ho Ten: " << name << "\n";
            cout << "Thoi gian su dung: " << timeUse << "\n";
            cout << "So may: " << numCpt << "\n";
            cout << "So tien phai tra: " << getCount() << "\n";
        }
};

class KHVip : public KhachHang
{
    private:
        int priceVip;
    public:
        KHVip(string _name = "name", int _timeUse = 0,int _numCpt = 0, int _price = 0, int _priceVip = 0)
        : KhachHang(_name,_timeUse,_numCpt,_price)
        {
            priceVip = _priceVip;
        }
        KHVip(const KHVip& kh) : KhachHang(kh)
        {
            priceVip = kh.priceVip;
        }
        ~KHVip() {} 
        
        string getType() { return "VIP";}
        
        int getCount()
        {
            if(getTimeUse() >= 4) return priceVip * 4;
            return getTimeUse() * getPrice();
        }
};

class KHTX : public KhachHang
{
    private:
        int promo;
    public:
        KHTX(string _name = "name", int _timeUse = 0,int _numCpt = 0, int _price = 0, int _promo = 0)
        : KhachHang(_name,_timeUse,_numCpt,_price)
        {
            promo = _promo;
        }
        KHTX(const KHTX& kh) : KhachHang(kh)
        {
            promo = kh.promo;
        }
        ~KHTX() {} 
        
        string getType() {return "TX";}
        int getCount() 
        {
            return getTimeUse() * (getPrice() - promo);
        }
};

class KHKTX : public KhachHang
{
    private:
        int priceCapacity;
        int capacityDownload;
    public:
        KHKTX(string _name = "name", int _timeUse = 0,int _numCpt = 0, int _price = 0, int _priceCapacity = 0, int _capacityDownload = 0)
        : KhachHang(_name,_timeUse,_numCpt,_price)
        {
            priceCapacity = _priceCapacity;
            capacityDownload = _capacityDownload;
        }
        KHKTX(const KHKTX& kh) : KhachHang(kh)
        {
            priceCapacity = kh.priceCapacity;
            capacityDownload = kh.capacityDownload;
        }
        ~KHKTX() {}
        
        string getType() {return "KTX";}
        int getCount()
        {
            return getTimeUse() * getPrice() + priceCapacity * capacityDownload;
        }
};

int main()
{
    int num,price,priceVip,priceCapacity;
    cin >> num >> price >> priceVip >> priceCapacity;
    
    KhachHang *p;
    
    for(int i=0;i<num;i++)
    {
        cout << (i+1) << ". ";
        string type, name;
        int numCpt, timeUse;
        
        cin >> type;
        cin.ignore();
        
        getline(cin,name);
        cin >> timeUse >> numCpt;
        
        if(type == "VIP")
        {
            KHVip kh = KHVip(name,timeUse,numCpt,price,priceVip);
            p = &kh;
            p->Output();
        }
        else if(type == "TX")
        {
            int promo;
            cin >> promo;
            KHTX kh = KHTX(name,timeUse,numCpt,price,promo);
            p = &kh;
            p->Output();
        }
        else if(type == "KTX")
        {
            int capDow;
            cin >> capDow;  
            KHKTX kh = KHKTX(name,timeUse,numCpt,price,capDow,priceCapacity);
            p = &kh;
            p->Output();
        }
    }
    return 0;
}
