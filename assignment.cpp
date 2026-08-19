#include<iostream>
#include<string>
using namespace std;
class Student{
private:
   Sting name;
   int roll_no;
   float marks;
public:
void inputDetails(){
  cout<<"enter name:";
  cin>>name;
  cout<<"enter roll number:;
  cin>>roll_no;
  cout<<"enter marks:";
  cin>>marks;
}
void displaydetails(){
  cout<<"student information"<<endl;
  cout<<"name= "<<name;
  cout<<"roll no= "<<roll_no;
  cout<<"marks= "<<marks;
}
};
int main(){
  Student s;
  s.inputDetails();
  s.displayDetails();
return 0;
}
