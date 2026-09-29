#include <iostream>
using namespace std;

class Patient
{
private:
    string name;
    int age;
    string disease;
    float consultationCharge;

public:
    // Constructor
    Patient(string n, int a, string d)
    {
        name = n;
        age = a;
        disease = d;
        consultationCharge = 0;
    }

    // Calculate consultation charges
    void calculateCharge()
    {
        consultationCharge = 500;
    }

    // Display patient information
    void displayPatient()
    {
        cout << "\nPatient Information" << endl;
        cout << "Name       : " << name << endl;
        cout << "Age        : " << age << endl;
        cout << "Disease    : " << disease << endl;
        cout << "Charge     : Rs. " << consultationCharge << endl;
    }
};

int main()
{
    // Creating an object
    Patient patient1("Aditi", 20, "Fever");

    patient1.calculateCharge();
    patient1.displayPatient();

    return 0;
}
 
