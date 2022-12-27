/* Created by :- Tushardeep Singh
   Date :- 19th November'2022
 */

// transaction.cpp
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include "menu.h"
using namespace::std;

/*
 Funtion name : transactions
 Input : option, depositAmount, withdrawAmount
 Prompts the user to select an option and user accordingly enters depositAmount, withdrawAmount
 */
void transactions(){
        size_t option;
    
        // case : Deposit
        double* depositAmount {new double (0)};
        size_t* number_of_deposits {new size_t (0)};
        double balance {0};
        double& total_deposited_amount {balance}; // since balance = total_deposited_amount = 0, everytime program executes.
        const size_t* transaction_limit {new const size_t (4)};
        const size_t* min_deposit {new const size_t (1)};
        const size_t* max_deposit {new const size_t (50000)};
        const size_t* acc_limit {new const size_t (100000)};
        double* deposit_array {new double[*transaction_limit]}; // deposit_array used to store each successfull deposit
        size_t* deposit_count {new size_t (0)}; // used to provide correct index to each successfull deposit, ++ after each successfull deposit.


    
        // case : withdrawl
        size_t* number_of_withdrawls {new size_t (0)};
        double* withdrawAmount {nullptr};
        withdrawAmount = new double;
        const size_t* max_withdraw_limit {new const size_t (2000)};
        const size_t* min_withdraw_limit {new const size_t(50)};
        double* withdraw_array {new double[*transaction_limit]}; // withdraw_array used to store each successfull withdrawl
        size_t* withdraw_count {new size_t (0)}; // used to provide correct index to each suuccessful withdraw, ++ after each successful withdraw
        
        // case : exit
        double* deposit_sum {new double (0)};
        double* withdraw_sum {new double {0}};
    
        // Extras :
        string err {"ERROR.. "};
    
    do{
        showMenu(); // showMenu() prints out the options menu
        cout << "What would you like to do ? (program doesn't check for characters)" << endl;
        cout << "Option : ";
        cin >> option;
        
        if(option <= 0 || option > 4){
            cout << err << "Please select correct option\n" << endl;
        }else{
            switch(option){
                    
                    // case : balance
                case 1: cout << "Your Account balance : " << balance << "$\n" << endl;
                    break;
                    
                    // case : deposit
                case 2: {
                    if(*number_of_deposits < *transaction_limit){
                        cout << "Deposit Amount : ";
                        cin >> *depositAmount;

                            if(*depositAmount < *min_deposit){
                                    cout << endl;
                                    cout << err << "Minimum deposit amount is " << *min_deposit << "$" << endl;
                                    cout << "Please try again..\n" << endl;
                            }else if(*depositAmount > *max_deposit){
                                    cout << endl;
                                    cout << err << "Not Allowed" << endl;
                                    cout << "Max ATM deposit : " << *max_deposit << endl;
                                    cout << "Our customer service representative will be happy to assit you..\n" << endl;
                            }else{
                                    balance += *depositAmount; // balance updated
                                    if(total_deposited_amount > *acc_limit){
                                        cout << err << "Account can not hold more than 100000$.." << endl;
                                        cout << "No amount deposited.." << endl;
                                        balance -= *depositAmount; // balance corrected
                                        cout << "Your balance : " << balance << "$" << endl;
                                        cout << "You can only add : " << (*acc_limit - balance) << "$\n"<< endl;
                                    }else{
                                        cout << "***Deposit successfull***" << endl;
                                        cout << "Your Account balance : " << balance << "$\n" << endl;
                                        ++*number_of_deposits; // ++ number_of_deposits to check transaction_limit
                                        
                                        deposit_array[*deposit_count]  = *depositAmount; // successful deposit stored
                                        ++*deposit_count; // ++ deposit_count for correct deposit_array index
                                        
                                    }
                            }
                    }else{ // below, transaction limit reached
                        cout << err << "Only " << *transaction_limit << " deposits per program execution..\n" << endl;
                    }
                    break;
                } // case 2 ends
                    
                    // case : withdrawl
                case 3 : {
                    if(*number_of_withdrawls < *transaction_limit){
                        cout << "Withdraw amount : ";
                        cin >> *withdrawAmount;
                        
                        if(*withdrawAmount > balance){
                            cout << err << "Not enough funds.." << endl;
                            cout << "Account balance : " << balance << "$" << endl;
                            cout << "Amount requested : " << *withdrawAmount << "$\n" << endl;
                        }else if(*withdrawAmount > *max_withdraw_limit){
                            cout << err << "Maximum Withdrawl limit : " << *max_withdraw_limit << "$\n" << endl;
                        }else if(*withdrawAmount < *min_withdraw_limit){
                            cout << err << "Minimum withdrawl limit : " << *min_withdraw_limit << "$\n" << endl;
                        }else{
                            cout << "Processing withdrawl....." << endl;
                            cout << "***Withdrawl Successfull***" << endl;
                            cout << "Please collect your cash" << endl;
                            balance -= *withdrawAmount; // balance updated
                            cout << "Account balance : " << balance << "$\n" << endl;
                            ++*number_of_withdrawls; // ++ number_of_withdrawls to check transaction_limit
                            
                            withdraw_array[*withdraw_count] = *withdrawAmount; // withdrawAmount successfully stored
                            ++*withdraw_count; // ++ withdraw_count for correct withdraw_array index
                        }
                        
                    }else{ // below, transaction limit reached
                        cout << err << "Only " << *transaction_limit << " withdrawls per program execution.." << endl;
                    }
                    break;
                } // case 3 ends
                    
                    
                case 4 : {
                    cout << endl;
                    cout << "Transaction Summary : \n" << endl;
                    
                    // below, for loop prints out each deposit transaction, that is stored in deposit_array[]
                    // using transaction_limit as a condition would cause unexpected results, as not everyone reaches it
                    // using number_of_deposits as a condition, it will loop correct number of times
                    for(size_t i {0}; i < *number_of_deposits; ++i){
                        cout << " deposit transaction : " << deposit_array[i] << "$" << endl;
                    }
                    
                    // below, for loop prints out total amount deposited, each deposit is stored in deposit_array[]
                    // using transaction_limit as a condition would cause unexpected results, as not everyone reaches it
                    // using number_of_deposits as a condition, it will loop correct number of times
                    for(size_t i {0}; i < *number_of_deposits; ++i){
                        *deposit_sum += deposit_array[i];
                    }
                    cout << "Total Amount Deposited : " << *deposit_sum << "$" << endl;
                    cout << endl;
                    
                    // below, for loop prints out each withdraw transaction, that is stored in withdraw_array
                    // using transaction_limit as a condition would cause unexpected results, as not everyone reaches it
                    // using withdraw_count as a condition, it would loop correct number of times
                    for(size_t i {0}; i < *withdraw_count; ++i){
                        cout << " withdraw transaction : " << withdraw_array[i] << "$" << endl;
                    }
                    
                    // below, for loop prints out total amount withdrawn, each transaction is stored in withdraw_array[]
                    // using transaction_limit as a condition would cause unexpected results, as not everyone reaches it
                    // using withdraw_count as a condition, it would loop correct number of times
                    for(size_t i {0}; i < *withdraw_count; ++i){
                        *withdraw_sum += withdraw_array[i];
                    }
                    
                    cout << "Total Amount withdrawn : " << *withdraw_sum << "$" << endl;
                    cout << endl;
                    cout << "Account balance : " << balance << "$" << endl;
                    cout << endl;
                    cout << "Total deposit transactions : " << *deposit_count << endl;
                    cout << "Total withdraw transactions : " << *withdraw_count << endl;
                    cout << endl;
                    cout << "Thankyou for choosing Tushar's ATM" << endl;
                    cout << "Have a great day" << endl;
                    
                    break;
                }
            }
        }
    }while(option != 4);
    
    // Returning the dynamic memory
    // case : deposit
    
    delete depositAmount;
    depositAmount = nullptr;
    
    delete number_of_deposits;
    number_of_deposits = nullptr;
    
    delete transaction_limit;
    transaction_limit = nullptr;
    
    delete min_deposit;
    min_deposit = nullptr;
    
    delete max_deposit;
    max_deposit = nullptr;
    
    delete acc_limit;
    acc_limit = nullptr;
    
    delete[] deposit_array;
    deposit_array = nullptr;
    
    delete deposit_count;
    deposit_count = nullptr;
    
    
    // case : withdrawl
    
    delete number_of_withdrawls;
    number_of_withdrawls = nullptr;
    
    delete withdrawAmount;
    withdrawAmount = nullptr;
    
    delete max_withdraw_limit;
    max_withdraw_limit = nullptr;
    
    delete min_withdraw_limit;
    min_withdraw_limit = nullptr;
    
    delete[] withdraw_array;
    withdraw_array = nullptr;
    
    delete withdraw_count;
    withdraw_count = nullptr;
    
    
    // case : exit
    
    delete deposit_sum;
    deposit_sum = nullptr;
    
    delete withdraw_sum;
    withdraw_sum = nullptr;

}
