#include <iostream>
using namespace std;

// Base Class
class Employee
{
protected:
    int employeeID;
    string employeeName;
    string department;

public:

    void getEmployeeDetails()
    {
        cout << "Enter Employee ID: ";
        cin >> employeeID;

        cout << "Enter Employee Name: ";
        cin >> employeeName;

        cout << "Enter Department: ";
        cin >> department;
    }

    void displayEmployeeDetails()
    {
        cout << "\nEmployee ID   : " << employeeID;
        cout << "\nEmployee Name : " << employeeName;
        cout << "\nDepartment    : " << department;
    }
};


// Derived Class 1
class TeachingStaff : public Employee
{
private:
    string subject;
    string qualification;

public:

    void getTeachingDetails()
    {
        getEmployeeDetails();

        cout << "Enter Subject: ";
        cin >> subject;

        cout << "Enter Qualification: ";
        cin >> qualification;
    }

    void displayTeachingDetails()
    {
        displayEmployeeDetails();

        cout << "\nSubject       : " << subject;
        cout << "\nQualification : " << qualification << endl;
    }
};


// Derived Class 2
class NonTeachingStaff : public Employee
{
private:
    string designation;
    int workingHours;

public:

    void getNonTeachingDetails()
    {
        getEmployeeDetails();

        cout << "Enter Designation: ";
        cin >> designation;

        cout << "Enter Working Hours: ";
        cin >> workingHours;
    }

    void displayNonTeachingDetails()
    {
        displayEmployeeDetails();

        cout << "\nDesignation   : " << designation;
        cout << "\nWorking Hours : " << workingHours << endl;
    }
};


int main()
{
    // Object of TeachingStaff
    TeachingStaff teacher;

    cout << "\n===== Teaching Staff =====\n";
    teacher.getTeachingDetails();

    cout << "\n----- Employee Details -----";
    teacher.displayTeachingDetails();


    // Object of NonTeachingStaff
    NonTeachingStaff staff;

    cout << "\n\n===== Non-Teaching Staff =====\n";
    staff.getNonTeachingDetails();

    cout << "\n----- Employee Details -----";
    staff.displayNonTeachingDetails();

    return 0;
}