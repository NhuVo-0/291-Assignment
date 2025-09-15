
#include "functions.h" //header file for function declarations

const int arr_size = 150;
int myarr[arr_size] = {0};

int main () {

    ifstream file;
    file.open("A1input.txt");

    if (!file.good()) {
        cerr << "File cannot be opened!" << endl;
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        file >> myarr[i];
    }

    file.close();

    check_arr(myarr);
    mod_arr(myarr);
    add_arr(myarr);
    remove_arr(myarr);

    

    return 0;
}

int check_arr(int my_arr[]){
    try {
        int user;
        cout << endl;
        cout << "Enter value: ";
        if (!(cin >> user)) {
            throw invalid_argument("Input invalid!");
        }

        bool index = false;
        for (int i = 0; i < 100; i++) {
            if (my_arr[i] == user) {
                cout << "Value " << user << " -> [" << i << "]." << endl; 
                index = true;
            }
            
        }

        if (!index) {
            cout << "Value does not exist." << endl;
        }

    }
    catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

int mod_arr(int my_arr[]) {
    try {
        int user_input;
        cout << endl;
        cout << "Enter an index to change the value at: ";
        cin >> user_input;
        cout << "[" << user_input << "]" << " -> " << my_arr[user_input] << endl;

        if (cin.fail() || user_input < 0 || user_input >= arr_size) {
            throw invalid_argument("Invalid Index!");
        }

        int input_val;
        cout << "Enter new value: ";
        cin >> input_val;
        cout << endl; 

        if (cin.fail()) {
            throw out_of_range("Input Value");
        }
        cout << "Old value: " << my_arr[user_input] << endl;
        my_arr[user_input] = input_val;
        cout << "Value at index[" << user_input << "] changed -> " << input_val << endl;
    }
    catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

int add_arr(int myarr[]){
    try{
        cout << endl;
        cout << "Add integer at the end: ";
        int user;
        cin >> user;

        if (cin.fail()) {
            throw invalid_argument("Invalid Value!");
        }

        bool add = false;

        for (int i = 100; i < arr_size; i++) {
            if (myarr[i] == 0) {
                myarr[i] = user;
                cout << "Added the value: " << user << " at -> index[" << i << "]." << endl;
                add = true;
                break;
            }
        }

        if ( !add) {
            cout << "Full spot in array." << endl;

        }
    }
    catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

int remove_arr(int my_arr[]){
    try{
        int value;
        cout << endl;
        cout << "Enter a value to remove: ";
        cin >> value;
        cout << endl;
        if (cin.fail()) {
            throw invalid_argument("Invalid value.");
        }

        for (int i = 0; i < arr_size; i++) {
            if ( my_arr[i] == value) {
                for ( int j = i; j < 149; j++) {
                    my_arr[j] = my_arr[j + 1];
                }
                cout << "Value: " << value << " was removed from -> index[" << i << "]." << endl;
                cout << endl << "Final array: " << endl;
                for ( int k = 0; k < arr_size; k++){
                    if ( my_arr[k] != 0){
                    cout << my_arr[k] << " ";
                    }
                }
                return 0;
            }
        }

        cout << "Invalid Value" << endl;

    }

    catch(const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
