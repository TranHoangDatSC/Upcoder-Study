#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
using namespace std;

#define FOR(i,a,b) for(int i = a;i < b;i++)
struct DonThuc
{
    int n;
    double a;
};
void nhapDaThuc(DonThuc* DSDT, int k)
{
    FOR(i,0,k)
    {
        cin >> DSDT[i].a;
    }
    FOR(i,0,k)
    {
        cin >> DSDT[i].n;
    }
}
void xuatDonThuc(double a, int n) 
{
    if (a==1) 
    {
        if (n==0) { cout << a; }
        else if (n == 1) { cout << "x"; }
        else { cout << "x^" << n; }
    }
    else if (a > 1)
    {
        if (n==1) { cout << a << "x"; }
        else if (n==0) { cout << a; }
        else { cout << a << "x^" << n; }
    }
}
void xuatDaThuc(DonThuc* DSDT, int k) 
{
    FOR(i,0,k) 
    {
        if(i && DSDT[i-1].a != 0) 
            cout << " + ";
            xuatDonThuc(DSDT[i].a, DSDT[i].n);
    }
}
void tinhDaThuc(DonThuc* DSDT, int k, double x) 
{
    double result = 0;
    FOR(i,0,k) 
        result += DSDT[i].a * pow(x, DSDT[i].n);
    cout << result;
}
void xuatDaoHam(DonThuc* DSDT, int k) 
{
    FOR(i,0,k) 
    {
        if(i && DSDT[i-1].n > 0 && DSDT[i-1].a !=0) 
            cout << " + ";
            xuatDonThuc(DSDT[i].a * DSDT[i].n,DSDT[i].n - 1);
    }
}
int main() 
{
    int k; 
    cin >> k;
    DonThuc DSDT[1000];
    nhapDaThuc(DSDT,k);
    double x;
    cin >> x;
    xuatDaThuc(DSDT,k); cout << "\n";
    tinhDaThuc(DSDT,k,x); cout << "\n";
    xuatDaoHam(DSDT,k);  cout << "\n";
    return 0;
}
