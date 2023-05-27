#pragma once
#include<string>
#include<vector>
#include<iostream>
using namespace std;

template <class Type>
class Queue 
{
private:
	Type *Contents; // pointer to purchases objects 
	int Queue_size;
	int Front, Back;
	int counter;
	
public:
	Queue(int queue_size);
	~Queue();

	int size();
	bool Empty() const;
	bool Full() const;

	Type Remove(Type& front_element);
	bool Add(const Type& new_element);

	void PrintQueue() const;

    friend ostream& operator<< (ostream&, const Queue<Type>&);

}; 

