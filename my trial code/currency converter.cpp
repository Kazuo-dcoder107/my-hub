#include <iostream>
#include<string>
using namespace std;

int main(){
    double pesos;
    string currency;

    cout<<"CURRENCY CONVERTER\n"; 
    cout<<"Enter the Philippine Pesos you want to convert:\n";
    cin>>pesos;
    double dollar = pesos*0.017;
    double pound = pesos*0.014;
    double canadian_dollar = pesos*0.024;

    cout<<"Enter USD for converting PHP to USD , GBP for PHP to GBP, or CAD for PHP to CAD:\n";
    cin>>currency;

    if (currency == "USD"){
        cout<<pesos<< "Philippine Pesos In Dollars = "<<dollar;
    }
    else if(currency == "GBP"){
        cout<<pesos<< "Philippine Pesos In Pounds = "<<pound;
    }
    else if (currency == "CAD"){
        cout<<pesos<< "Philippine Pesos In Canadian Dollar = "<<canadian_dollar;
    }
    else{
        cout<<"That's An Invalid Input! Please Try Again. ";
    }
}
