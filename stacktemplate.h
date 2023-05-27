#include"stack.h"
#include<stack>
#include<cstdlib>
#include<string>
#include<cstring>
#include<iostream>
#include<istream>
#include<regex>
#include<sstream>
using namespace std;

// Constructor
template <class Type>
Stack<Type>::Stack(int stack_size) : Stack_size(stack_size),
Contents(new Type[stack_size]), index_of_top(-1),
counter(0) {};

// Destructor
template <class Type>
Stack<Type> :: ~Stack()
{
	delete[] Contents;
};

template <class Type>
bool Stack<Type>::Full() const
{
	return (index_of_top == Stack_size - 1) ? true : false;
};

// Push
template <class Type>
bool Stack<Type>::Push(const Type& new_element)
{
	if (Full()) {
        cout << "Overflow error! Portfolio is full." << endl;
		return false;
	}
	else {

		index_of_top++;
		Contents[index_of_top] = new_element;
		counter++;
		return true;
	}
};

//Size

template <class Type>
int Stack<Type>::size() {
	return counter;
};

template <class Type>
bool Stack<Type>::isEmpty() {
	if (index_of_top == -1) {
		// stack is empty
		return true;
	}
	else
	{
		return false;
	}
};

// Pop
template <class Type>
Type Stack<Type>::Pop(Type& top_element)
{
	if (isEmpty())
    {
		cout << "Underflow error! Stack is empty." << endl;
	}
	else
    {
		top_element = Contents[index_of_top];
		index_of_top--;
		counter--;
		return Contents[index_of_top];
	}
};

// Top
template <class Type>
Type Stack<Type> ::Top() const
{
	if (isEmpty())
    {
		Type x = Type();
		return x;
	}
	else
    {
		return Contents[index_of_top];
	}
};

// PrintStack
template <class Type>
void Stack<Type>::PrintStack() const
{
   
    cout << endl;
    cout << "-----------------------------PORTFOLIO OVERVIEW-----------------------------------------" << endl;
    cout << "\nLIFO Portfolio after sales: \n";
    
	for (int i = index_of_top; i >= 0; i--) {
cout << Contents[i].getnoOfSh() << " shares of " << Contents[i].getstockN() << "at £" << Contents[i].getsharePP() << " per share." << endl;
	}
};

// Delete
template <class Type>
Type Stack<Type>::Delete(Type& del_element)
{
	if (isEmpty()) {
		return 1;
	}

	for (int i = index_of_top; i >= 0; i--) {
		if (Contents[i] == del_element) {
			for (int j = i; j < index_of_top; j++) {
				Contents[j] = Contents[j + 1];
			}
			index_of_top -= 1;

		}
	}
};

template <class Type>
void Stack<Type>::stockquery(string &stocks){
    
    cout << endl;
    cout << " [STRING] Name of stock." << endl;
    cout << " Enter the name of the stock position in question." << endl;
    cout << " [CAVEAT] Without any numeric, LESS THAN 5 characters:" << endl;
    cin.ignore();
    string stockq;
    getline(cin, stockq);
    cin.clear();// clear the buffer for future queries

    regex reg1("[0-9]+"); // regex search condition to check for presence of number 0-9 in stock name variable
    bool match = regex_search(stockq, reg1);

if((match == true) || (stockq.size() > 4)) { // if matched loop until the right values specified

            cout << endl;
            cout << "[ERROR] Credentials incorrect!" << endl;
            cout << "Enter the stock name, without any numeric, LESS THAN 5 characters:" << endl;
            stockquery(stocks);
        }
    else
    {
        
    // if not matched continue as normal
    sq.push_back(stockq);
    stocks = sq[0];
    return;
    
    }};

