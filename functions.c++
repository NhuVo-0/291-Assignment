
#include "functions.h" //header file for function declarations

const int arr_size = 150; //creating an array w/ size bigger than intended
int myarr[arr_size] = {0}; //initialize the array with all values = 0

int main () {

    ifstream file; //in file stream the input file
    file.open("A1input.txt"); //open the file for reading

    if (!file.good()) { //checking if opening the file have any issue if so output error message
        cerr << "File cannot be opened!" << endl;
        return 1;
    }

    for (int i = 0; i < 100; i++) { //load the array with values from file 
        file >> myarr[i];
    }

    file.close(); //close the file after reading

    check_arr(myarr); //call the function for checking values
    mod_arr(myarr); // call function to modify a index's value
    add_arr(myarr); //call function to add to the end of the array (100)
    remove_arr(myarr); // call function to remove value at index

    

    return 0;
}

int check_arr(int my_arr[]){ //function definition
    try { //try & catch for user input's validation  
        int user; //initialize a variable for user input
        cout << endl;
        cout << "Enter value: "; //terminal message
        if (!(cin >> user)) { //user input's validation, if not valid (i.e not numerical) then throw a error
            throw invalid_argument("Input invalid!");
        }

        bool index = false; //true/false holder for if the value is found in the array or not
        for (int i = 0; i < 100; i++) { //for loop to run through the 100 values from file
            if (my_arr[i] == user) { //check if value at index is == to user input
                cout << "Value " << user << " -> [" << i << "]." << endl;  //output msg
                index = true; //set holder = true to stop the search
            }
            
        }

        if (!index) { //check if the value is not in the array or not
            cout << "Value does not exist." << endl;
        }

    }
    catch(const exception& e) { //catch block to output the error msg and what error it is (e.what())
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

int mod_arr(int my_arr[]) { //function definition
    try { //try & catch block 
        int user_input; //user input variable
        cout << endl;
        cout << "Enter an index to change the value at: "; //output message
        cin >> user_input; //get user inpyt
        cout << "[" << user_input << "]" << " -> " << my_arr[user_input] << endl; //output the index and value 

        if (cin.fail() || user_input < 0 || user_input >= arr_size) { //check if the index is valid and within the array's size
            throw invalid_argument("Invalid Index!");
        }

        int input_val; //get new value
        cout << "Enter new value: "; //output msg 
        cin >> input_val;
        cout << endl; 

        if (cin.fail()) { //check if the value is numerical or not
            throw out_of_range("Input Value");
        }
        cout << "Old value: " << my_arr[user_input] << endl; //output the old value 
        my_arr[user_input] = input_val; //change the old value by assigning the index with the user input value
        cout << "Value at index[" << user_input << "] changed -> " << input_val << endl; //output msg
    }
    catch(const exception& e) { //catch block error msg and what error
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

int add_arr(int myarr[]){ //function definition
    try{ //try and catch block for user validation
        cout << endl;
        cout << "Add integer at the end: "; //output msg
        int user;
        cin >> user; //get user input value to add

        if (cin.fail()) { //check if the value is numerical or not
            throw invalid_argument("Invalid Value!");
        }

        bool add = false; //true/false holder for if the value was added or not

        for (int i = 100; i < arr_size; i++) { //for loop to run starting after 100th index (end of array supposedly)
            if (myarr[i] == 0) { //checking if the spot after 100 are empty (0) in this case = empty
                myarr[i] = user; //assigning that index w/  the user input 
                cout << "Added the value: " << user << " at -> index[" << i << "]." << endl; //output msg
                add = true; //set holder = true for adding successfully
                break; //break out after value was added
            }
        }

        if ( !add) { //check if the value couldn't be added because of full array
            cout << "Full spot in array." << endl;

        }
    }
    catch(const exception& e) { //catch block for exceptions and error msg
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

int remove_arr(int my_arr[]){ //function definition
    try{ // try and catch block
        int value;
        cout << endl;
        cout << "Enter a value to remove: "; //output msg
        cin >> value; //get value
        cout << endl;
        if (cin.fail()) { //check if the value is numerical or not
            throw invalid_argument("Invalid value.");
        }

        for (int i = 0; i < arr_size; i++) { //for loop to run through the array
            if ( my_arr[i] == value) { //check if the index's value is == user input
                for ( int j = i; j < 149; j++) { // run another for loop to shift everything one to the left (removing)
                    my_arr[j] = my_arr[j + 1]; //shifting 1 to the left
                }
                cout << "Value: " << value << " was removed from -> index[" << i << "]." << endl; //output msg
                cout << endl << "Final array: " << endl; //output final array after changes
                for ( int k = 0; k < arr_size; k++){ //for loop to output values without the empties ones (0)
                    if ( my_arr[k] != 0){
                    cout << my_arr[k] << " ";
                    }
                }
                return 0;
            }
        }

        cout << "Invalid Value" << endl; // if the value is invalid then output

    }

    catch(const exception& e) { //catch block for exceptions and what the error is
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
