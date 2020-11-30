/*
 Homework #8
 Author: Juan Carbajal
 Email: juancarbajal98@gmail.com
 Course: PIC 10 Fall 2018
 Collaborators: N/A
 
 Honesty Pledge:
 
 I, Juan Carbajal, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
 User inputs: Name of file which data is read from
 
 Output: No print to console but a new file NewData is created with same data as user-inputted file
 
 List of known bugs: none
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main() {
    
    // Gather name of file from which data will be read from
    cout << "Enter the name of the file: " ;
    string file_name;
    getline(cin, file_name);
    
    // Create file variable to associate with disk file
    ifstream input_data;
    
    // File is opened
    input_data.open(file_name);
    
        // Check if stream entered fail state
        if (input_data.fail()) {
            cout << "Failed to open file." << endl;
            return 1;
        }
    
        // Define vector that will hold all text on file
        vector<string> new_data;
        string temp;
    
        // while the text from the user inputted file remains of type string then it will be placed into the new_data vector line by line
        while (getline(input_data,temp)) {
            new_data.push_back(temp);
        }
    // Close file
    input_data.close();
    
    
    // Create ofstream object to write to a new file
    ofstream output_data;
    
    // Opens (or creates) NewData file
    output_data.open("NewData.txt");
    
        // Check if stream entered fail stat
        if (output_data.fail()) {
            cout << "Failed to open file." << endl;
            return 1;
        }
    
    // for loop that sends in every line of text stored in the vector from the old file into the new file
    int i ;
    for(i = 0; i < new_data.size(); i += 1){output_data << new_data[i] << endl;}
    
    // Close loop
    output_data.close();
   
    
    return 0;
    
}
