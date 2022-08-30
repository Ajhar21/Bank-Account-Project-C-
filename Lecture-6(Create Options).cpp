#include <bits/stdc++.h>
using namespace std;
class BankAccount
{
public:
    string account_holder;
    string address;
    int account_number;   ///bank will generate account number
    int age;
protected:
    int balance;
private:
    string password;
public:
    BankAccount(string account_holder, string address, int age, string password )
    {
        this->account_holder=account_holder;
        this->address=address;
        this->age=age;
        this->password=password;
        this->balance=0;
        this->account_number=rand()%1000000000;
        cout<<"Your Account No is "<<this->account_number<<endl;
    }
    int show_balance(string password)
    {
        if(this->password==password)
        {
            return this->balance;
        }
        else
        {
            return -1;
        }
    }
    void add_money(string password, int amount)
    {
        if(amount<0)
        {
            cout<<"Amount is Invalid"<<endl;
            return;
        }
        if(this->password==password)
        {
            this->balance+=amount;
            cout<<"Add Money Successful"<<endl;
        }
        else
        {
            cout<<"Password didn't Match"<<endl;
        }
    }
    void deposit_money(string password, int amount)
    {
        if(amount<0)
        {
            cout<<"Amount is Invalid"<<endl;
            return;
        }
        if(this->balance < amount)
        {
            cout<<"Insufficient balance"<<endl;
            return;
        }
        if(this->password == password)
        {
            this->balance -= amount;
            cout<<"Deposit Money Successful"<<endl;
        }
        else
        {
            cout<<"Password didn't Match"<<endl;
        }
    }
    friend class MyCash;
};
class MyCash
{
protected:
    int balance;
public:
    MyCash()
    {
        this->balance=0;
    }
public:
    void add_money_from_bank(BankAccount *myAccount, string password, int amount)
    {
        if(amount<0)
        {
            cout<<"Amount is Invalid"<<endl;
            return;
        }
        if(myAccount->balance < amount)
        {
            cout<<"Insufficient balance"<<endl;
            return;
        }
        if(myAccount->password==password)
        {
            this->balance+=amount;
            myAccount->balance-=amount;
            cout<<"Add money from bank successful"<<endl;
        }
        else
        {
            cout<<"Password didn't match"<<endl;
        }
    }
    int show_balance()
    {
        return this->balance;
    }
};
BankAccount* create_account()
{
    string account_holder,address,password;
    int age;
    cout<<"CREATE ACCOUNT"<<endl;
    cin>>account_holder>>address>>age>>password;
    BankAccount *myAccount=new BankAccount(account_holder,address,age,password);
    return myAccount;

}
void add_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Add Money"<<endl;
    cin>>password>>amount;
    myAccount->add_money(password,amount);
    cout<<"Your Bank Balance is "<<myAccount->show_balance("abc")<<endl;
}
void deposit_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Deposit Money"<<endl;
    cin>>password>>amount;
    myAccount->deposit_money(password,amount);
    cout<<"Your Balance is "<<myAccount->show_balance("abc")<<endl;
}
void add_money_from_bank(MyCash *myCash, BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Add money From Bank"<<endl;
    cin>>password>>amount;
    myCash->add_money_from_bank(myAccount,password,amount);
    cout<<"Your Balance is "<<myAccount->show_balance("abc")<<endl;
    cout<<"Your MyCash Balance is "<<myCash->show_balance()<<endl;
}
int main()
{
    BankAccount *myAccount=create_account();
    MyCash *myCash=new MyCash();

    while(true)
    {
        cout<<"1.Add Money to Bank"<<endl;
        cout<<"2.Deposit Money From Bank"<<endl;
        cout<<"3.Add Money to MyCash From Bank"<<endl;
        int option;
        cin>>option;
        if(option==1)
        {
            add_money(myAccount);
        }
        else if(option==2)
        {
            deposit_money(myAccount);
        }
        else if(option==3)
        {
            add_money_from_bank(myCash,myAccount);
        }
        else
        {
            cout<<"Invalid Option"<<endl;
        }

    }

    return 0;
}




