#include <iostream>
using namespace std;

class Employee
{
private:
    int employeeID;
    string employeeName;
    double basicSalary;
    double HRA;
    double DA;

public:
    // Constructor
    Employee(int id, string name, double basic, double hra, double da)
    {
        employeeID = id;
        employeeName = name;
        basicSalary = basic;
        HRA = hra;
        DA = da;
    }

    // Calculate Gross Salary
    double calculateGrossSalary()
    {
        return basicSalary + HRA + DA;
    }

    // Display Employee Details
    void display()
    {
        cout << "Employee Details" << endl;
        cout << "------------------------" << endl;
        cout << "Employee ID   : " << employeeID << endl;
        cout << "Employee Name : " << employeeName << endl;
        cout << "Basic Salary  : " << basicSalary << endl;
        cout << "HRA           : " << HRA << endl;
        cout << "DA            : " << DA << endl;
        cout << "Gross Salary  : " << calculateGrossSalary() << endl;
    }

    // Destructor
    ~Employee()
    {
        cout << "\nEmployee object destroyed." << endl;
    }
};

int main()
{
    // Create object and initialize values using constructor
    Employee emp(101, "Aditi", 30000, 6000, 3000);

    // Display employee details
    emp.display();

    return 0;
}