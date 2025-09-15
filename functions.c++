
#include "functions.h"

const int arr_size = 150;
int myarr[arr_size];

int main () {

    ifstream file;
    file.open("A1input.txt");

    if (!file.good()) {
        cerr << "File cannot be opened!" << endl;
        return 1;
    }

    for (int i = 0; i < arr_size; i++) {
        file >> myarr[i];
    }

    file.close();

    check_arr(myarr);

    

    return 0;
}

int check_arr(int my_arr[]){
    try {
        int user;
        cout << "Enter an index 0-100: ";
        if (!(cin >> user)) {
            throw invalid_argument("Input invalid!");
        }
        if (user < 0 || user >= arr_size) {
            throw out_of_range("Input is out of range");
        }

        cout << "Value at index[" << user << "] -> " << my_arr[user] << endl;
    }
    catch(...) {
        cerr << "Invalid index!" << endl;
    }
    return 0;
}
