#include <iostream>
using namespace std;

class ARRINT1
{
    private:
        int len;
        int *values;
    public:
        ARRINT1(int n)
        {
            this->len = n;
            this->values = new int[n];
        }
        
        friend istream& operator >> (istream& is, ARRINT1 &arr)
        {
            for(int i = arr.len - 1; i >= 0; i--)
            {
                is >> arr.values[i];
            }
            return is;
        }
        friend ostream& operator << (ostream& os, ARRINT1 arr)
        {
            os << arr.len << ": ";
            for (int i = 0; i < arr.len; i++)
            {
                os << arr.values[i];
            }
            return os;
        }
        
        ARRINT1 operator + (ARRINT1 other)
        {
            ARRINT1 result(max(this->len,other.len));
            
            for(int i = 0;i < result.len; i++)
            {
                result.values[i] = this->values[i] + other.values[i];
                if(result.values[i] >= 10)
                {
                    result.values[i] -= 10;
                }
            }
            return result;
        }
};

int main()
{
    int a,b;
    cin >> a >> b;
    
    ARRINT1 array1(a), array2(b);
    
    cin >> array1 >> array2;
    cout << array1 + array2;
    
    return 0;
}
