#include <iostream>
#include <math.h>
using namespace std;

bool KtraSCP(int a);
bool KtraSCP(int a) {
    int b = sqrt(a);
    if (b*b == a )
        return true;
    return false;
}

int main () {
    int n;
     cin >> n;
     if (KtraSCP(n))
        cout << "yes";
    else 
        cout << "no";
    return 0;
}
