#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//integer function to get input from user and check for
//that value and return the first instance of that value's index (with try/catch validation of user input)
int check_arr(int my_arr[]);
// take an integer array

//integer function to modify the index's value given a index and new value from user (also with user input validation)
int mod_arr(int my_arr[]);

//integer function to add a value to the end of the array (also with validation to user input)
int add_arr(int my_arr[]);

//integer function to remove a value given an index from user (also have validation for user input)
int remove_arr(int my_arr[]);