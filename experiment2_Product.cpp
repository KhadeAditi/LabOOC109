#include<iostream>
#include<string>
using namespace std;

class Product{
    int product_Id;
    string product_name;
    int quantity;
    float unitPrice;

public :
   void inputDetails(){
    cout<<"enter product id :";
    cin>>product_Id;
    cout<<"enter product name:";
    cin>>product_name;
    cout<<"enter the quantity :";
    cin>>quantity;
    cout<<"Enter the unit price :";
    cin>>unitPrice;
}
  float totalCost(){
    return quantity * unitPrice;
  }

  void displayDetails(){
    cout<<"\n.....Product Information....."<<endl;
    cout<<"ID = "<<product_Id<<endl;
    cout<<"Product Name = "<<product_name<<endl;
    cout<<"Quantity = "<<quantity<<endl;
    cout<<"Unit-Price = "<<unitPrice<<endl;
    cout<<"Cost = "<<totalCost()<<endl;

  }

};
int main(){
    Product p;
    p.inputDetails();
    p.displayDetails();

return 0;
}