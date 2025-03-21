#include <iostream>
using namespace std;

struct SinhVien
{
    string HoTen;
    int NamSinh;
    double DTB;
    
    friend istream& operator >> (istream& is,SinhVien& sv)
    {
        is >> sv.HoTen >> sv.NamSinh >> sv.DTB;
        return is;
    }
};

void max_mark(SinhVien sv[], int n)
{
    SinhVien Max = sv[0];
    for(int i = 1; i < n; i++)
    {
        if(sv[i].DTB > Max.DTB)
            Max = sv[i];
    }
    
    cout << "Diem cao nhat lop:\n";
    int cnt = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(sv[i].DTB == Max.DTB)
        {
            cout << "#" << ++cnt << "\n";
            cout << sv[i].HoTen << " " << sv[i].NamSinh << " " << sv[i].DTB << "\n";
        }
    }
    
}

void min_mark(SinhVien sv[], int n)
{
    SinhVien Min = sv[0];
    for(int i = 1; i < n; i++)
    {
        if(sv[i].DTB < Min.DTB)
            Min = sv[i];
    }
    
    cout << "Diem thap nhat lop:\n";
    int cnt = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(sv[i].DTB == Min.DTB)
        {
            cout << "#" << ++cnt << "\n";
            cout << sv[i].HoTen << " " << sv[i].NamSinh << " " << sv[i].DTB << "\n";
        }
    }
    
}


int main()
{
    SinhVien sv[100];
    int size = 0;
    
    while(cin >> sv[size])
        size++;
        
    max_mark(sv,size);
    min_mark(sv,size);
    
    return 0;
}
