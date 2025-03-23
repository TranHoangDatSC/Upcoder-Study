// Đổi một số từ hệ 10 sang 2/8/16

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void ConvertBase(long number, int baseType) {
    string HEX_DIGITS = "0123456789ABCDEF";
    stack<string> st;
    
    if (number == 0) {
        cout << "0" << endl;
        return;
    }

    switch(baseType) {
        case 0: // Convert to binary
            while (number > 0) {
                st.push(to_string(number % 2));
                number /= 2;
            }
            cout << "Binary: ";
            break;

        case 1: // Convert to octal
            while (number > 0) {
                st.push(to_string(number % 8));
                number /= 8;
            }
            cout << "Octal: ";
            break;

        case 2: // Convert to hexadecimal
            while (number > 0) {
                st.push(string(1, HEX_DIGITS[number % 16]));
                number /= 16;
            }
            cout << "Hexadecimal: ";
            break;

        default:
            cout << "Invalid input!" << endl;
            return;
    }

    // Print the result
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main() {
    long number;
    int baseType;

    cin >> number;
    cin >> baseType;

    ConvertBase(number, baseType);

    return 0;
}
