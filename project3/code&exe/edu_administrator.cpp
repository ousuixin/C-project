#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "system.h"
using namespace std;

void edu_administrator::show_need_review() {
    if (to_be_review.size()) {
        cout << "#########################################################################################################" << endl;
        cout << "##  TEACHER        NAME           TIME                PLACE          SCORE     CAPACITY    STU_NUMBER  ##" << endl;
        for (auto a = to_be_review.begin(); a != to_be_review.end(); a++) {
            cout << "##  " << left << setw(15) << a->teacher_name << setw(15) << a->name
                 << setw(20) << a->time << setw(15) << a->place << setw(10) << a->score
                 << setw(12) << a->max_capacity << setw(12) << a->stu_num << "##" << endl;
        }
        cout << "#########################################################################################################" << endl;
    } else {
        cout << "## There is no class to be approved." << endl;
    }
};

void edu_administrator::approve_class(Class a) {
    for (auto temp = sysu.t_all.begin(); temp != sysu.t_all.end(); ++temp) {
        if (a.teacher_name == temp->username) {
            for (auto i = temp->to_be_review.begin(); i != temp->to_be_review.end(); i++) {
                if (a.name == i->name) {
                    temp->have_opened.push_back(a);
                    temp->to_be_review.erase(i);
                    break;
                }
            }
            break;
        }
    }

    for (auto temp = sysu.e_all.begin(); temp != sysu.e_all.end(); ++temp) {
        for (auto i = temp->to_be_review.begin(); i != temp->to_be_review.end(); ++i) {
            if (i->name == a.name) {
                temp->to_be_review.erase(i);
                break;
            }
        }
    }
};

void edu_administrator::disapprove_class(Class a) {
    for (auto temp = sysu.t_all.begin(); temp != sysu.t_all.end(); ++temp) {
        if (a.teacher_name == temp->username) {
            for (auto i = temp->have_opened.begin(); i != temp->have_opened.end(); i++) {
                if (a.name == i->name) {
                    temp->to_be_review.push_back(a);
                    temp->have_opened.erase(i);
                    break;
                }
            }
            break;
        }
    }

    for (auto temp = sysu.s_all.begin(); temp != sysu.s_all.end(); ++temp) {
        for (auto i = temp->myclass.begin(); i != temp->myclass.end(); ++i) {
            if (i->name == a.name) {
                temp->myclass.erase(i);
                break;
            }
        }
    }

    for (auto temp = sysu.e_all.begin(); temp != sysu.e_all.end(); ++temp) {
        temp->to_be_review.push_back(a);
    }
};

void edu_administrator::print_func () {
    cout << "#####" << "#####" << "####################" << "#####" << "#####" << "####################" << endl;
    cout << "##   " << "     " << "(0).Exit The System                " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(1).Change Password                " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(2).Change Username                " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(3).List All Class                 " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(4).Find Class By Name             " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(5).Find Class By Teacher          " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(6).Show Class Pending Approval    " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(7).Approve Class To Open          " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(8).Disapprove Class To Open       " << "     " << "     " << "   ##" << endl; 
    cout << "#####" << "#####" << "####################" << "#####" << "#####" << "####################" << endl;
};

int edu_administrator::select_func() {
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
        cout << "## The clases need reviewing is as follows:" << endl;
        show_need_review();
    } else if (s == "7") {
        int ret = 0;
        cout << "## Please input the name of the class you want to approve:" << endl;
        string s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Go back to the menu." << endl;
            return 1;
        } 
        for (auto a = to_be_review.begin(); a != to_be_review.end(); a++) {
            if (a->name == s1) {
                ret = 1;
                a->statu = "approved";
                sysu.c_all.push_back(*a);
                approve_class(*a);
                cout << "## The class is open to all student now!" << endl;
                break;
            }
        }
        if (!ret) {
            cout << "## Operation Failed ---- There is no such class to be approved!" << endl;
        }
    } else if (s == "8") {
        int ret = 0;
        cout << "## Please input the name of the class you disapprove to open:" << endl;
        string s1 = input_check(4);
        if (s1 == "Q") {
            cout << "## Go back to the menu." << endl;
            return 1;
        } 
        for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
            if (a->name == s1) {
                a->statu = "reviewing";
                a->stu_num = 0;
                disapprove_class(*a);
                sysu.c_all.erase(a);
                cout << "## The class is closed for all student now!" << endl;
                ret = 1;
                break;
            }
        }
        if (!ret) {
            cout << "## Operation Failed ---- There is no such class open before!" << endl;
        }
    }
    return 1;
};

