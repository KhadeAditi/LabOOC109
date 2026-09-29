 
#include <iostream>
using namespace std;

class MobileRecharge
{
private:
    string mobileNumber;
    float balance;

public:
    // Constructor
    MobileRecharge(string number, float b)
    {
        mobileNumber = number;
        balance = b;
    }

    // Recharge account
    void recharge(float amount)
    {
        balance = balance + amount;
        cout << "Recharge successful." << endl;
    }

    // Deduct balance
    void deductBalance(float amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Balance deducted successfully." << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    // Display account details
    void displayAccount()
    {
        cout << "\nAccount Details" << endl;
        cout << "Mobile Number: " << mobileNumber << endl;
        cout << "Balance      : Rs. " << balance << endl;
    }
};

int main()
{
    // Creating an object
    MobileRecharge account1("9876543210", 100);

    account1.displayAccount();

    account1.recharge(200);
    account1.displayAccount();

    account1.deductBalance(50);
    account1.displayAccount();

    return 0;
}
 
