#pragma once
#include<string>
#include<regex>
#include<sstream>
#include<iostream>
#include<stdio.h>

class Purchases {

private:
// Variables
	std::string stockN; // stores name of stock
	int noOfSh;   // stores number of shares
	float sharePP; // stores share purchase price
 
public:
    
    // constructor
    Purchases();

	//Public functions
    void setstockN();
    void setnoOfSh();
    void setsharePP();
    
	std::string getstockN();
	int getnoOfSh();
	float getsharePP();
    
    void setnoOfShF(int i);
    
};


