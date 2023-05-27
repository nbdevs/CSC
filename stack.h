#pragma once
#include<iostream>
#include<vector>

template<class Type>
class Stack
{
private:
	Type* Contents; // pointer to purchases object  
	int Stack_size; // maximum size of the stack array 
	int index_of_top; // top element in the stack
	int counter; //counter variable for size of stack
    int shares; // LIFO variable for share query
    std::string stocks; // variable for stock name query
    float productLIFO; //LIFO product variable
    int sum; // sum of total shares variable
    int count; //loop variable for stock name
    
    int sum1, sum2; // variable for reducing the shares from the sum amount
    std::string share_query;
    
    float productFIFO; // FIFO product variable
    float FIFOprice;
    float LIFOprice;
    
public:
	Stack(int stack_size);
	~Stack();
	bool Full() const;
	bool Push(const Type& new_element);
	Type Pop(Type& top_element);
    
	int size();
	bool isEmpty();
	void PrintStack() const;
	Type Top() const;
    
	Type Delete(Type& del_element);
    
    void stockquery(std::string &stocks);
    void sharequery(int &shares, int &share_query);
    void checkerLIFO(float &productLIFO);
    void checkerFIFO(float &productFIFO);
    
    int LIFOp(int &shares, int &sum, std::string &stocks, int &count);
    void stockval(int &shares, int &sum, std::string &stocks, int &count, float &productLIFO, float &productFIFO);
    void stockvalP();
    void sellval(int &shares, int &sum, std::string &stocks, int &count);
    void sellval();
    
    void sellLIFO();
    void sellFIFO();
    
    
   friend std::ostream& operator<< (std::ostream& o, const Stack<Type>& s);
    
    //Vectors
    std::vector<std::string> sq; //stock query vector container
    std::vector<int> SQ; // share query vector container
    
    //For stack
    std::vector<int> SUMI; // sum variable for integers, vector container
    std::vector<float> SUMF; // sum variable for floats, vector container
    
    //For queue
    std::vector<int> SUMI2; // sum variable for integers, vector container
    std::vector<float> SUMF2; // sum variable for floats, vector container
};

