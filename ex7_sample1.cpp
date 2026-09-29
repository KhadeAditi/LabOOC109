#include <iostream>
#include <stdio.h>

using namespace std;

// Base Class
class Student
{
    int roll;
    char name[25];

public:

    void getdata()
    {
        cout << "\n-----------------------------------------";
        cout << "\nEnter Roll No. : ";
        cin >> roll;

        cout << "\nEnter Student Name : ";
        cin >> name;
    }

    void putdata()
    {
        cout << "\n-----------------------------------------";
        cout << "\n********** Student Marklist **********";
        cout << "\n-----------------------------------------";

        cout << "\nRoll No. : " << roll;
        cout << "\nStudent Name : " << name << endl;
    }
};


// Derived Class 1
class StudentExam : public Student
{
public:
    int sub1, sub2, sub3, sub4, sub5, sub6;
    float per;

    void accept_data()
    {
        getdata();

        cout << "\nEnter Marks for Subject 1 : ";
        cin >> sub1;

        cout << "\nEnter Marks for Subject 2 : ";
        cin >> sub2;

        cout << "\nEnter Marks for Subject 3 : ";
        cin >> sub3;

        cout << "\nEnter Marks for Subject 4 : ";
        cin >> sub4;

        cout << "\nEnter Marks for Subject 5 : ";
        cin >> sub5;

        cout << "\nEnter Marks for Subject 6 : ";
        cin >> sub6;
    }

    void display_data()
    {
        putdata();

        cout << "\nMarks of Subject 1 : " << sub1;
        cout << "\nMarks of Subject 2 : " << sub2;
        cout << "\nMarks of Subject 3 : " << sub3;
        cout << "\nMarks of Subject 4 : " << sub4;
        cout << "\nMarks of Subject 5 : " << sub5;
        cout << "\nMarks of Subject 6 : " << sub6;
    }
};


// Derived Class 2
class StudentResult : public StudentExam
{
public:

    void calculate()
    {
        per = (sub1 + sub2 + sub3 + sub4 + sub5 + sub6) / 6.0;

        cout << "\n\nTotal Percentage : " << per;
        cout << "\n-----------------------------------------\n";
    }
};


int main()
{
    // Object of derived class StudentResult
    StudentResult str;

    int cnt, i;

    cout << "\nEnter No. of Students You Want? : ";
    cin >> cnt;

    for (i = 0; i < cnt; i++)
    {
        str.accept_data();
        str.display_data();
        str.calculate();
    }

    return 0;
}