#include <iostream>
using namespace std;

class Matrix
{
private:
    int mat[2][2];

public:

    // Function to accept matrix elements
    void getData()
    {
        cout << "Enter 4 elements of matrix:" << endl;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display matrix
    void display()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overload + operator for matrix addition
    Matrix operator+(const Matrix& m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }

        return result;
    }

    // Overload - operator for matrix subtraction
    Matrix operator-(const Matrix& m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.mat[i][j] = mat[i][j] - m.mat[i][j];
            }
        }

        return result;
    }

    // Overload == operator to compare two matrices
    bool operator==(const Matrix& m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (mat[i][j] != m.mat[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Matrix m1, m2, addition, subtraction;

    // Input first matrix
    cout << "Enter elements of Matrix 1:" << endl;
    m1.getData();

    // Input second matrix
    cout << "\nEnter elements of Matrix 2:" << endl;
    m2.getData();

    // Matrix addition
    addition = m1 + m2;

    cout << "\nMatrix Addition:" << endl;
    addition.display();

    // Matrix subtraction
    subtraction = m1 - m2;

    cout << "\nMatrix Subtraction:" << endl;
    subtraction.display();

    // Matrix comparison
    if (m1 == m2)
    {
        cout << "\nBoth matrices are equal." << endl;
    }
    else
    {
        cout << "\nBoth matrices are not equal." << endl;
    }

    return 0;
}