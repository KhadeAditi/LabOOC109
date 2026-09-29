#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:

    // Overloading extraction operator >>
    friend istream& operator>>(istream& in, Student& s)
    {
        cout << "Enter Roll No: ";
        in >> s.rollNo;

        cout << "Enter Name: ";
        in >> s.name;

        cout << "Enter Marks: ";
        in >> s.marks;

        return in;
    }

    // Overloading insertion operator <<
    friend ostream& operator<<(ostream& out, const Student& s)
    {
        out << "\nStudent Details" << endl;
        out << "Roll No : " << s.rollNo << endl;
        out << "Name    : " << s.name << endl;
        out << "Marks   : " << s.marks << endl;

        return out;
    }
};

int main()
{
    Student s;

    // Extraction operator
    cin >> s;

    // Insertion operator
    cout << s;

    return 0;
}