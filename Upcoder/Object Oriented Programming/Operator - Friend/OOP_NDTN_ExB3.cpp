#include<iostream>
#include<cmath>
using namespace std;

class ARRINT2
{
    private:
        int size;
        int *values;
    public:
        ARRINT2(int n)
        {
            this->size = n;
            this->values = new int[n];
        }
        
        friend istream& operator >> (istream& is, ARRINT2& p)
        {
            for(int i = p.size - 1; i >= 0; i--)
            {
                is >> p.values[i];
            }
            return is;
        }
        friend ostream& operator << (ostream& os, ARRINT2 p)
        {
            os << p.size << ": ";
            for(int i = 0; i < p.size; i++)
            {
                os << p.values[i];
            }
            return os;
        }
        ARRINT2 operator - (ARRINT2 other)
        {
            ARRINT2 result(max(this->size,other.size));
            
            for(int i = 0; i < result.size; i++)
            {
                result.values[i] = (this->values[i] - other.values[i]);
                if(result.values[i] < 0)
                {
                    result.values[i] = abs(result.values[i]);
                }
            }
            return result;
        }
};

int main()
{
    int a,b;
    cin >> a >> b;
    
    ARRINT2 arr1(a), arr2(b);
    
    cin >> arr1 >> arr2;
    
    cout << arr1 - arr2;
    return 0;
}
