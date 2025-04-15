#include <iostream>
using namespace std;

int giaiThua(int n)
{
    if(n == 1) return 1;
    else return n * giaiThua(n - 1);
}

void hoanVi(int n, int arr[], bool used[], int pos)
{
    if(pos == n)
    {
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(!used[i])
            {
                arr[pos] = i;
                used[i] = true;
                hoanVi(n, arr, used, pos + 1);
                used[i] = false; // backtrack
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    cout << giaiThua(n) << "\n";

    int arr[100];     // giả sử n <= 10
    bool used[100] = {false}; // đánh dấu số đã dùng (1..n)

    hoanVi(n, arr, used, 0);

    return 0;
}


// #include <iostream>
// #include <string>
// using namespace std;

// int giaiThua(int n)
// {
//     if(n == 1)
//         return 1;
//     else return n * giaiThua(n - 1);
// }
// void hoanVi(int n, string str)
// {
//     if(str.size() == n)
//         cout << str << "\n";
//     else 
//     {
//         for(int i = 1; i <= n; i++)
//         {
//             string number = to_string(i);
//             auto check = str.find(number);
//             if(check != string::npos)
//                 continue;
//             else 
//                 hoanVi(n,str + number);
//         }
//     }
// }
// int main()
// {
//     int n;
//     string str;
//     cin >> n;
//     cout << giaiThua(n) << "\n";
//     hoanVi(n,str);
//     return 0;
// }
