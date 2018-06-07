#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int main () {
    stringstream ss;
    ss << "123 ";
    int num;
    ss >> num;
    ss << 1;
    ss << ' ';
    ss << 2;
    ss >> num;


    cout << ss.str() << endl;

// if (ss) {
//     cout << "hi" << endl;
// }
//         ss << "...";
// if (ss)
// {
//     cout << "hi" << endl;
// }
    return 0;
}