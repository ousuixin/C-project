#include <iostream>
#include "system.h"
using namespace std;

int staff_num = 100;
int teacher_num = 200;
int stu_num = 300;
string staff_prove;
string teacher_prove;
string stu_prove;
class system sysu;

int main () {
    sysu.write_in();

    cout << "============================================================" << endl;
    cout << "==             Welcome To The Elective System             ==" << endl;
    cout << "============================================================" << endl;

    string s1;

    while (1) {
        cout << "## what do you want to do ? You can:" << endl;
        sysu.print_func();
        cout << "## Please enter the numbers to perform the corresponding operations." << endl;
        cout << "## You can input Q to go back to this manu at any time." << endl;
        string s = input_check(1);
        if (s == "Q") {
            cout << "## Go back to the menu!" << endl;
            continue;
        } else if (s == "0") {
            cout << "============================================================" << endl;
            cout << "==                       Good bye!                        ==" << endl;
            cout << "============================================================" << endl;
            return 0;
        } else if (s == "1") {
            s1 = sysu.login();
            if (s1 == "Q") {
                cout << "## Go back to the menu!" << endl;
                continue;
            }
            break;
        } else if (s == "2") {
            s1 = sysu.register0();//rigister是关键字！
            if (s1 == "Q") {
                cout << "## Go back to the menu!" << endl;
                continue;
            }
            break;
        }
    }

    person& temp = sysu.load(s1);
    //载入该用户信息


    cout << "## What do you want to do ?" << endl;
    temp.print_func();
    cout << "## Please enter the numbers to perform the corresponding operations." << endl;
    cout << "## You can input Q to go back to the menu at anywhere."<< endl;

    while (temp.select_func()) {
        cout << "## What else do you want to do?" << endl;
        temp.print_func();
        cout << "## Please enter the numbers to perform the corresponding operations." << endl;
        cout << "## You can input Q to go back to the menu at anywhere." << endl;
    }

    cout << "============================================================" << endl;
    cout << "==                       Good bye!                        ==" << endl;
    cout << "============================================================" << endl;

    sysu.place_in_file();
    return 0;
}