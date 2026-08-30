#include<iostream>
using namespace std;

class Fraction
{
    int numerator,denominator;

public :
   void accept()
   {
     cout<<"Enter Numerator :";
     cin>> numerator;

     cout<<"Enter Denominator :";
     cin>>denominator;
   }

   Fraction add(Fraction f)
   {
     Fraction  result;

     if(denominator == f.denominator)
     {
        result.numerator = numerator + f.numerator;
        result.denominator = denominator;
     }
     else
     {
        result.numerator = (numerator * f.denominator) + (f.numerator * denominator);
        result.denominator = denominator * f.denominator;
     }
     return result;
   }

   Fraction subtract(Fraction f)
   {
     Fraction  result;

     if(denominator == f.denominator)
     {
        result.numerator = numerator - f.numerator;
        result.denominator = denominator;
     }
     else
     {
        result.numerator = (numerator * f.denominator) - (f.numerator * denominator);
        result.denominator = denominator * f.denominator;
     }
     return result;
   }

   void display(){
    int a = numerator;
    int b = denominator;

    while(b != 0){
        int temp =b;
        b = a % b;
        a= temp;
    }

    numerator = numerator / a;
    denominator = denominator / a;

    cout<<numerator << "/" <<denominator <<endl;
   }

};
int main(){
    Fraction f1,f2 ,sum ,diff;

    cout<<"Enter First Fraction :"<<endl;
    f1.accept();

    cout<<"enter second fraction :"<<endl;
    f2.accept();

    sum=f1.add(f2);
    diff=f1.subtract(f2);

    cout<<"Addition =";
    sum.display();

    cout<<"substraction =";
    diff.display();


    return 0;
}