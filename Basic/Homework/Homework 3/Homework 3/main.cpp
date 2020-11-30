/*
	Homework #3
	Author: Juan Carbajal
	Email: juancarbajal98@gmail.com
	Course: PIC 10 Fall 2018
	Collaborators: N/A
 
	Honesty Pledge:
 
	I, Juan Carbajal, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
	User inputs: budget for remodeling of living room floor and fence, living room floor dimensions
 
	Output: If the budget covers all the costs then specific measurements and costs are listed. If the budget covers just the living room floor then the back yard size is adjusted. Otherwise the user is told the budget is not enough.
 
	List of known bugs: none
	*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
    // Acquire preliminary remodeling details for a possible reflooring in a living room and fence enclosing the back yard.
    cout << "* Home Remodeling *" << "\n\n" << " Budget = " ;
    double budget = 0;
    cin >> budget ;
    
    cout << "\n" << " Living Room Width (feet) = " ;
    double LR_width = 0;
    cin >> LR_width ;
    
    cout << "\n" << " Living Room Length (feet) = ";
    double LR_length = 0;
    cin >> LR_length ;
    
    // Define the square footage of the living room by the area of the acquired living room dimensions.
    const int LR_sqft = LR_length * LR_width ;
    
    // The fence going around the back yard must enclose an area 3 times larger than the living room, hence we define the back yard footage in this way.
    const double BY_sqft = 3 * LR_sqft ;
    
    // The back yard is square and the fence will go on three sides while the back wall of the house will be used for the fourth side.
    // One side of the fence will  have a length equal to the square root of the back yard square footage.
    // The .5 is added to avoid truncation when converting to integer.
    int fence_length = 3 * (sqrt (BY_sqft)) + .5 ;
    
    // Total cost is calculated with flooring at $3.79 per square foot and fencing at $18 per foot.
    const double flooring_pricing = 3.79 ;
    const int fence_pricing = 18 ;
    double LR_cost = flooring_pricing * LR_sqft ;
    double BY_cost = fence_pricing * fence_length ;
    double total_cost = LR_cost + BY_cost ;
    
    // These two variables are in regards to the case if a user can afford their flooring done but cannot afford all the desired fencing. In that case the user will be recommended smaller amounts of fencing that will allow the user to remain within budget.
    int fence_amount = 0 ;
    int BY_size = 0 ;
    
    // If the total cost is within the budget then some specifications are provided; the amount of flooring, fencing, and the total cost.
    if ( budget > LR_cost && budget >= total_cost) {
        cout << "\n* * * * * * * * * * * * * * * * * * *" << "\n" ;
        cout << "* REMODELING PROJECT SPECIFICATIONS *" ;
        cout << "\n* * * * * * * * * * * * * * * * * * *" << "\n\n" ;
        cout << "LIVING ROOM = " << LR_sqft << " square feet of flooring needed." << "\n" ;
        cout << "BACK YARD = " << fence_length << " feet of fence needed." ;
        cout << "\nTOTAL COST = $" ;
        cout << fixed <<setprecision(2) << total_cost << "\n" ;
    }
    
    // When the budget covers the flooring but not all the fencing then the total cost is adjusted with as many 5 foot increments of fencing that the budget can afford.
    else if ( budget > LR_cost && budget < total_cost)
    {
        cout << "\n* * * * * * * * * * * * * * * * * * * * * * * * * *" << "\n" ;
        cout << "* NOT ENOUGH BUDGET ... ADJUSTING BACK YARD SIZE. *" ;
        cout << "\n* * * * * * * * * * * * * * * * * * * * * * * * * *" << "\n\n" ;
        
        // The amount of flooring is listed.
        cout << "LIVING ROOM = " << LR_sqft << " square feet of flooring needed." << "\n" << endl;
        
        // Total cost and affordable fencing are listed in 5 foot increments.
        cout << setw(15) << "TOTAL COST" << setw(16) << "FENCE AMOUNT" << setw(17) << "BACK YARD SIZE" << "\n" << endl ;
        for (total_cost = LR_cost, fence_amount = 0,  BY_size = 0 ; budget > total_cost ; total_cost = total_cost + 270 , fence_amount = fence_amount + 15 , BY_size = BY_size + 5)
            cout << setw(8) << "$ " << fixed << setprecision(2) << setw(7) << total_cost << setw(14) << fence_amount << "'" << setw(14) << BY_size<< "' x " << BY_size << "' " << endl;
        
    }
    
    // If the budget is not enough for flooring alone.
    else {
        cout << "\n* * * * * * * * * * * * * * * * * * *" << "\n" ;
        cout << "* SORRY, YOUR BUDGET IS NOT ENOUGH. *" ;
        cout << "\n* * * * * * * * * * * * * * * * * * *" << "\n\n" ;
    }
    
    cout << "\n" ;

    return 0;
}
