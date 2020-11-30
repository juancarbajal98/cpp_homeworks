/*
	Homework #4
	Author: Juan Carbajal
	Email: juancarbajal98@gmail.com
	Course: PIC 10 Fall 2018
	Collaborators: N/A
 
	Honesty Pledge:
 
	I, Juan Carbajal, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
	User inputs: Class grades: homework score, midterm score, final exam score
 
	Output: All given grades as well as the final overall numeric grade and letter grade with respect to grading scheme.
 
	List of known bugs: none
	*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string> 
#include <iomanip>
#include <cassert>

using namespace std ;

//We begin to consider the two grading schemes for the class.
//Scheme 1 says the midterm will be 30% and the final will be 40% of the final grade. Scheme 2 says the final will replace the midterm, making the final worth 70%. In both cases homework is 30%. Later on we will decide when to use scheme 1 vs scheme 2 or vice versa.
double const weight1_m = 0.3 ;
double const weight1_f = 0.4 ;
double const weight2 = 0.7 ;
double const hw_weight = 0.3 ;

/* Computes the numeric value of the course grade
 @Param hmw_grade: homework grade
 @Param midterm_grade: midterm exam grade
 @Param final_grade: final exam grade
 ...
 @return the overall course grade
 */
//if statements help guarantee user will recieve higher grade of the two schemes if there is a difference between the two. If there is no difference then both schemes yield the same grade.
double mygrade (double hmw_grade, double midterm_grade, double final_grade) {
    if (midterm_grade > final_grade) return hw_weight * hmw_grade + weight1_m * midterm_grade + weight1_f * final_grade ;
    if (final_grade >= midterm_grade) return weight2 * final_grade + hmw_grade * hw_weight ;
    
    return 0;
    }

string letter_grade (double n)
{
    /* Turns a number grade into a letter grade
     @param n a double between 0 and 100
     @return the letter grade with respect to grading scale
     */
    if (n < 61) return "F" ;
    if (n >= 61 && n < 63) return "D-" ;
    if (n >= 63 && n < 67) return "D" ;
    if (n >= 67 && n < 70) return "D+";
    if (n >= 70 && n < 73) return "C-" ;
    if (n >= 73 && n < 77) return "C" ;
    if (n >= 77 && n < 80) return "C+" ;
    if (n >= 80 && n < 83) return "B-" ;
    if (n >= 83 && n < 87) return "B" ;
    if (n >= 87 && n < 90) return "B+" ;
    if (n >= 90 && n < 93) return "A-" ;
    if (n >= 93 && n <= 100) return "A" ;
    return "" ;
}


int main ()
{
    cout << "PIC 10A GRADE CALCULATOR" << "\n\n" ;
    
    //Define variables homework grade, midterm grade, and final exam grade
    double hmw_grade = 0;
    double midterm_grade = 0;
    double final_grade = 0;
    
    //Gather the user's grades. If statement is utilized to restrict all grade inputs to be between 0 and 100
    cout << "Homework grade (%)  = " ;
    cin >> hmw_grade ;
    if (hmw_grade > 100 || hmw_grade <0) {
        cout << "Invalid input; grade must be no more than 100 and no less than 0." << "\n";
        return 0;}
    
    cout << "\n" << "Midterm grade (%)  = " ;
    cin >> midterm_grade ;
    if (midterm_grade > 100 || midterm_grade <0) { cout << "Invalid input; grade must be no more than 100 and no less than 0." << "\n";
        return 0; }
    
    cout << "\n" << "Final Exam grade (%)  = " ;
    cin >> final_grade ;
        if (final_grade > 100 || final_grade <0) {
            cout << "Invalid input; grade must be no more than 100 and no less than 0." << "\n";
            return 0;}
    
    
    //Beginning of output.
    cout << "\n\n\n" << "CATEGORY" << setw(15) << "GRADE" << "\n\n" ;
    
    cout << "HOMEWORK" << fixed
    << setprecision(2) << setw(15) << hmw_grade << endl;
    cout << "MIDTERM" << setw(16) << midterm_grade << endl;
    cout << "FINAL" << setw(18) << final_grade << endl;
    cout << "OVERALL GRADE" << setw(10);
    

    //Call the overall_grade function to compute the final numeric grade.
    double overall_grade = mygrade (hmw_grade, midterm_grade, final_grade);
    
    cout << overall_grade << endl ;
    
    //Utilizes string function letter_grade to convert the numeric grade into a letter grade.
    cout << "CLASS GRADE" << setw(10) << letter_grade(overall_grade) << endl;
    
    
    return 0;
    
}
