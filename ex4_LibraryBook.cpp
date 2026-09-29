
#include <iostream>
using namespace std;

class LibraryBook
{
private:
    string bookName;
    string author;
    bool issued;

public:
    // Constructor
    LibraryBook(string name, string a)
    {
        bookName = name;
        author = a;
        issued = false;
    }

    // Member function to issue book
    void issueBook()
    {
        if (issued == false)
        {
            issued = true;
            cout << "Book issued successfully." << endl;
        }
        else
        {
            cout << "Book is already issued." << endl;
        }
    }

    // Member function to return book
    void returnBook()
    {
        if (issued == true)
        {
            issued = false;
            cout << "Book returned successfully." << endl;
        }
        else
        {
            cout << "Book is already available." << endl;
        }
    }

    // Member function to display book
    void displayBook()
    {
        cout << "\nBook Name: " << bookName << endl;
        cout << "Author: " << author << endl;

        if (issued == true)
            cout << "Status: Issued" << endl;
        else
            cout << "Status: Available" << endl;
    }
};

int main()
{
    // Creating an object
    LibraryBook book1("The Alchemist", "Paulo Coelho");

    book1.displayBook();

    book1.issueBook();
    book1.displayBook();

    book1.returnBook();
    book1.displayBook();

    return 0;
}
 