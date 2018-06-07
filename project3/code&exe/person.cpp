#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "system.h"
using namespace std;

int is_conflict(string time, vector<Class> v) {
    stringstream ss;
    string s[3];    
    int j = 0, f = 0, t = 0;
    for (int i = 0; i < time.length(); ++i) {
        if (time[i] != '_'&&time[i] != '~') {
            ss << time[i];
        } else {
            ss >> s[j];
            ss.clear();ss.str("");
            // cout << s[j] << endl;
            j++;
        }
    }
    ss >> s[2];
    if (s[1].length() == 4) {
        f = (s[1][0] - '0')*10+s[1][1]-'0';
    } else {
        f = s[1][0]-'0';
    }
    if (s[2].length() == 4) {
        t = (s[2][0] - '0')*10+s[2][1]-'0';
    } else {
        t = s[2][0]-'0';
    }
//    cout << s[0] << endl;
//cout << time << endl;
    j = 0;
    string s1[3];
    int f1 = 0, t1 = 0;
    for (auto a = v.begin(); a != v.end(); a++)  {
        ss.clear();ss.str("");
        for (int i = 0; i < a->time.length(); ++i) {
            if (a->time[i] != '_'&&a->time[i] != '~') {
                ss << a->time[i];
            } else {
                ss >> s1[j];
                ss.clear();ss.str("");
                j++;
            }
        }
        ss >> s1[2];
        //cout << s1[1] << ' ' << s1[2] << endl;
        j = 0;
        if (s1[1].length() == 4) {
            f1 = (s1[1][0] - '0')*10+s1[1][1]-'0';
        } else {
            f1 = s1[1][0]-'0';
        }
        if (s1[2].length() == 4) {
            t1 = (s1[2][0] - '0')*10+s1[2][1]-'0';
        } else {
            t1 = s1[2][0]-'0';
        }
        //cout  << s1[0] << endl;
        if (s1[0] != s[0]) {
            continue;
        } else {
            //cout << t << ' ' << f << ' ' << t1 << ' ' << f1 << endl;
            if (t1 < f||t < f1) {
                continue;
            } else {
                return 1;
            }
        }
    }
    return 0;
};

void person::change_password(string s) {
    password = s;
};

void person::change_username(string s) {
    username = s;
};

void person::list_all() {
    int ret = 1;
    for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
        ret = 0;
    }
    if (ret) {
        cout << "## There is no class now." << endl;
    } else {
        cout << "#########################################################################################################" << endl;
        cout << "##  TEACHER        NAME           TIME                PLACE          SCORE     CAPACITY    STU_NUMBER  ##" << endl;
        for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
            cout << "##  " << left << setw(15) << a->teacher_name << setw(15) << a->name
                 << setw(20) << a->time << setw(15) << a->place << setw(10) << a->score
                 << setw(12) << a->max_capacity << setw(12) << a->stu_num << "##" << endl;
        }
        cout << "#########################################################################################################" << endl;
    }
};

void person::find_by_classname(string name) {
    int ret = 1;
    for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
        if (a->name == name) {
            ret = 0;
        }
    }
    if (ret) {
        cout << "## There is no such class!" << endl;
    } else {
        for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
            if (a->name == name) {
                cout << "#########################################################################################################" << endl;
                cout << "##  TEACHER        NAME           TIME                PLACE          SCORE     CAPACITY    STU_NUMBER  ##" << endl;
                cout << "##  " << left << setw(15) << a->teacher_name << setw(15) << a->name
                     << setw(20) << a->time << setw(15) << a->place << setw(10) << a->score
                     << setw(12) << a->max_capacity << setw(12) << a->stu_num << "##" << endl;
                cout << "#########################################################################################################" << endl;
                ret = 0;
            }
        }
    }
};

void person::find_by_tchname(string name) {
    int ret = 1;
    for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
        if (a->teacher_name == name) {
            ret = 0;
        }
    }
    if (ret) {
        cout << "The Teacher has no book!" << endl;
    } else {
        cout << "#########################################################################################################" << endl;
        cout << "##  TEACHER        NAME           TIME                PLACE          SCORE     CAPACITY    STU_NUMBER  ##" << endl;
        for (auto a = sysu.c_all.begin(); a != sysu.c_all.end(); a++) {
            if (a->teacher_name == name) {
                cout << "##  " << left << setw(15) << a->teacher_name << setw(15) << a->name
                     << setw(20) << a->time << setw(15) << a->place << setw(10) << a->score
                     << setw(12) << a->max_capacity << setw(12) << a->stu_num << "##" << endl;
            }
        }
        cout << "#########################################################################################################" << endl;
    }
};


