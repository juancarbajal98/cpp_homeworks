/*
Homework #5
Author: Juan Carbajal
Email: juancarbajal98@gmail.com
Course: PIC 10 Fall 2018
Collaborators: N/A

Honesty Pledge:

I, Juan Carbajal, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.

User inputs: Initial Population, Birth Rate, Death Rate, and the amount of years the user is interested in studying.

Output: Two approximations of population growth (or decrease); one in a balanced environment where there are no additional outside factors in our approximation, and one where a random enviromental effect will add or subtract people from the population. There is also a probability of the population going extinct given the certain conditions.

List of known bugs: none
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

/* Calculates the growth rate of the population
 @Param birth_rate: rate at which people in this population are birthed
 @Param death_rate: rate at which people in this population die
 @return the difference of the birth rate and death rate
*/
double growth_rate (double birth_rate , double death_rate ) {
    return birth_rate - death_rate ;
    return 0;
}

/* Calculates an approximation of the population at the end of a certain number of years
 @Param growth_rate: rate of growth (or decrease) in population
 @Param environmental_effect: random effect due to environmental causes, bounded between -1 and 1.
 @Param initial_population: initial population, bounded below by 2
 @Param years: time over which population will be approximated
 @return an approximation of the population of the end of the specified years; either with or without environmental effect
*/
int population (double growth_rate, double environmental_effect, int initial_population, int years) {
    if (environmental_effect == 0) return initial_population * ( pow( 1+ growth_rate, years)) ;
    else return (1 + growth_rate - environmental_effect) * initial_population ;
    return 0;
}

/*
 @param growth_rate: rate of growth (or decrease) in population
 @return phrase informing the possibility of extinction with given conditions
 */
void extinction (double growth_rate) {
    if (growth_rate < 0) {cout << "Extinction is possible." ;}
}

// Initialize global variable extinction_counter
int extinction_counter = 0 ;

/*
 @param environmental_population_e: an approximation of the population with nonzero environment effect
 @return increment extinction_counter for each possibility of extinction
 */
void extinction_probabilty (int environmental_population) {
    if (environmental_population == 0 || environmental_population < 0){
        extinction_counter += 1 ;}
    }
    
int main ()
{
    // Gather initial population from the user.
    int initial_population = 2;
    cout << "Initial Population = " ;
    cin >> initial_population ;
    
    
    // Restrict innput for initial population to be bounded below by 2.
    while (initial_population < 2) {
        cout << "Invalid Entry: Please enter an integer greater than 1." << "\n" << "Initial Population = ";
        cin >> initial_population ;
    }
    
    // Gather the birth & death rate from the user
    double birth_rate = 0;
    cout << "Birth Rate = ";
    cin >> birth_rate ;
    double death_rate = 0;
    cout << "Death Rate = ";
    cin >> death_rate ;
    
    
    // Call growth_rate function using specified user values for birth and death rate
    double growth_rate_r = growth_rate(birth_rate, death_rate) ;
    
    
    // Gather the amount of years the user is interested in studying the population
    int years = 0;
    cout << "Years = ";
    cin >> years ;
    cout << "\n\n" ;
    
    
    // Beginning of output
    cout << "MODEL" << setw(25) << "YEARS" << setw(17) << "POPULATION" << setw(16) << "EXTINTCTION" << endl;
    
    // Deterministic refers to the population model in which there is no environmental effect
    // Call the population function with no additional outside factors. In other words the environmental effect is set to zero.
    const double deterministic_const = 0;
    int deterministic_population = population(growth_rate_r, deterministic_const, initial_population, years) ;
    cout << "DETERMINISTIC" << setw(17) << years << setw(17) << deterministic_population << setw(16) << "POSSIBLE" << endl;
    
    // Output user-inputted years
    cout << "ENVIRONMENTAL" << setw(17) << years ;
    
    // Initialize environmental_population
    int environmental_population = 0;
    
    // Sets the seed of rand()
    srand(time(0));
   
    // Define the bounds of the enviromental effect as constants
    const int bottom_E = -1;
    const int top_E = 1;
    
   // Calculation of environmental model. population function is now called with the environmental effect(E) equal to a random double between -1 and 1. With E no longer being zero, we must compute all the years from beginning to second to last year before we can compute the final approximation corresponding to the final year. E changes from year to year as to satisfy its randomness.
   // i serves as counter to assure the final return value of the population function corresponds to the final year
    for (int i = 0; i < years ; i += 1) {
        double E = bottom_E + ( top_E - bottom_E ) * ( rand() * 1.0 / RAND_MAX ) ;
        environmental_population = population(growth_rate_r, E, initial_population, years) ;
        initial_population = environmental_population ;
    }
    
    
   // Serves to assure that population will not be negative
    if (environmental_population < 0) {
        cout << setw(17) << 0;}
    else {cout << setw(17) << environmental_population;}
    
    
    // Defined to guarantee user-input initial value is constant for every time the nested for loop executes while solving for extinction probability
    const int initial_population_e = initial_population;
    
    //Acquire 100 values for enviromental population where each value will be passed through extinction_probability
    for (int x =0; x < 100; x += 1) {
            
        for (int i = 0; i < years; i += 1) {
                
            double E = bottom_E + ( top_E - bottom_E ) * ( rand() * 1.0 / RAND_MAX ) ;
            
            environmental_population = population(growth_rate_r, E, initial_population_e, years) ;
            initial_population = environmental_population;
            
            //if statement gurantees we exit this nested loop as soon as population goes extinct
            if (environmental_population <= 0) {
                i = years - 1;}
        }
        extinction_probabilty(environmental_population) ;
    }
    
    //dummy variable to get a probability from extinction_counter 
    const double a = 100.0;
    
    //extinction probability
    cout << setw(12) << "PROB = " << fixed << setprecision(2) << extinction_counter / a << endl;
    
    return 0;
}
