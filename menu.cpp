/* Created by :- Tushardeep Singh
   Date :- 19th November'2022
 */

// menu.cpp
#include "iostream"
#include "iomanip"
using namespace::std;

/*
 Function name : showMenu
 Input : no input
 Outputs the menu bar
 */
void showMenu(){
    int colSize {14};
    cout << right; // right justified
    cout << setfill('*'); // all blank spaces filled with *
    size_t index {1}; // option index
    
    cout << "*" << setw(colSize) << "MENU" << setw(colSize) << "*"<< endl;
    cout << index << ". Check Balance " << endl;
    cout << ++index << ". Deposit" << endl;
    cout << ++index << ". Withdraw" << endl;
    cout << ++index << ". Exit" << endl;
    cout << "*" << setw(colSize) << "" << setw(colSize) << "*"<< endl;
}
