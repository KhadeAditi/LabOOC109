#include<iostream>
using namespace std;
int main(){
     int a,b,choice;

     cout<<".....Calculator Menu........";
     cout<<"1. Addition"<<endl;
     cout<<"2. Substraction"<<endl;
     cout<<"3. Multiplication"<<endl;
     cout<<"4. Division"<<endl;
     cout<<"5. Modulus"<<endl;
     cout<<"6. Exit"<<endl;

     cout<<"Enter the choice :";
     cin>>choice;

     switch(choice){
        case 1:
           cout<<"enter two numbers :";
           cin>>a>>b;
           cout<<"Addition = "<<a+b;
           break;
        
        case 2:
           cout<<"enter two numbers :";
           cin>>a>>b;
           cout<<"Substraction = "<<a-b;
           break;

        case 3:
           cout<<"enter two numbers :";
           cin>>a>>b;
           cout<<"Multiplication = "<<a * b;
           break;

        case 4:
           cout<<"enter two numbers :";
           cin>>a>>b;
           cout<<"Divison = "<<a / b;
           break;

        case 5:
           cout<<"enter two numbers :";
           cin>>a>>b;
           cout<<"Modulus = "<<a % b;
           break;

        case 6:
          cout<<"Exit";
          break;

        default :
          cout<<"invalid choice.";


     }
return 0;    
}