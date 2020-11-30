
/*
 Homework #2
 Author: Juan Carbajal
 Email: juancarbajal98@gmail.com
 Course: PIC 10 Fall 2018
 Collaborators: N/A
 
 Honesty Pledge:
 
 I, Juan Carbajal, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
 User inputs: full name, birth year, birth month, birth day, telephone number, email, desired hourly wage 
 
 Output: Two formatted emails utilizing the gathered user information
 
 List of known bugs: none
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    
    cout << "===== PLEASE COMPLETE THE FOLLOWING FORM  =====\n" << endl;
    
    cout << "What is your full name (First Last) ? ";
    
    
    string first_name ;
    string last_name ;
    
    
    //Gather the user's name. Having the user's name decomposed as such will prove to be beneficial throughout the code.
    cin >> first_name >> last_name ;
    
    //Gather the user's birth year.
    cout << "\nWhat year were you born? " ;
    int year_of_birth ;
    cin >> year_of_birth;
    
    //Gather the user's birth month.
    cout << "\nWhat is your birth month? " ;
    string birth_month ;
    cin >> birth_month;
    
    //Gather the user's day of month in which they were born.
    cout << "\nWhat day of the month were you born in? ";
    int birth_day ;
    cin >> birth_day ;
    
    //Gather the user's phone number. The two getline commands are intentional: the first one should be understood as a buffer for space and the second a buffer for the actual phone number.
    cout << "\nWhat is your telephone number? " ;
    string phone_number;
    getline(cin,phone_number); getline(cin,phone_number) ;
    
    //Gather the user's email.
    cout << "\nWhat is your email? " ;
    string email ;
    cin >> email ;
   
    //Gather the user's desired hourly wage. Although the typical input will be an integer, we declare the wage to be a double to be safe.
    cout << "\nWrite your desired hourly wage = $ ";
    double hourly_wage;
    cin >> hourly_wage ;
    
    //Create a string to indicate breaks between major inputs/outputs.
    string line_break = "\n* * * * * * * * * * * * * * * * * * * * " ;
    cout << line_break << endl;
    
    
    //Beginning of output. The beginning of 1 of 2 emails.
    cout << "TO ALL CURRENT EMPLOYEES\n\n" ;
    
    //Greeting the user as a new employee.
    string full_name= first_name + " " + last_name ;
    cout << "\nPlease join me in welcoming " << full_name << " to our company!\n\n";
    
    //We indent forward 15 spaces to list name,initials, and email in a formatted way
    cout << setw(15) << "Name: " << full_name << endl;
    
    //Here below, the "_p" could be understood as containing periods. Both of these strings will be utilized throughout the code
    string initials= first_name.substr(0,1) + last_name.substr(0,1) ;
    string initials_p= first_name.substr(0,1) + "." + last_name.substr(0,1) + "." ;
    cout << setw(15) << "Initials: " << initials_p << endl;
    
    cout << setw(15) <<"Email: " << email << endl;
    
    //We consider it to be 2017. Defining next year as a constant will be useful for specifying the employees age next year on their birthday.
    const int next_year = 2018 ;
    int next_year_age = next_year - year_of_birth ;
    

    cout << "\nBecause " << initials_p << " will be " << next_year_age << " years young, we will celebrate by going out to lunch next year during " << initials_p << "'s birthday on " << birth_month << " " << birth_day << "." << endl;
    
    cout << line_break ;
    
    //Beginning of email 2. This email is just to the employer. Using the gathered input information we output new employee information for the employee's use.
    cout<< "\nTO: " << email << endl;
    
    cout << "\n\nDear " << first_name << "," << endl;
    
    cout << "\nPlease review your new employee information:\n" << endl;
    
    cout << setw(15) << "Name: " << full_name << endl;
    
    //A unique ID is constructed with the use of the employee's initials followed by the last 4 digits of their specified phone number.
    string ID= initials + phone_number.substr(phone_number.length()-4) ;
    cout << setw(15) << "ID #: " << ID << endl;
    
    cout << setw(15) << "DOB: " << birth_month << " " << birth_day << " " << year_of_birth << endl ;
    
    cout << setw(15) << "Salary: " << "$ " ;
    
    //Salary is calculated by multiplying total work hours in a year by the employee's desired outcome. We implement boundaries for said salary: no less than $17,000, no more than $62,500. It is given that there are 40 hours in a work week and 52 weeks in the year. The constant "work_hours" is calculated by multiplying 40 * 52 = 2080.
    const int work_hours = 2080 ;
    int salary = hourly_wage * work_hours ;
    
    
    const double lowest_salary = 17000 ;
    const double highest_salary = 62500 ;
    
    int value = fmin(salary, highest_salary);
    value = fmax(value,lowest_salary) ;
    
    int lhs_salary = (value)/1000 ;
    int rhs_salary = value % 1000 ;
    
    
    //It is guaranteed here that the ouput salary will always remain within the salary bounds. Any desired hourly wages that exceed the boundaries - either too low or too high - are automatically set to the nearest boundary value.
    
    if (rhs_salary < 100) {
        cout << lhs_salary << "," << setfill ('0') << setw(3) << rhs_salary ;
    }
    else {
        cout << lhs_salary << "," << rhs_salary ;}
    
    cout << "\n" << "\nWelcome to our company!" << endl ;
    
    
    return 0;
}

