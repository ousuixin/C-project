#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <utility>
#include <cmath>
#include <map>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "polynomial.h"
#include "func.h"
using namespace std;
//this vector is used for store all the polynomials;
int count = 0;
map<string, polynomial> m0;
polynomial temp1;
polynomial temp2;


int main () {
	// //this function is used to write the data in file to the program running now;
	// write_in();
    m0.insert(make_pair("TEMP1", temp1));
    m0.insert(make_pair("TEMP2", temp2));

	//then we can start;
	cout << "============================================================" << endl;
    cout << "==      Welcome To The Compute Polynomial Calculator!     ==" << endl;
    cout << "==                 Hope You Can Enjoy It!                 ==" << endl;
    cout << "============================================================" << endl;

    //ask the user to choose the function
    cout << "~~ What do you want to do ? In this calculator, you can :   " << endl;
    print_function();
    cout << "~~ Please enter the numbers to perform the corresponding operations." << endl;
    cout << "~~ And you can return to the menu any time by entering 'Q'." << endl;

    while (choose_function()) {
        cout << "~~ What else do you want to do?" << endl;
        print_function();
        cout << "~~ Please enter the numbers to perform the corresponding operations." << endl;
        cout << "~~ And you can return to the menu any time by entering 'Q'." << endl;
    }

    cout << "============================================================" << endl;
    cout << "==                         Good Bye!                      ==" << endl;
    cout << "============================================================" << endl;
	// //this function is used to place the data on file;
	// place_in_file();
	return 0;
}