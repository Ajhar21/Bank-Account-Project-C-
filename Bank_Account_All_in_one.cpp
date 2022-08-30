#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;
public:
    BankAccount(string account_holder, string address, int age, string password)
    {
        this->account_holder=account_holder;
        this->address=address;
        this->age=age;
        this->password=password;
        this->balance=0;
        cout<<"Your Balance is "<<this->balance<<endl;
        srand(time(0));
        this->account_number=rand()%1000000000;
        cout<<"Your Account Number is "<<this->account_number<<endl;
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
            cout<<"Invalid Amount"<<endl;
            return;
        }
        if(this->password==password)
        {
            this->balance+=amount;
            cout<<"Money Added Successfully"<<endl;

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
            cout<<"Invalid Amount"<<endl;
            return;
        }
        if(amount > this->balance)
        {
            cout<<"Insufficient Balance"<<endl;
            return;
        }
        if(this->password==password)
        {
            this->balance-=amount;
            cout<<"Deposit Sucessful"<<endl;

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
        balance=0;
        cout<<"Your MyCash Balance is "<<balance<<endl;
    }
    void add_money_to_MyCash_from_bank(BankAccount *myAccount, string password, int amount)
    {
        if(amount<0)
        {
            cout<<"Invalid Amount"<<endl;
            return;
        }
        if(amount > myAccount->balance)
        {
            cout<<"Insufficient Balance"<<endl;
            return;
        }
        if(myAccount->password==password)
        {
            this->balance+=amount;
            myAccount->balance -=amount;
            cout<<"Money Added to MyCash Successfully"<<endl;

        }
        else
        {
            cout<<"Password didn't Match"<<endl;
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
    cout<<"Your Balance is "<<myAccount->show_balance("abc")<<endl;
}
void deposit_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Deposit Money"<<endl;
    cin>>password>>amount;
    myAccount->deposit_money(password,amount);
    cout<<"Your New Balance is "<<myAccount->show_balance("abc")<<endl;
}
void add_money_to_MyCash_from_bank(MyCash *myCash, BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Add Money to MyCash"<<endl;
    cin>>password>>amount;
    myCash->add_money_to_MyCash_from_bank(myAccount,password,amount);
    cout<<"Your MyCash Balance is "<<myCash->show_balance()<<endl;;
    cout<<"Your New Bank Balance is "<<myAccount->show_balance("abc")<<endl;
}
int main()
{
    BankAccount *myAccount=create_account();
    MyCash *myCash=new MyCash();

    Flag:
        cout<<"1.Add Money to Bank"<<endl;
        cout<<"2.Deposit Money"<<endl;
        cout<<"3.Add Money to MyCash"<<endl;
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
            add_money_to_MyCash_from_bank(myCash,myAccount);
        }
        else{
            cout<<"Invalid Option"<<endl;
        }
        goto Flag;

    return 0;
}
