#include <iostream>
using namespace std;

class Box
{
private:
    double length;
    double width;
    double height;

public:

    // 1. Default Constructor
    Box()
    {
        length = 1.0;
        width = 1.0;
        height = 1.0;
    }

    // 2. Parameterized Constructor
    Box(double l, double w, double h)
    {
        length = l;
        width = w;
        height = h;
    }

    // 3. Copy Constructor
    Box(const Box &b)
    {
        length = b.length;
        width = b.width;
        height = b.height;
    }

    // Calculate Volume
    double calculateVolume()
    {
        return length * width * height;
    }

    // Display Box Information
    void display()
    {
        cout << "Length : " << length << endl;
        cout << "Width  : " << width << endl;
        cout << "Height : " << height << endl;
        cout << "Volume : " << calculateVolume() << endl;
    }

    // Destructor
    ~Box()
    {
        cout << "Box object destroyed." << endl;
    }
};

int main()
{
    // Object using Default Constructor
    Box box1;

    cout << "Box 1 (Default Constructor)" << endl;
    box1.display();

    cout << endl;

    // Object using Parameterized Constructor
    Box box2(10.0, 5.0, 4.0);

    cout << "Box 2 (Parameterized Constructor)" << endl;
    box2.display();

    cout << endl;

    // Object using Copy Constructor
    Box box3(box2);

    cout << "Box 3 (Copy Constructor)" << endl;
    box3.display();

    cout << endl;

    return 0;
}