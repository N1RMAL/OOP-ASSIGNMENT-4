#include <iostream>
#include <string.h>
using namespace std;

char name[100], type[100], month[100];
long int number, cread, lread; 
double amount;

int printBill()
{
    cout << "Your bill has been processed:\n";
    cout << "\nCustomer name: " << name << "\n";
    cout << "\nCustomer number: " << number << "\n";
    cout << "\nCustomer type: " << type << "\n";
    cout << "\nCurrent meter reading: " << cread << "\n";
    cout << "\nLast meter reading: " << lread << "\n";
    cout << "\nBill month: " << month << "\n\n";
    cout << "\nAmount to be payed: " << amount;
}

int calculateBill()
{
    if(strcmp(type,"Commercial")||strcmp(type,"commercial")==0)
    {
        if(cread<=200)
        {
            amount=(5*cread);
        }
        else
        {
            amount=1000+((cread-200)*10);
        }
    }
    else if(strcmp(type,"Non-Commercial")||strcmp(type,"non-commercial")==0)
    {
        if(cread<=100)
        {
            amount=(3*cread);
        }
        else
        {
            amount=300+((cread-100)*5);
        }
    }
    else
    {
        cout << "Invalid customer type, please enter again!";
        calculateBill();
    }
}

int readData()
{
    cout << "Enter your name:\n";
    cin.getline(name,100);
    cout << "\nEnter your consumer number:\n";
    cin >> number;
    cout << "\nEnter the consumer type:\n";
    cin.ignore();
    cin.getline(type,100);
    cout << "\nEnter your current meter reading:\n";
    cin >> cread;
    cout << "\nEnter the last meter reading:\n";
    cin >> lread;
    cout << "\nEnter the month:\n";
    cin.ignore();
    cin.getline(month,100);
    cout << "\n\n";
}

int main()
{
    readData();
    calculateBill();
    printBill();
}

