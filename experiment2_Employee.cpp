#include<iostream>
#include<string>
using namespace std;

class Employee{

      int emp_Id;
      string emp_name;
      string department;
      float basic_salary;

    public:
      void inputDetails(){
        cout<<"Enter employee Id :";
        cin>>emp_Id;
        cout<<"Enter Employee Name :";
        cin>>emp_name;
        cout<<"Enter the Department :";
        cin>>department;
        cout<<"enter the  basic salary:";
        cin>>basic_salary;
      }

      float calculateAnnul_salary(){
        return basic_salary * 12 ;

      }

      void displayDetails(){
        cout<<".....Employee Details......"<< endl;
        cout<<"ID :"<<emp_Id<< endl;
        cout<<"Name :"<<emp_name<< endl;
        cout<<"Department :"<<department<< endl;
        cout<<"Basic Salary :"<<basic_salary<< endl;
        cout<<"Annual Salary :"<<calculateAnnul_salary()<< endl;

      }

};
int main(){
    Employee e;
    e.inputDetails();
    e.displayDetails();
 return 0;
}