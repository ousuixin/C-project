#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "system.h"
using namespace std;

void student::print_func () {
    cout << "#####" << "#####" << "####################" << "#####" << "#####" << "####################" << endl;
    cout << "##   " << "     " << "(0).Exit The System           " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(1).Change Password           " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(2).Change Username           " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(3).List All Class            " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(4).Find Class By Name        " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(5).Find Class By Teacher     " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(6).Shield Conflict Class     " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(7).Shield Full_member Class  " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(8).Select Class              " << "     " << "     " << "     " << "   ##" << endl; 
    cout << "##   " << "     " << "(9).Delete Class              " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(10).List My Class            " << "     " << "     " << "     " << "   ##" << endl;
    cout << "#####" << "#####" << "####################" << "#####" << "#####" << "####################" << endl;
};

int student::select_func() {
    string s = input_check(2);
    if (s == "Q") {
        cout << "## Go back to the menu." << endl;
        return 1;
    } else if (s == "0") {
        return 0;
    } else if (s == "1") {
        cout << "## Please input the new password:" << endl;
        string s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Go back to the menu." << endl;
            return 1;
        }
        cout << "Set password successfully! The new password is " << s1 << " now!" << endl;
        change_password(s1);
    } else if (s == "2") {
        cout << "## Please input the new username:" << endl;
        string s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Go back to the menu." << endl;
            return 1;
        } 
        cout << "Set username successfully! The new username is " << s1 << " now!" << endl;
        change_username(s1);
    } else if (s == "3") {
        list_all();
    } else if (s == "4") {
        cout << "## Please input the class you want to find:" << endl;
        string s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Go back to the menu." << endl;
            return 1;
        } 
        cout << "## The information is as following:" << endl;
        find_by_classname(s1);
    } else if (s == "5") {
        cout << "## Please input the teacher's name of the class you want to find:" << endl;
        string s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Go back to the menu." << endl;
            return 1;
        } 
        cout << "## The information is as following:" << endl;
        find_by_tchname(s1);
    } else if (s == "6") {
        cout << "## The classes time conflict with yours are shield now:" << endl;
        shield_conflict();
    } else if (s == "7") {
        cout << "## The classes which have no vacancy are shield now:" << endl;
        shield_full();
    } else if (s == "8") {
        int ret = 0;
        cout << "## Please input the name of the class you want to select:" << endl;
        string s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Go back to the menu." << endl;
            return 1;
        } 
        for (auto a = myclass.begin(); a != myclass.end(); a++) {
            if (a->name == s1) {
                cout << "## Operation Failed ---- You have selected this class before." << endl;
                return 1;
            }
        }
        for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
            if (a->name == s1) {
                if (is_conflict(a->time, myclass)) {                                            
                    cout << "## Operation Failed ---- The class is conflict with the classes you have now!" << endl;
                    return 1;
                } else if (a->max_capacity == a->stu_num) {
                    cout << "## Operation Failed ---- The class is all seats taken!"  << endl;
                    return 1;
                }
                ret = 1;
                Class temp0 = *a;
                myclass.push_back(temp0);
                a->stu_num++;
                select_class(s1);
                cout << "## Select class successfully!" << endl;
                break;
            }
        }
        if (!ret) {
            cout << "## Operation Failed ---- There is no such class!" << endl;
        }
    } else if (s == "9") {
        int ret = 0;
        cout << "## Please input the name of the class you want to delete:" << endl;
        string s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Go back to the menu." << endl;
            return 1;
        } 
        for (auto a = myclass.begin(); a != myclass.end(); a++) {
            if (a->name == s1) {
                myclass.erase(a);
                cout << "## Delete class successfully!" << endl;
                ret = 1;
                break;
            }
        }
        if (!ret) {
            cout << "## Operation Failed ---- You don't have such class before!" << endl;
        } else {
            for (auto i = sysu.c_all.begin(); i != sysu.c_all.end(); i++) {
                if (i->name == s1) {
                    i->stu_num--;
                    break;
                }
            }
            delete_class(s1);
        }
    } else if (s == "10") {
        list_myclass();
    }
    return 1;
};

void student::shield_conflict() {
    int ret = 1;
    for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
        if (!is_conflict(a->time, myclass)) {
            ret = 0;
        }
    }
    if (ret) {
        cout << "## There is no more class to show." << endl;
    } else {
        cout << "#########################################################################################################" << endl;
        cout << "##  TEACHER        NAME           TIME                PLACE          SCORE     CAPACITY    STU_NUMBER  ##" << endl;
        for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
            if (!is_conflict(a->time, myclass)) {
                cout << "##  " << left << setw(15) << a->teacher_name << setw(15) << a->name
                     << setw(20) << a->time << setw(15) << a->place << setw(10) << a->score
                     << setw(12) << a->max_capacity << setw(12) << a->stu_num << "##" << endl;
            }
        }
        cout << "#########################################################################################################" << endl;
    }
};

void student::shield_full() {
    int ret = 1;
    for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
        if (a->max_capacity != a->stu_num) {
            ret = 0;
        }
    }
    if (ret) {
        cout << "## There is no more class to show." << endl;
    } else {
        cout << "#########################################################################################################" << endl;
        cout << "##  TEACHER        NAME           TIME                PLACE          SCORE     CAPACITY    STU_NUMBER  ##" << endl;
        for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
            if (a->max_capacity != a->stu_num) {
                cout << "##  " << left << setw(15) << a->teacher_name << setw(15) << a->name
                     << setw(20) << a->time << setw(15) << a->place << setw(10) << a->score
                     << setw(12) << a->max_capacity << setw(12) << a->stu_num << "##" << endl;
            }
        }
        cout << "#########################################################################################################" << endl;
    }
};

void student::select_class(string name) {
    for (auto i = sysu.s_all.begin(); i != sysu.s_all.end(); i++) {
        for (auto temp = i->myclass.begin(); temp != i->myclass.end(); temp++) {
            if (name == temp->name) {
                temp->stu_num++;
                break;
            }
        }
    }

    for (auto i = sysu.t_all.begin(); i != sysu.t_all.end(); i++) {
        for (auto temp = i->have_opened.begin(); temp != i->have_opened.end(); temp++) {
            if (name == temp->name) {
                temp->stu_num++;
                break;
            }
        }
    }
};

void student::delete_class(string name) {
    for (auto i = sysu.s_all.begin(); i != sysu.s_all.end(); i++) {
        for (auto temp = i->myclass.begin(); temp != i->myclass.end(); temp++) {
            if (name == temp->name) {
                temp->stu_num--;
                break;
            }
        }
    }

    for (auto i = sysu.t_all.begin(); i != sysu.t_all.end(); i++) {
        for (auto temp = i->have_opened.begin(); temp != i->have_opened.end(); temp++) {
            if (name == temp->name) {
                temp->stu_num--;
                break;
            }
        }
    }
};

void student::list_myclass() {
    if (myclass.size()) {
        cout << "#########################################################################################################" << endl;
        cout << "##  TEACHER        NAME           TIME                PLACE          SCORE     CAPACITY    STU_NUMBER  ##" << endl;
        for (auto a = myclass.begin(); a != myclass.end(); a++) {
            cout << "##  " << left << setw(15) << a->teacher_name << setw(15) << a->name
                 << setw(20) << a->time << setw(15) << a->place << setw(10) << a->score
                 << setw(12) << a->max_capacity << setw(12) << a->stu_num << "##" << endl;
        }
        cout << "#########################################################################################################" << endl;
    } else {
        cout << "## You have not selected any class yet!" << endl;
    }
};