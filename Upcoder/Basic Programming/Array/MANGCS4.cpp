#include <iostream>
using namespace std;

const int MAX = 100;

void nhapMang(int a[MAX][MAX], int dong, int cot) {
    bool zigzag = true;  // Điều khiển hướng nhập
    for (int i = 0; i < dong; i++) {
        if (zigzag) {
            for (int j = 0; j < cot; j++) cin >> a[i][j];
        } else {
            for (int j = cot - 1; j >= 0; j--) cin >> a[i][j];
        }
        zigzag = !zigzag;  // Đổi hướng
    }
}

void sapXepMang(int a[MAX][MAX], int dong, int cot) {
    for (int i = 0; i < dong * cot - 1; i++) {
        for (int j = i + 1; j < dong * cot; j++) {
            int x1 = i / cot, y1 = i % cot;
            int x2 = j / cot, y2 = j % cot;
            if (a[x1][y1] > a[x2][y2]) {
                swap(a[x1][y1], a[x2][y2]);
            }
        }
    }
}

void xuatMang(int a[MAX][MAX], int dong, int cot) {
    bool zigzag = true;
    for (int i = 0; i < dong; i++) {
        if (zigzag) {
            for (int j = 0; j < cot; j++) cout << a[i][j] << " ";
        } else {
            for (int j = cot - 1; j >= 0; j--) cout << a[i][j] << " ";
        }
        cout << endl;
        zigzag = !zigzag;
    }
}

int main() {
    int a[MAX][MAX];
    int dong, cot;
    cin >> dong >> cot;

    nhapMang(a, dong, cot);
    sapXepMang(a, dong, cot);
    xuatMang(a, dong, cot);

    return 0;
}
