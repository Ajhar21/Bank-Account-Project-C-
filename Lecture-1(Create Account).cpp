#include <bits/stdc++.h>
using namespace std;
class BankAccount
{
public:
    string account_name;
    string address;
    int account_number;   ///bank will generate account number
    int age;
protected:
    int balance;
private:
    string password;
public:
    BankAccount(string account_name, string address, int age, string password )
    {
        this->account_name=account_name;
        this->address=address;
        this->age=age;
        this->password=password;
        this->account_number=rand()%1000000000;
        cout<<"Your Account No is "<<this->account_number<<endl;
    }
};
int main()
{

    return 0;
}
