#include<iostream>
#include<string>
using namespace std;

class Student{
    private :
      string name;
      int rollNo;
      float marks;
    
    public :
      void inputDetails(){
        cout<<"enter student name :";
        cin>>name;
        cout<<"enter Roll Number :";
        cin>>rollNo;
        cout<<"enter the marks :";
        cin>>marks;
      }

      void displayDetails(){
        cout<<"-----student Details------\n";
        cout<<"Student Name :"<<name<<endl;
        cout<<"Student Roll No :"<<rollNo<<endl;
        cout<<"student Marks :"<<marks<<endl;
        
      }

};
int main(){
Student s;
s.inputDetails();
s.displayDetails();
return 0;
}