#include<iostream>
#include<iomanip>
using namespace std;

class Time 
{
    int hours,minutes,seconds;

public:
    void accept()
    {
        cout<<"Enter Hours :";
        cin>>hours;
        cout<<"enter Minutes :";
        cin>>minutes;
        cout<<"Enter Second :";
        cin>>seconds;

    }
    
    Time add(Time t)
    {
        Time result;
        result.seconds=seconds + t.seconds;
        result.minutes=minutes + t.minutes;
        result.hours=hours + t.hours;

        if(result.seconds >= 60)
        {
            result.seconds -= 60;
            result.minutes++;
        }
        if(result.minutes >= 60){
            result.minutes -= 60;
            result.hours++;
        }

        return result;
    }
    void display(){
       cout<<setfill('0') <<setw(2)<< hours <<":"
       << setw(2)<< minutes <<":"
       <<setw(2) <<seconds <<endl;
    }

};

int main(){
    Time t1,t2,result;
    cout<<"Enter The First Time :"<<endl;
    t1.accept();

    cout<<"Enter the Second Time :"<<endl;
    t2.accept();

    result=t1.add(t2);

    cout<<"Resultant time :";
    result.display();
}