template <class Type>
void Stack<Type>::sharequery(int &shares, int &share_query){
    
    cout << endl;
    cout << " [INTEGER] Number of shares." << endl;
    cout << " Enter the quantity of the shares you would like to view." << endl;
    cout << " [INTEGER] Enter a number ONLY:" << endl;
    cin >> share_query;
    
    SQ.push_back(share_query);
    shares = SQ[0];
    
    while (cin.fail())
    {
            cout << endl;
            cout << " [ERROR] Validate input and enter integers only." << endl;
            sharequery(shares, share_query); //recurse function until correct
    }

    return;
};

template <class Type>
int Stack<Type>::LIFOp(int &shares, int &sum, string &stocks, int &count)
{
     count = 0;
     sum = 0;
    
    for (int i = index_of_top; i >= 0; i--) {
        
        if (this->Contents[i].getstockN() == stocks)
        {
          sum += Contents[i].getnoOfSh();
            
          count++;
        }
    }
        
    if(count == 0){
        
        cout << endl;
        cout << "Error! This stock is not present in your portfolio." << endl;
        cout << "Validate your input and re-input the desired stock" << endl;
        cout << "Enter the name of the stock you wish to view:" << endl;
        cin.ignore();
        getline(cin, stocks);
        
        LIFOp(shares, sum, stocks, count);
       
    };
    
    return 2;
    
}
    
template <class Type>
void Stack<Type>::checkerLIFO(float &productLIFO){
    
    sum1 = SQ[0];
    int subtraction;
    float multiplication;
    
    for (int i = index_of_top; i >= 0; i--)
    {
        if (this->Contents[i].getstockN() == stocks)
        {
              subtraction = this->Contents[i].getnoOfSh();
              multiplication = this->Contents[i].getsharePP();
              SUMF.push_back(multiplication);
                
                for(int i =0; i < subtraction; i++)
                {
                    SUMI.push_back(1);
                }
              
                for (int i = 0; i < SUMI.size(); i++)
                {
                    if(sum1 == 0)
                    {
                        productLIFO += i * SUMF[0];
                        SUMI.clear();
                        SUMF.clear();
                       
                    }
                    sum1 -= SUMI[i];
                    
                    if ((sum1 != 0) && (i == SUMI.back()))
                    {
                        productLIFO += SUMI.size() * SUMF[0];
                        SUMI.clear();
                        SUMF.clear();
                    }
                }
        }
    }
};

template <class Type>
void Stack<Type>::checkerFIFO(float &productFIFO){
    sum2 = SQ[0];
    int subtraction;
    float multiplication;
    
    for (int i = 0; i < index_of_top; i++)
    {
        if (this->Contents[i].getstockN() == stocks)
        {
              subtraction = this->Contents[i].getnoOfSh();
              multiplication = this->Contents[i].getsharePP();
              SUMF2.push_back(multiplication);
                
                for(int i = 0; i < subtraction; i++)
                {
                    SUMI2.push_back(1);
                }
              
                for (int i = 0; i < SUMI2.size(); i++)
                {
                    if(sum1 == 0)
                    {
                        productLIFO += i * SUMF2[0];
                        SUMI2.clear();
                        SUMF2.clear();
                    }
                    sum1 -= SUMI[i];
                    
                    if ((sum1 != 0) && (i == SUMI2.back()))
                    {
                        productLIFO += SUMI2.size() * SUMF2[0];
                        SUMI2.clear();
                        SUMF2.clear();
                    }
                }
        }
    }
};

template <class Type>
void Stack<Type>::stockval(int &shares, int &sum, string &stocks, int &count, float &productLIFO, float &productFIFO)
{
    if (LIFOp(shares, sum, stocks, count) == 2)
    {
        if (shares > sum)
        {
            cout << endl;
            cout << "[ERROR] You have specified an amount you do not have in your portfolio." << endl;
            cout << "Enter the number of shares of this stock:" << endl;
            cin >> shares;
            cout << endl;
            stockval(shares, sum, stocks, count, productLIFO, productFIFO);
        }
        
        else
        {
            sum2 = SQ[0];
            
            checkerLIFO(productLIFO);
            checkerFIFO(productFIFO);
            
            LIFOprice = (productLIFO / sum);
            FIFOprice = (productFIFO / sum);
            
            transform(stocks.begin(), stocks.end(), stocks.begin(), ::toupper);
            
            cout << endl;
            cout << "-----------------------------PORTFOLIO VALUATION-----------------------------------------" << endl;
            cout << "\nSale Prices: \n";
            cout << "\tLIFO stock valuation for " << stocks << " is £" << LIFOprice << " per share." << endl;
            cout << "\tFIFO stock valuation for " << stocks << " is £" << FIFOprice << " per share." << endl;
    }
    }
        return;
    };
  
