#include"Queue.h"
#include<string>
#include<cstring>
#include<regex>
#include<cstdlib>
#include<istream>
#include<sstream>
#include<iostream>
using namespace std;

// Constructor
template<class Type>
Queue<Type>::Queue(int queue_size) : Queue_size(queue_size),
Contents(new Type[queue_size + 1]), 
Front(0), Back(0), counter(0){};

// Destructor
template <class Type>
Queue<Type>::~Queue()
{
    delete[] Contents;

};

// Tests

template <class Type>
int Queue<Type>::size() {
    return counter;
};

template <class Type>
bool Queue<Type>::Empty() const
{
    return (Front == Back) ? true : false;
};

template <class Type>
bool Queue<Type>::Full() const
{
    return ((1 + Back) % (Queue_size + 1) == Front) ? true : false;
};

// Remove and Add

template <class Type>
Type Queue<Type>::Remove(Type& front_element)
{
    if (Empty()) {
        
        cout << "Underflow error! Portfolio is empty" << endl;
        return false;
    }
    else
    {
        front_element = Contents[Front];
        Front = (Front + 1) % (Queue_size + 1);
        counter--;
        return Contents[Front];
        
    }
};

template <class Type>
bool Queue<Type>::Add(const Type& new_element)
{
    if (Full()) {

        cout << "Overflow error! Portfolio is full. Sell some purchases" << endl;
        return false;
    }
    else
    {
        Contents[Back] = new_element;
        Back = (Back + 1) % (Queue_size + 1);
        counter++;
        return true;

    }
};

// Display queue

template <class Type>
void Queue<Type>::PrintQueue() const {

    if (Empty()) {
        cout << "Underflow error! Queue is Empty." << endl;
    }
    else {

        cout << "The purchases in the portfolio are: " << endl;
        for (int i = Front; i < Back; i++) {
            cout << Contents[i] << " " << endl;
        }
    }
};
