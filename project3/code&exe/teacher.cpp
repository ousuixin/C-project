#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "system.h"
using namespace std;

void teacher::list_myclass() {
    if (have_opened.size() + to_be_review.size()) {
        cout << "#########################################################################################################"
             << "############" << endl;
        cout << "##  TEACHER        NAME           TIME                PLACE          SCORE     CAPACITY    STU_NUMBER   STATU      ##" << endl;
        for (auto a = have_opened.begin(); a != have_opened.end(); a++) {
            cout << "##  " << left << setw(15) << a->teacher_name << setw(15) << a->name
                 << setw(20) << a->time << setw(15) << a->place << setw(10) << a->score
                 << setw(12) << a->max_capacity << setw(13) << a->stu_num << "approved   ##" << endl;
        }
        for (auto a = to_be_review.begin(); a != to_be_review.end(); a++) {
            cout << "##  " << left << setw(15) << a->teacher_name << setw(15) << a->name
                 << setw(20) << a->time << setw(15) << a->place << setw(10) << a->score
                 << setw(12) << a->max_capacity << setw(13) << a->stu_num << "reviewing  ##" << endl;
        }    
        cout << "#########################################################################################################" 
             << "############"<< endl;
    } else {
        cout << "## You have not open any class now." << endl;
    }
};

void teacher::open_class(Class a) {
    for (auto i = sysu.e_all.begin(); i != sysu.e_all.end(); i++) {
        i->to_be_review.push_back(a);
    } 
};

void teacher::delete_class(Class a) {
    for (auto temp = sysu.c_all.begin(); temp != sysu.c_all.end(); temp++) {
        if (a.name == temp->name) {
            sysu.c_all.erase(temp);
            break;
        }
    }

    for (auto i = sysu.s_all.begin(); i != sysu.s_all.end(); i++) {
        for (auto temp = i->myclass.begin(); temp != i->myclass.end(); temp++) {
            if (a.name == temp->name) {
                i->myclass.erase(temp);
                break;
            }
        }
    }

    for (auto i = sysu.e_all.begin(); i != sysu.e_all.end(); i++) {
        for (auto temp = i->to_be_review.begin(); temp != i->to_be_review.end(); temp++) {
            if (a.name == temp->name) {
                i->to_be_review.erase(temp);
                break;
            }
        }
    } 
};


void teacher::print_func () {
    cout << "#####" << "#####" << "####################" << "#####" << "#####" << "####################" << endl;
    cout << "##   " << "     " << "(0).Exit The System                " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(1).Change Password                " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(2).Change Username                " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(3).List All Class                 " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(4).Find Class By Name             " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(5).Find Class By Teacher          " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(6).List My Class                  " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(7).Open Class                     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(8).Delete Class                   " << "     " << "     " << "   ##" << endl; 
    cout << "#####" << "#####" << "####################" << "#####" << "#####" << "####################" << endl;
};

int teacher::select_func() {
    string s = input_check(3);
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
        list_myclass();
    } else if (s == "7") {
        Class a;
        cout << "## Please input the name of the class you want to open:" << endl;
        string s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Operation Failed! Go back to the menu." << endl;
            return 1;
        } 
        a.name = s1;
        a.teacher_name = username;
        for (auto i = have_opened.begin(); i != have_opened.end(); i++) {
            if (s1 == i->name) {
                cout << "## Operation Failed ---- You have opened an same class before!" << endl;
                cout << "## Go back to the menu." << endl;
                return 1;
            }
        }
        for (auto i = to_be_review.begin(); i != to_be_review.end(); i++) {
            if (s1 == i->name) {
                cout << "## Operation Failed ---- You have opened an same class before!" << endl;
                cout << "## Go back to the menu." << endl;
                return 1;
            }
        }
        for (auto i = sysu.c_all.begin(); i != sysu.c_all.end(); i++) {
            if (s1 == i->name) {
                cout << "## Operation Failed ---- There an same class before!" << endl;
                cout << "## Go back to the menu." << endl;
                return 1;
            }
        }
//
        cout << "## Now, you should add more information for the class" << endl;
        cout << "## Please input the time of the class, you can input among Mon~Fir(only weekdays) at first:" << endl;
        s1 = input_check(6);
        if (s1 == "Q") {
            cout << "## Operation Failed! Go back to the menu." << endl;
            return 1;
        }
        string s2 = s1;
        cout << "## There is 12 classes every day, Please tell me you want to take up which classes" << endl;
        cout << "## Please input a number to tell me you want to start from which class:" << endl;
        s1 = input_check(5);
        if (s1 == "Q") {
            cout << "## Operation Failed! Go back to the menu." << endl;
            return 1;
        }
        stringstream ss;    ss << s1;   int num = 0;
        ss >> num;
        cout << "## Please input a number to tell me you want to end with which class:" << endl;
        s1 = input_check(5);
        if (s1 == "Q") {
            cout << "## Operation Failed! Go back to the menu." << endl;
            return 1;
        }
        ss.clear(); ss.str("");    ss << s1;   int num1 = 0;
        ss >> num1;
        if (num1 < num) {
            cout << "## The first class is bigger than the last one, it is wrong! So go back to the menu.";
            return 1;
        }
        ss.clear(); ss.str("");
        ss << s2 << '_' << num << "th" << '~' << num1 << "th";
        ss >> a.time;
        if (is_conflict(a.time, have_opened)||is_conflict(a.time, to_be_review)) {
            cout << "## Operation Failed! ---- The time is conflict. Go back to the menu." << endl;
            return 1;
        }
//
        cout << "## Please tell me where do you want to hold the class:" << endl;
        s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Operation Failed! Go back to the menu." << endl;
            return 1;
        }
        a.place = s1;
//
        cout << "## Please input the score of this cource every term:" << endl;
        s1 = input_check(7);
        if (s1 == "Q") {
            cout << "## Operation Failed! Go back to the menu." << endl;
            return 1;
        }
        ss.clear(); ss.str("");
        ss << s1;
        ss >> num;
        a.score = num;
//
        cout << "## Please input the max_capacity of the class:" << endl;
        s1 = input_check(7);
        if (s1 == "Q") {
            cout << "## Operation Failed! Go back to the menu." << endl;
            return 1;
        }
        ss.clear(); ss.str("");
        ss << s1;
        ss >> num;
        a.max_capacity = num;
        a.stu_num = 0;
        a.statu = "reviewing";
//
        to_be_review.push_back(a);
        open_class(a);
    } else if (s == "8") {
        int ret = 0;
        cout << "## Please input the name of class you want to delete:" << endl;
        string s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Operation Failed! Go back to the menu." << endl;
            return 1;
        } 
        for (auto i = have_opened.begin(); i != have_opened.end(); i++) {
            if (s1 == i->name) {
                delete_class(*i);
                have_opened.erase(i);
                ret = 1;
                cout << "## The class is delete now!" << endl;
                break;
            }
        }
        for (auto i = to_be_review.begin(); i != to_be_review.end(); i++) {
            if (s1 == i->name) {
                delete_class(*i);
                to_be_review.erase(i);
                ret = 1;
                cout << "## The class is delete now!" << endl;
                break;
            }
        }
        if (!ret) {
            cout << "## Operation Failed ---- You have not opened such class before!" << endl;
        }
    }
    return 1;
};

