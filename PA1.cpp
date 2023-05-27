#include"stacktemplate.h"
#include"Queue.template.h"
#include"Purchases.template.h"
#include<stack>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
#define size 10

void mainMenu(vector<int>& vect){
    
    cout << endl;
    cout << "-----------------------------Main Menu-----------------------------" << endl;
    cout << " What operation would you like to perform on your portfolio?" << endl;
    cout << " Portfolio Management:" << endl;
    cout << " 1. Add purchases to the portfolio." << endl;
    cout << " 2. View the LIFO and FIFO price of stock." << endl;
    cout << " 3. Make a sale of stock in the portfolio." << endl;
    cout << " 4. Exit." << endl;
    cout << "Enter a number to represent your choice." << endl;
    cout << endl;
    
    int choice;
    cin >> choice;
    vect.push_back(choice);
    return;
};

void startupMessage(vector<int>& vect) {

    cout << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << " Welcome to your portfolio." << endl;
    cout << " Follow the instructions in order to input the necessary transactions." << endl;
    cout << endl;
    cout << " ASSUMPTIONS:" << endl;
    cout << "  -A maximum of 10 purchases can be made in this portfolio." << endl;
    cout << "  -A minimum of 3 purchases can be made at a time." << endl;
    cout << "  -Once the Portfolio is full, purchases must be removed first in order to make new additions." << endl;
    
    return mainMenu(vect);
};


void portM(vector<int>& vect2){
    
    cout << endl;
    cout << "----------------------------------Portfolio Management----------------------------------------" << endl;
    cout << " Ready for purchases to be added to the portfolio..." << endl;
    cout << " Follow the instructions in order to input the necessary transactions." << endl;
    cout << endl << endl;
    cout << " How many purchases would you like to add to your portfolio?" << endl;

    int s_size; // Amount of purchases to be made
    cin >> s_size;

    if ((s_size > 10) || (s_size < 3)) {

        do {
            cout << endl;
            cout << " [ERROR] Not within the specified purchase limits." << endl;
            cout << " Adjust your demands and try again. Must be less than 10 purchases." << endl;
            cin >> s_size;

        } while (s_size > 10);
    }
   
    vect2.push_back(s_size);
    return;
};

void quitValidator() {

    cout << endl;
    cout << " You have selected to quit." << endl;
    cout << " Are you sure?" << endl;
    cout << " 1. Yes, I am sure. I wish to quit." << endl;

    int confirm;
    cin >> confirm;

    if (confirm == 1) {
     return;
    }
    else{
        while(!(confirm < 2)){
        cout << "Incorrect input. Please enter 1." << endl;

            int confirm;
            cin >> confirm;
        }
    }
};

int main() {

    int SIZE = size;
    vector<int> vect;
    vector<int> vect2;
    
    Purchases newP[10];
	Stack<Purchases> myStack(SIZE); // stack of purchases of maximum size 10
	Queue<Purchases> myQueue(SIZE); // queue of purchases of maximum size 10
    
    //variables
    string sq; // share query
    int sss; // share temp variable
    int sp; // stock query
    int sum1; // sum variable
    int counting; // count variable
    float prodL; // lifo price
    float prodF; // fifo price

    //Menu
	startupMessage(vect);
	
	switch (vect.back())
	{
	case 1:
	
        portM(vect2);
        
                 for(int i = 0; i < vect2.back(); i++)
                 {
                     //Populating array of purchases
                     newP[i].setstockN();
                     newP[i].setnoOfSh();
                     newP[i].setsharePP();
                     
                     //Populating Stack and Queue
                     myQueue.Add(newP[i]);
                     myStack.Push(newP[i]);
                 }
    
    
		break;
    case 2:
        
                myStack.stockquery(sq);
                myStack.sharequery(sp, sss);
                myStack.stockval(sp, sum1, sq, counting, prodL, prodF);
        
        break;
    case 3:
        
            myStack.stockquery(sq);
            myStack.sharequery(sp, sss);
            myStack.sellval();
            myStack.PrintStack();
        
        break;
	case 4:
	
		quitValidator();
	
	break;

	} while(vect[0] != 4)
        ;

    return 0;
	};
