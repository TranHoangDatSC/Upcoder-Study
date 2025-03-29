#include <iostream>
#include <iomanip>
using namespace std;

void GiaiPTBac1(double a, double b);

int main() {
    double a, b;
    cin >> a >> b;
    GiaiPTBac1(a,b);
    return 0;
}

void GiaiPTBac1(double a, double b) {
    double x = -b/a;
    if(a != 0)
        cout << setprecision(2) << fixed << x;
    else if(a == 0 && b != 0)
        cout << "VN";
    else if(a == 0 && b == 0)
        cout << "VSN";
}