template <class Type>
void Stack<Type>::stockvalP(){
    
   stockval(shares, sum, stocks, count);

    return;
    
};

// Overloaded output operator
template <class Type>
ostream& operator<<(ostream& o, const Stack<Type>& s)
{
    for (int i = s.index_of_top; i >= 0; i--) {
        o << s.Contents[i] << endl;
    }
    return o;
};

template <class Type>
void Stack<Type>::sellLIFO(){
    
    sum1 = SQ[0];
    int subtraction;
    float multiplication;
    
    for (int i = index_of_top; i >= 0; i--)
    {
        if (this->Contents[i].getstockN() == stocks)
        {
              subtraction = this->Contents[i].getnoOfSh();
              multiplication = this->Contents[i].getsharePP();
              SUMF.push_back(multiplication);
                
                for(int i =0; i < subtraction; i++)
                {
                    SUMI.push_back(1);
                }
              
                for (int i = 0; i < SUMI.size(); i++)
                {
                    if(sum1 == 0)
                    {
                        
                        this->Contents[i].setnoOfShF(i);
                        SUMI.clear();
                        SUMF.clear();
                       
                    }
                    sum1 -= SUMI[i];
                    
                    if ((sum1 != 0) && (i == SUMI.back()))
                    {
                       int j = i;
                      Contents[j] = Contents[j + 1];
                        index_of_top -= 1;
                        counter--;
                    
                        SUMI.clear();
                        SUMF.clear();
                    }
                }
        }
    }
};

template <class Type>
void Stack<Type>::sellFIFO(){
    
    sum1 = SQ[0];
    int subtraction;
    float multiplication;
    
    for (int i = 0; i < index_of_top; i++)
    {
        if (this->Contents[i].getstockN() == stocks)
        {
              subtraction = this->Contents[i].getnoOfSh();
              multiplication = this->Contents[i].getsharePP();
              SUMF.push_back(multiplication);
                
                for(int i =0; i < subtraction; i++)
                {
                    SUMI.push_back(1);
                }
              
                for (int i = 0; i < SUMI.size(); i++)
                {
                    if(sum1 == 0)
                    {
                        
                        this->Contents[i].getnoOfSh() = i;
                        SUMI.clear();
                        SUMF.clear();
                       
                    }
                    sum1 -= SUMI[i];
                    
                    if ((sum1 != 0) && (i == SUMI.back()))
                    {
                       int j = i;
                      Contents[j] = Contents[j + 1];
                        index_of_top -= 1;
                        counter--;
                    
                        SUMI.clear();
                        SUMF.clear();
                    }
                }
        }
    }
};


template <class Type>
void Stack<Type>::sellval(int &shares, int &sum, string &stocks, int &count)
{
    if (LIFOp(shares, sum, stocks, count) == 2)
    {
        if (shares > sum)
        {
            cout << endl;
            cout << "[ERROR] You have specified an amount you do not have in your portfolio." << endl;
            cout << "Enter the number of shares of this stock:" << endl;
            cin >> shares;
            cout << endl;
            sellval(shares, sum, stocks, count);
        }
        else{
            
            sellLIFO();
          
        }
        
    }
    
}

template <class Type>
void Stack<Type>::sellval()
{
    sellval(shares, sum, stocks, count);
    
};


