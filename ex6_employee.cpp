#include <iostream>
using namespace std;

class Employee
{
public:

    // Calculate salary using Basic Salary only
    double calculateSalary(double basic)
    {
        return basic;
    }

    // Calculate salary using Basic Salary and HRA
    double calculateSalary(double basic, double hra)
    {
        return basic + hra;
    }

    // Calculate salary using Basic Salary, HRA and DA
    double calculateSalary(double basic, double hra, double da)
    {
        return basic + hra + da;
    }
};

int main()
{
    // Create object of Employee class
    Employee emp;

    // Display calculated salaries
    cout << "Salary using Basic Salary only: "
         << emp.calculateSalary(30000) << endl;

    cout << "Salary using Basic Salary and HRA: "
         << emp.calculateSalary(30000, 5000) << endl;

    cout << "Salary using Basic Salary, HRA and DA: "
         << emp.calculateSalary(30000, 5000, 3000) << endl;

    return 0;
}