//--------------------------------------------------------------------------------------------------------------------
string input_check(const int num) {
    while (1) {
        //input
        cout << "$$ ";
        stringstream ss;
        string s;
        getline(cin, s);
        ss << s;
        if (ss.str() == "") {
            continue;
        } else if (ss.str() == "Q") {
            return s;
        }
        //check the input acccording to the case
        if (num == 1) {
            ss >> s;
            if (!(s[0] >= '0'&&s[0] <= '2'&&s.size()==1) || ss >> s) {
                cout << "## Your input is error, please only input a right number from 0 to 2!" << endl;
            } else {
                return s;
            }
//(1)when num == 1, we check whether the num between 0-2 is right
        } else if (num == 2) {
            int number = 0;
            if (ss >> number) {
                if (ss >> s || number < 0 || number > 10) {
                    cout << "~~ Your input is error, please only input a right number between 0~10!"
                         << endl;
                } else {
                    ss.clear(); ss.str("");
                    ss << number;
                    ss >> s;
                    return s;
                }
            } else {
                cout << "~~ Your input is error, please input a number!" << endl;
            }
//(2)when num == 3, we check whether the 10>=num>=0 is right
        } else if (num == 3) {
            ss >> s;
            if (!(s[0] >= '0'&&s[0] <= '8'&&s.size()==1) || ss >> s) {
                cout << "## Your input is error, please only input a right number from 0 to 8!" << endl;
            } else {
                return s;
            }
//(1)when num == 3, we check whether the num between 0-8 is right
        } else if (num == 4) {
            string name;
            ss >> name;
            if (ss >> s) {
                cout << "## Your input is error, Please enter only one element in a line!" << endl;
            } else {
                int ret = 0;
                for (int i = 0; i < name.size(); ++i) {  
                    if (i == 1&&name.size() >= 15) {
                        cout << "## Your input is error, the element'letter should be no more than 15!" << endl;
                        ret = 1;
                        break;
                    }
                    if (!((name[i] <= 'z'&&name[i] >= 'a')||(name[i] <= 'Z'&&name[i] >= 'A')||(name[i] <= '9'&&name[i] >= '0'))) {
                        cout << "## Your input is error, a element should only have letter or number." << endl;
                        ret = 1;
                        break;
                    }
                }
                if (!ret) {
                    return name;
                }
            }
        } else if (num == 5) {
            int number = 0;
            if (ss >> number) {
                if (ss >> s || number < 0 || number > MAX) {
                    cout << "~~ Your input is error, please only input a right number between 0~" << MAX <<"!"
                         << endl;
                } else {
                    ss.clear(); ss.str("");
                    ss << number;
                    ss >> s;
                    return s;
                }
            } else {
                cout << "~~ Your input is error, please input a number!" << endl;
            }
//(2)when num == 5, we check whether the MAX>=num>=0 is right
        } else if (num == 6) {
            string name;
            ss >> name;
            if (ss >> s) {
                cout << "## Your input is error, Please enter only one element in a line!" << endl;
            } else {
                int ret = 0;
                for (int i = 0; i < name.size(); ++i) {  
                    if (i == 1&&name.size() >= 15) {
                        cout << "## Your input is error, the element'letter should be no more than 15!" << endl;
                        cout << "## Please input a new one:" << endl;
                        ret = 1;
                        break;
                    }
                    if (!((name[i] <= 'z'&&name[i] >= 'a')||(name[i] <= 'Z'&&name[i] >= 'A')||(name[i] <= '9'&&name[i] >= '1'))) {
                        cout << "## Your input is error, a element should only have letter or number." << endl;
                        cout << "## Please input a new one:" << endl;
                        ret = 1;
                        break;
                    }
                    if (name!="Monday"&&name!="Tuesday"&&name!="Wednesday"&&name!="Thursday"&&name!="Friday") {
                        cout << "## You should only input Monday,Tuesday,Wednesday,Thursday or Friday!" << endl;
                        cout << "## Please input a new one:" << endl;
                        ret = 1;
                        break;
                    }
                }
                if (!ret) {
                    return name;
                }
            }
        
        } else if (num == 7) {
            int number = 0;
            if (ss >> number) {
                if (ss >> s || number < 0) {
                    cout << "~~ Your input is error, please only input a right number >= 0!"
                         << endl;
                } else {
                    ss.clear(); ss.str("");
                    ss << number;
                    ss >> s;
                    return s;
                }
            } else {
                cout << "~~ Your input is error, please input a number!" << endl;
            }
//(2)when num == 2, we check whether the num>=0 is right
        }
    } 
}