#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Nguoi
{
    private:
        string hoten;
        int namsinh;
        string quequan;
    
    public:
        
        // Khởi tạo
        Nguoi(string _hoten = "",int _namsinh = 2000,string _quequan = "")
        {
            hoten = _hoten;
            namsinh = _namsinh;
            quequan = _quequan;
        }
        
        Nguoi(const Nguoi& h)
        {
            hoten = h.hoten;
            namsinh = h.namsinh;
            quequan = h.quequan;
        }
        
        // Nhập, xuất
        friend istream& operator >> (istream& is, Nguoi& ng)
        {
            getline(is, ng.hoten);
            is >> ng.namsinh;
            is.ignore();
            getline(is, ng.quequan);
            
            return is;
        }
        
        friend ostream& operator << (ostream& os, Nguoi ng)
        {
            os << "Ho Ten: " << ng.hoten << "\n";
            os << "Nam Sinh: " << ng.namsinh << "\n";
            os << "Que quan: " << ng.quequan << "\n";
            return os;
        }
        
        // Get, set
        void setHT(string _ht) { hoten=_ht; }
        void setNS(int _ns) { namsinh=_ns; }
        void setQQ(string _qq) { quequan=_qq; }
        
        string getHT() { return hoten; }
        int getNS() { return namsinh; } 
        string getQQ() { return quequan; }
        
        void Set(string _hoten = "",int _namsinh = 2000,string _quequan = "")
        {
            hoten = _hoten;
            namsinh = _namsinh;
            quequan = _quequan;
        }
        
        // Hủy
        ~Nguoi() {}
};

class SinhVien : public Nguoi
{
    private:
        string khoa;
        int size;
        int diem[100];
    public:
    
        // Toán tử [], =
        int& operator [](int index)
        {
            return diem[index];   
        }
        void operator = (SinhVien sv)
        {
            khoa = sv.khoa;
            size = sv.size;
            for(int i = 0; i < size; i++)
            {
                diem[i] = sv.diem[i];
            }
        }

        // Khởi tạo
        SinhVien(string _hoten = "", int _namsinh = 2000, string _quequan = "", string _khoa = "", int _size = 0, int _diem[] = new int {1}) 
        : Nguoi(_hoten,_namsinh,_quequan)
        {
            khoa = _khoa;
            size = _size;
            
            for(int i=0;i<size;i++)
            {
                diem[i] = _diem[i];
            }
        }
        
        SinhVien(const SinhVien& sv) : Nguoi(sv)
        {
            khoa = sv.khoa;
            size = sv.size;
            for(int i=0;i<size;i++)
            {
                diem[i] = sv.diem[i];
            }
        }
        
        // Nhập, xuất
        friend istream& operator >> (istream& is, SinhVien& sv)
        {
            string hoten, quequan, khoa;
            int namsinh, size;
            int diem[100];
            
            getline(is, hoten);
            is >> namsinh;
            is.ignore();
            getline(is, quequan);
            getline(is, sv.khoa);
            
            sv.size = 0;
            while(is >> sv.diem[sv.size])
            {
                sv.size++;
            }
            
            sv.setHT(hoten);
            sv.setNS(namsinh);
            sv.setQQ(quequan);
            return is;
        }
        
        friend ostream& operator << (ostream& os, SinhVien sv)
        {
            os << "Ho Ten: " << sv.getHT() << "\n";
            os << "Nam Sinh: " << sv.getNS() << "\n";
            os << "Que quan: " << sv.getQQ() << "\n";
            
            os << "Khoa: " << sv.khoa << "\n";
            os << "Diem cac mon: ";
            
            for(int i=0;i<sv.size;i++)
            {
                os << sv.diem[i] << " ";
            }
            os << "\n" << "Diem trung binh: " << fixed << setprecision(2) << sv.getDTB();
            return os;
        }
        
        // Tính điểm trung bình (lấy 2  chữ số thập phân)
        double getDTB()
        {
            double sum = 0;
            for(int i=0;i<this->size;i++)
            {
                sum = sum + this->diem[i];
            }
            return sum/ this->size;
        }
        
        // Get, set
        void setK(string k) {khoa = k;}
        string getK() {return khoa;}
        
        // Hủy
        ~SinhVien() {}
};

int main()
{
    SinhVien sv;
    cin >> sv;
    cout << sv;
    return 0;
}
