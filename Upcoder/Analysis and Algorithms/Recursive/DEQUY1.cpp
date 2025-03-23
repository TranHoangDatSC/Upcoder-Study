#include <iostream>
#include <algorithm>
using namespace std;

void ChuoiHoanVi(int n, int k, string str);

int main() {
    int n,k;
    cin >> n >> k;
    cout << pow(n,k) << endl;
    
    string str = "";
    ChuoiHoanVi(n,k,str);
    return 0;   
}

void ChuoiHoanVi(int n, int k, string str) {
    if(str.size() == n) 
        cout << str << "\n";
    else {
        for(int i = 1; i <= n; i++) {
            string number = to_string(i);
            ChuoiHoanVi(n, k, str + number);
        }
    }
}
