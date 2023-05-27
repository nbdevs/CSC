#pragma once
#include"Purchases.h"
#include<string>
#include<regex>
#include<sstream>
#include<iostream>
#include<stdio.h>
using namespace std;

Purchases::Purchases() : stockN(), noOfSh(0), sharePP(0){
    
};

void Purchases::setstockN()
{

    cout << endl;
    cout << " [STRING] Name of stock." << endl;
    cout << " Enter the name of the stock position you would like to open:" << endl;
    cout << " Enter the stock name, without any numeric, LESS THAN 10 characters:" << endl;
    string stock;
    cin.ignore();
    getline(cin, stock);
    cin.clear();// clear the buffer for future queries

    regex reg1("[0-9]+"); // regex search condition to check for presence of number 0-9 in stock name variable
    bool match = regex_search(stock, reg1);

if((match == true) || (stockN.size() > 4)) { // if matched loop until the right values specified

            cout << endl;
            cout << "[ERROR] Credentials incorrect!" << endl;
            Purchases::setstockN();
            return;
        }
         // if not matched continue as normal
         stockN = stock;
          return;
};

    void Purchases::setnoOfSh() {
        
        cout << endl;
        cout << " [INTEGER] Number of shares." << endl;
        cout << " Enter the quantity of the shares you would like to view." << endl;
        cout << " [INTEGER] Enter a number ONLY:" << endl;
        cin >> noOfSh;
   
        while (cin.fail())
        {
                cout << endl;
                cout << " [ERROR] Validate input and enter integers only." << endl;
                Purchases::setnoOfSh(); //recurse function until correct
        }
        return;
};

void Purchases::setsharePP() {

    cout << endl;
    cout << " [FLOAT] Per share purchase price of stock." << endl;
    cout << " Enter the per share purchase price of the stock:" << endl;
    float shareP;
    cin >> shareP;
    
    sharePP = shareP;
};

//Public accessors
string Purchases::getstockN() {
 return stockN;
};

int Purchases::getnoOfSh() {
return noOfSh;
};

float Purchases::getsharePP() {
return sharePP;
};

void Purchases::setnoOfShF(int i) {
    
     noOfSh = i;

};
