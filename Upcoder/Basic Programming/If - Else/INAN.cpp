#include <iostream>
using namespace std;

long Solve(long T, long P, long C) {
    long res = 0;
    if(T == 1) {
        res = P * C;
    }
    else if(T == 2) {
        if(P % 2 == 0)
            res = (P / 2) * C;
        else 
            res = ((P + 1) / 2) * C;
    }
    return res;
}

int main() {
    long T, P, C;
    cin >> T >> P >> C;
    cout << Solve(T,P,C);
    return 0;
}
