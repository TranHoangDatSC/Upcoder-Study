#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    protected:
        string ID;
        string CustomerName;
        string IDCardNumber;
        double Balance; // Trả về số dư tài khoản

    public:
        BankAccount() 
        {
            ID = "000000";
            CustomerName = "No name";
            IDCardNumber = "xxx";
            Balance = 0;
        }

        BankAccount(string id, string customerName, string idCardNumber, double money)
        {
            this->ID = id;
            this->CustomerName = customerName ;
            this->IDCardNumber = idCardNumber;
            this->Balance = money;
        } 

        void setBalance(double money)
        {
            this->Balance = money;
        }
        double getBalance()
        {
            return this->Balance;
        }


        string toString()
        {
            return "{" + this->ID + "}:{" + this->CustomerName + "}:{" + to_string((int) this->Balance) + "}"; 
        }

        virtual double WithdrawLimit()
        {
            return this->Balance;
        }
        virtual bool Withdraw(double withdrawmoney)
        {
            return withdrawmoney <= this->WithdrawLimit();
        }
        virtual double Deposit(double depositmoney)  // Tiền gửi
        {
            Balance += depositmoney;
            return this->Balance;
        }
};

class CheckingAccount : public BankAccount
{
    private:
        double OverDraftLimit;
    public:
        CheckingAccount() : BankAccount()
        {
            this->OverDraftLimit = 50000;
        }

        CheckingAccount(string id,string customerName, string idCardNumber, double money,double overDL) : BankAccount(id, customerName,idCardNumber,money)
        {
            this->OverDraftLimit = overDL;
        }

        double WithdrawLimit() override
        {
            return this->Balance + this->OverDraftLimit;
        }
        bool Withdraw(double depositmoney) override
        {
            return depositmoney <= this->WithdrawLimit();
        }
};

class SavingAccount : public BankAccount
{
    private:
        double InterestRate;
        double InterMoney;

    public:
        SavingAccount() : BankAccount() {}

        SavingAccount(string id,string customerName, string idCardNumber, double money) : BankAccount(id,customerName,idCardNumber,money) {}

        double getIntermoney()
        {
            return this->InterMoney;
        }
        double WithdrawLimit() override
        {
            return this->Balance;
        }
        double Deposit(double depositmoney) override
        {
            if(this->Balance < 1000000) this->InterestRate = 0.1;
            else if(this->Balance < 50000000) this->InterestRate = 0.3;
            else if(this->Balance < 200000000) this->InterestRate = 0.5;
            else if(this->Balance < 1000000000) this->InterestRate = 1;

            else this->InterestRate = 1.94;
            this->InterMoney = this->Balance * this->InterestRate;

            return this->Balance;
        }

};

int main()
{
    char type;
    string infomation;
    double TienRut;
    CheckingAccount a;
    SavingAccount b;

    cin >> type >> infomation >> TienRut;

    string id,customerName,idCardNumber;
    double money, overDraftLimit;
    int start = 0, end;

    infomation += '/';
    end = infomation.find('/',start);
    id = infomation.substr(start, end-start); start = end + 1;

    end = infomation.find('/',start);
    customerName = infomation.substr(start,end-start); start = end + 1;

    end = infomation.find('/',start);
    idCardNumber = infomation.substr(start,end-start); start = end + 1;

    end = infomation.find('/',start);
    money = stod(infomation.substr(start,end - start)); start = end + 1;

    if(type == 'C')
    {
        end = infomation.find('/',start);
        overDraftLimit = stod(infomation.substr(start,end-start));
        a = CheckingAccount(id,customerName,idCardNumber,money,overDraftLimit);

        cout << a.toString() << "\n";
        if(a.Withdraw((TienRut)))
        {
            a.setBalance(a.getBalance() - TienRut);
            cout << "Yes" << a.toString() << "\n"; 
        } else cout << "No \n";
        cout << "Checking Account";
    }
    else if(type == 'S')
    {
        b = SavingAccount(id, customerName,idCardNumber,money);

        cout << b.toString() << "\n";
        if(b.Withdraw(TienRut))
        {
            b.setBalance(b.getBalance() - TienRut);
            cout << "Yes" << b.toString() << '\n';
        }
        else cout << "No \n";

        b.Deposit(b.getBalance());
        b.setBalance(b.getBalance() + b.getIntermoney());
        cout << b.toString();
    }
    return 0;
}
