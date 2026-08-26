#include<iostream>
using namespace std;
int main(){
    string name;
    int units;
    double bill=0;

    cout<<"enter the name of consumer :";
    cin>>name;
    cout<<"enter units consumed :";
    cin>>units;

    if(units<=100){
        bill = units * 5;
    }
    else if(units<=200){
        bill = (100*5) + ((units-100) * 7);
    }
    else if(units<=300){
        bill = (100*5) + (100*7) + ((units-200) * 10);
    }
    else{
        bill = (100*5) + (100*7) + (100*10) + ((units-300) * 12);
    }

    cout<<"consumer name :"<<name<<endl;
    cout<<"units consumed :"<<units<<endl;
    cout<<"total bill : "<<bill;
    return 0;
}