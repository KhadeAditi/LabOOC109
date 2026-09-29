#include <iostream>
using namespace std;

// Function declarations
int area(int);
int area(int, int);
float area(float);
float area(float, float);

int main()
{
    int s, l, b;
    float r, bs, ht;

    // Input for square
    cout << "Enter side of a square: ";
    cin >> s;

    // Input for rectangle
    cout << "Enter length and breadth of rectangle: ";
    cin >> l >> b;

    // Input for circle
    cout << "Enter radius of circle: ";
    cin >> r;

    // Input for triangle
    cout << "Enter base and height of triangle: ";
    cin >> bs >> ht;

    // Display areas
    cout << "\nArea of square is " << area(s);
    cout << "\nArea of rectangle is " << area(l, b);
    cout << "\nArea of circle is " << area(r);
    cout << "\nArea of triangle is " << area(bs, ht);

    return 0;
}

// Area of square
int area(int s)
{
    return s * s;
}

// Area of rectangle
int area(int l, int b)
{
    return l * b;
}

// Area of circle
float area(float r)
{
    return 3.14 * r * r;
}

// Area of triangle
float area(float bs, float ht)
{
    return (bs * ht) / 2;
}