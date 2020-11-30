//
//  main.cpp
//  Homework 7
//
//  Created by Juan Carbajal on 11/24/18.
//  Copyright © 2018 Juan Carbajal. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Customer
{
public:
    // Constructs a customer with a total balance of zero, credit limit of 1500, and zero number of purchases
    Customer();
    
    Customer(string n);
    
    /* Mutation function that updates the value of Customer's total balance and number of purchases after a successful purchase
    @Param val: the dollar amount of the purchase the customer would like to make
    @return true if the total balance will remain under the credit limit with the addition of purchase amount
    */
    bool add_purchase(double val);
    // Gets the customer name
    string get_name() const;
    // Gives an address to object in Customer class
    // Initialized with default constructor
    string address() const;
    //Gets the customer's credit limit
    double get_credit_limit() const;
    // Gets the customer's total balance
    double get_total_balance() const;
    // Gets the customer's total number of succesful purchases
    int get_num_purchases() const;
    
private:
    string name;
    double total_balance;
    double credit_limit;
    int number_of_purchases;
};


Customer::Customer()
{
    total_balance = 0;
    credit_limit = 1500;
    number_of_purchases = 0;
}

//comments like a nonmember function with parameters. however no return
Customer::Customer(string n)
{
    total_balance = 0;
    credit_limit = 1500;
    number_of_purchases = 0;
    name = n;
}

bool Customer:: add_purchase(double val)
{
    bool set = false;
    
    if (val + total_balance <= credit_limit) {
        set = true;
        total_balance = total_balance + val;
        number_of_purchases = number_of_purchases + 1 ;
    }
    
    return set;
}

string Customer:: get_name() const
{return name;}

double Customer:: get_credit_limit() const
{return credit_limit;}


double Customer:: get_total_balance() const
{return total_balance;}

int Customer:: get_num_purchases() const
{return number_of_purchases;}


int main()
{
    //construct customer object
    Customer c;

    cout << "Customer: ";
    string name;
    getline(cin, name);
    
    c = Customer(name);

    cout << "Credit Limit: " << c.get_credit_limit();
    cout << endl;
   
    bool more = true ;
    while (more)
    {
        cout << "Purchase value (in $): ";
        double val;
        cin >> val;
        if (c.add_purchase(val) == true) {cout << "Purchase Successful.";}
        else {
            cout << "Not enough credit limit. Purchase cannot be completed.";
        }
        
        cout << "\nDo you want to purchase another item (y/n)? ";
        string answer ;
        getline(cin, answer);
        getline(cin, answer);
        if (answer != "y") {more = false;}
    }
    
    cout << "The total of " << c.get_num_purchases() << " purchase(s) is $" << c.get_total_balance() << endl;
    
    return 0;
}
