#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
    private:
        int id;
        string firstName;
        string lastName;
        double salary;
        
    public:
        Employee() {
            this->id = 0;
            this->firstName = "";
            this->lastName = "";
            this->salary = 0.0;
        }
        Employee (int _id, string fn, string ln, double _salary) {
            id = _id;
            firstName = fn;
            lastName = ln;
            salary = _salary;
        }
        
        friend istream& operator >> (istream& is, Employee& emp) {
            is >> emp.id >> emp.firstName >> emp.lastName >> emp.salary;
            return is;
        }
        friend ostream& operator << (ostream& os, Employee emp) {
            os << "Employee[id=" << emp.id;
            os << ",name=" << emp.getName();
            os << ",salary= $" << fixed << setprecision(2) << emp.salary << "]\n";
            return os;
        }
        
        void setId(int _id) { id = _id; }
        void setFirstName(string fn) { firstName = fn; }
        void setLastName(string ln) { lastName = ln; }
        void setSalary(double _salary) { salary = _salary; }
        
        int getId() { return id; }
        string getFirstName() { return firstName; }
        string getLastName() { return  lastName; }
        double getSalary() { return salary; }
        
        string getName() {
            return getFirstName() + " " + getLastName();
        }
        double getAnnualSalary() {
            return getSalary() * 12;
        }
        double raiseSalary(double percent) {
            salary = salary * (1 + percent);
            return salary;
        }
        string toString() {
            string s = "Employee[id= " + to_string(id) + ",name=" + getName()
            + ",salary= $" + to_string(salary) + "]\n";
            return s;
        }
        
        Employee operator ++ () {
            salary = salary * (1 + 0.1);
            return *this;
        }
        Employee operator ++ (int) {
            Employee result = *this;
            salary = salary * (1 + 0.1);
            return result;
        }
        Employee operator -- () {
            salary = salary * (1 - 0.1);
            return *this;
        }
        Employee operator -- (int) {
            Employee result;
            salary = salary * (1 - 0.1);
            return result;
        }
        
        Employee operator + (double k) {
            salary = salary + k;
            return *this;
        }
        Employee operator - (double k) {
            salary = salary - k;
            return *this;
        }
        
        bool operator > (Employee emp) {
            return this->getAnnualSalary() > emp.getAnnualSalary();
        }
        bool operator < (Employee emp) {
            return this->getAnnualSalary() < emp.getAnnualSalary();
        }
        bool operator == (Employee emp) {
            return this->getAnnualSalary() == emp.getAnnualSalary();
        }
        bool operator != (Employee emp) {
            return this->getAnnualSalary() != emp.getAnnualSalary();
        }
};

void nhap(Employee &Emp1, Employee &Emp2, double &plus1, double &plus2) {
    cin >> Emp1 >> Emp2;
    cin >> plus1 >> plus2;
}
void xuat(Employee Emp1, Employee Emp2,double plus1, double plus2) {
    cout << Emp1 << Emp2;
    
    if(Emp1 == Emp2) 
        cout << "BANG NHAU\n";
    else if(Emp1 < Emp2)
        cout << "NHO HON\n";
    else 
        cout << "LON HON\n";

        
    cout << "$ " << (Emp1++ - plus1).getSalary() << "\n";
    cout << "$ " << (--Emp2 + plus2).getSalary() << "\n";
}

int main() {
    Employee emp1,emp2;
    double plus1,plus2;
    nhap(emp1,emp2,plus1,plus2);
    xuat(emp1,emp2,plus1,plus2);
    
    return 0;
}
